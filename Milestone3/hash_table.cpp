#include "hash_table.h"
#include <iostream>

HashTable::HashTable() {}

HashTable::HashTable(int hashTableSize) {}

HashNode** HashTable::getTable() { return nullptr; }

int HashTable::getSize() { return 0; }

int HashTable::calculateHashCode(int currentKey) { return 0; }

bool HashTable::isEmpty() { return true; }

int HashTable::getNumberOfItems() { return 0; }

bool HashTable::add(int curKey, HashNode* myNode) { return true; }

bool HashTable::remove(int curKey) { return true; }

void HashTable::clear() {}

HashNode* HashTable::getItem(int curKey) { return nullptr; }

bool HashTable::contains(int curKey) { return false; }

void HashTable::printTable() {}
