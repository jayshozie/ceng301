#include "HashTable.h"

// --- TASK 3 ---
void HashTable::resizeTable()
{
    int old_size = this->tableSize;
    int new_size = this->getNextPrime(old_size * 2);
    HashTable* new_table = new HashTable(new_size);
    /* insert old entires */
    for(int i = 0; i < old_size; i++) {
        if(this->table[i].status == DELETED
           || this->table[i].status == EMPTY) {
            continue;
        }
        std::string curr_key = this->table[i].key;
        int curr_value = this->table[i].value;
        new_table->insert(curr_key, curr_value);
    }
    *this = *new_table;
}
