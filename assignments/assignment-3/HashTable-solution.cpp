// HashTable.cpp
#include "HashTable.h"
#include <cmath>

// --- Constructor ---
HashTable::HashTable(CollisionStrategy strategy, int initialSize)
    : strategy(strategy), tableSize(initialSize), currentSize(0)
{
    if(strategy == SEPARATE_CHAINING) { this->buckets.resize(this->tableSize); }
    else {
        this->table.resize(this->tableSize, HashEntry("", 0, EMPTY));
    }
}

// --- Helpers ---
bool HashTable::isPrime(int n)
{
    /* O(sqrt(n)), and is optimized for small values */
    if(n <= 1) { return false; }
    if(n == 2 || n == 3) { return true; }
    if(n % 2 == 0 || n % 3 == 0) { return false; }

    /* check from 5 to sqrt(n), iterate by i+6 for efficiency */
    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0) { return false; }
    }
    return true;
}

int HashTable::getNextPrime(int n)
{
    /* O(n * sqrt(n)) */
    
    /* added for optimization */
    switch(n) {
    case 0:
        return 2;
    case 1:
        return 2;
    case 2:
        return 2;
    case 3:
        return 3;
    }
    int next_prime = n;
    if(next_prime % 2 == 0) { next_prime++; }
    for(;;) {
        if(this->isPrime(next_prime)) { return next_prime; }
        next_prime += 2;
    }
}

int HashTable::performHash(std::string key)
{
    unsigned int hashVal = 0;
    unsigned int pPow = 1;
    for(size_t i = 0; i < key.length(); i++) {
        hashVal += (unsigned char)key[i] * pPow;
        pPow *= 33;
    }
    return (hashVal % this->tableSize);
}

int HashTable::performHash2(std::string key)
{
    int p = this->tableSize - 1;
    while(p > 2 && !this->isPrime(p)) { p--; }

    unsigned int rawHash = 0;
    unsigned int pPow = 1;
    for(size_t i = 0; i < key.length(); i++) {
        rawHash += (unsigned char)key[i] * pPow;
        pPow *= 33;
    }
    return ((p - (rawHash % p)) % this->tableSize);
}

// --- Operations ---
void HashTable::insert(std::string key, int value)
{
    if((double)(this->currentSize + 1) / this->tableSize > 0.5) {
        this->resizeTable();
    }
    int h1 = this->performHash(key);

    if(this->strategy == SEPARATE_CHAINING) {
        std::vector<HashEntry>& bucket = this->buckets[h1];
        for(size_t i = 0; i < bucket.size(); i++) {
            if(bucket[i].key == key) {
                bucket[i].value = value;
                return;
            }
        }

        bucket.push_back(HashEntry(key, value, OCCUPIED));
        this->currentSize++;
    }
    else {
        int h2 = (this->strategy == DOUBLE) ? this->performHash2(key) : 0;
        for(int i = 0; i < this->tableSize; i++) {
            int idx;
            if(this->strategy == LINEAR) { idx = (h1 + i) % this->tableSize; }
            else if(this->strategy == QUADRATIC) {
                idx = (h1 + i * i) % this->tableSize;
            }
            else {
                idx = (h1 + i * h2) % this->tableSize;
            }

            if(this->table[idx].status != OCCUPIED) {
                this->table[idx] = HashEntry(key, value, OCCUPIED);
                this->currentSize++;
                return;
            }
            else if(this->table[idx].key == key) {
                this->table[idx].value = value;
                return;
            }
        }
    }
}

bool HashTable::search(std::string key, int& outValue)
{
    int h1 = performHash(key);

    if(this->strategy == SEPARATE_CHAINING) {
        const std::vector<HashEntry>& bucket = this->buckets[h1];
        for(size_t i = 0; i < bucket.size(); i++) {
            if(bucket[i].key == key) {
                outValue = bucket[i].value;
                return true;
            }
        }
    }
    else {
        int h2 = (this->strategy == DOUBLE) ? this->performHash2(key) : 0;

        for(int i = 0; i < this->tableSize; i++) {
            int idx;
            if(this->strategy == LINEAR) { idx = (h1 + i) % this->tableSize; }
            else if(this->strategy == QUADRATIC) {
                idx = (h1 + i * i) % this->tableSize;
            }
            else {
                idx = (h1 + i * h2) % this->tableSize;
            }

            if(this->table[idx].status == EMPTY) { return false; }
            if(this->table[idx].status == OCCUPIED
               && this->table[idx].key == key) {
                outValue = this->table[idx].value;
                return true;
            }
        }
    }
    return false;
}

void HashTable::remove(std::string key)
{
    int h1 = performHash(key);

    if(this->strategy == SEPARATE_CHAINING) {
        for(size_t i = 0; i < this->buckets[h1].size(); i++) {
            if(this->buckets[h1][i].key == key) {
                this->buckets[h1].erase(this->buckets[h1].begin() + i);
                this->currentSize--;
                return;
            }
        }
    }
    else {
        int h2 = (this->strategy == DOUBLE) ? this->performHash2(key) : 0;
        for(int i = 0; i < this->tableSize; i++) {
            int idx;
            if(this->strategy == LINEAR) { idx = (h1 + i) % this->tableSize; }
            else if(this->strategy == QUADRATIC) {
                idx = (h1 + i * i) % this->tableSize;
            }
            else {
                idx = (h1 + i * h2) % this->tableSize;
            }

            if(this->table[idx].status == EMPTY) { return; }
            if(this->table[idx].status == OCCUPIED
               && this->table[idx].key == key) {
                this->table[idx].status = DELETED; // Lazy deletion
                this->currentSize--;
                return;
            }
        }
    }
}

void HashTable::resizeTable()
{
    int oldSize = this->tableSize;
    // New size is the first prime >= 2 * oldSize
    this->tableSize = getNextPrime(2 * oldSize);
    this->currentSize = 0;

    if(this->strategy == SEPARATE_CHAINING) {
        std::vector<std::vector<HashEntry>> oldBuckets = this->buckets;
        this->buckets.clear();
        this->buckets.resize(this->tableSize);

        for(int i = 0; i < oldSize; i++) {
            for(size_t j = 0; j < oldBuckets[i].size(); j++) {
                this->insert(oldBuckets[i][j].key, oldBuckets[i][j].value);
            }
        }
    }
    else {
        std::vector<HashEntry> oldTable = this->table;
        this->table.clear();
        this->table.resize(this->tableSize, HashEntry("", 0, EMPTY));

        for(int i = 0; i < oldSize; i++) {
            if(oldTable[i].status == OCCUPIED) {
                this->insert(oldTable[i].key, oldTable[i].value);
            }
        }
    }
}

void HashTable::printTable()
{
    std::cout << "Size: " << tableSize << std::endl;

    if(strategy == SEPARATE_CHAINING) {
        for(int i = 0; i < tableSize; i++) {
            if(!buckets[i].empty()) {
                std::cout << i << ": ";
                for(const auto& entry: buckets[i]) {
                    std::cout << "[" << entry.key << ":" << entry.value
                              << "] -> ";
                }
                std::cout << "NULL" << std::endl;
            }
        }
    }
    else {
        // Open Addressing Print
        for(int i = 0; i < tableSize; i++) {
            if(table[i].status == OCCUPIED)
                std::cout << i << ": " << table[i].key << " (" << table[i].value
                          << ")" << std::endl;
            else if(table[i].status == DELETED)
                std::cout << i << ": DELETED" << std::endl;
        }
    }
}
