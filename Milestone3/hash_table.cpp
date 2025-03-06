/**
*
* hash_table.cpp  : This This is the implementation file for hash_table.h with methods for managing a basic hash table.
*
*  03/06/2025 - Created by Zoe Elias.
* 03/06/2025 - Modified by Zoe Elias; created stubs for compilation and running code.
* 03/06/2025 - Modified by Zoe Elias; added #include <iostream> for std::cout
*                       Note for Kirill Koukarine: You can remove this line if you'd like, I just added it so the file would compile.
*/


//TODO: This file contains stub implementations. Functions need to be properly implemented.
//NOTE for Kirill Koukarine: You can implement the functions and modify this code however you like!

#include <iostream> // 03/06/25 - Added by Zoe Elias for std::cout (Kirill, remove if unnecessary)
#include "hash_table.h"

HashNode** HashTable::getTable() { return nullptr; }
int HashTable::getSize() { return 0; }
int HashTable::calculateHashCode(int) { return 0; }
bool HashTable::isEmpty() { return true; }
int HashTable::getNumberOfItems() { return 0; }
bool HashTable::add(int, HashNode*) { return false; }
bool HashTable::remove(int) { return false; }
void HashTable::clear() {}
HashNode* HashTable::getItem(int) { return nullptr; }
bool HashTable::contains(int) { return false; }
void HashTable::printTable() {}
