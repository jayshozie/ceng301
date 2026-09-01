#include "HashTable.h"

// --- TASK 1 ---
int HashTable::performHash(std::string key)
{
    int hash = 0;
    int p = 1;
    for(int i = 0; i < key.length(); i++) {
        hash += (key[i] * p) % this->tableSize;
        p *= 33;
    }
    return hash % this->tableSize;
}
