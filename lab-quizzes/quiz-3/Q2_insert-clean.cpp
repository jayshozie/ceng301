#include "HashTable.h"

// --- TASK 2 ---
void HashTable::insert(std::string key, int value)
{
    int hashed = this->performHash(key);
    if(this->table[hashed].status == OCCUPIED) {
        hashed++;
        while(this->table[hashed].status == OCCUPIED) {
            hashed++;
            hashed = hashed % this->tableSize;
        }
    }  
    /* we have the correct index */
    this->table[hashed].value = value;
    this->table[hashed].key = key;
    this->table[hashed].status = OCCUPIED;
}
