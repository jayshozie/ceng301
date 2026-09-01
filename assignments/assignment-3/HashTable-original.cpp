#include "HashTable.h"
#include <cmath>

// --- Constructor ---
HashTable::HashTable(CollisionStrategy strategy, int initialSize) {
    // YOUR CODE HERE
}

// --- Helpers ---
bool HashTable::isPrime(int n) {
    // YOUR CODE HERE
}

int HashTable::getNextPrime(int n) {
    // YOUR CODE HERE
}

int HashTable::performHash(std::string key) {
    // YOUR CODE HERE
}

int HashTable::performHash2(std::string key) {
    // YOUR CODE HERE
}

// --- Operations ---
void HashTable::insert(std::string key, int value) {
    // YOUR CODE HERE
}

bool HashTable::search(std::string key, int& outValue) {
    // YOUR CODE HERE
}

void HashTable::remove(std::string key) {
    // YOUR CODE HERE
}

void HashTable::resizeTable() {
    // YOUR CODE HERE
}

void HashTable::printTable() {
    std::cout << "Size: " << tableSize << std::endl;
    
    if (strategy == SEPARATE_CHAINING) {
        for (int i = 0; i < tableSize; i++) {
            if (!buckets[i].empty()) {
                std::cout << i << ": ";
                for (const auto& entry : buckets[i]) {
                    std::cout << "[" << entry.key << ":" << entry.value << "] -> ";
                }
                std::cout << "NULL" << std::endl;
            }
        }
    } else {
        // Open Addressing Print
        for (int i = 0; i < tableSize; i++) {
            if (table[i].status == OCCUPIED)
                std::cout << i << ": " << table[i].key << " (" << table[i].value << ")" << std::endl;
            else if (table[i].status == DELETED)
                std::cout << i << ": DELETED" << std::endl;
        }
    }
}
