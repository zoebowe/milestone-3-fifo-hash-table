/**
 * @author - Zoe Elias
 * @file hash_table.cpp - This file implements the methods declared in hash_table.h.
 * 03/14/2025 - Z. Elias created the file and added initial comments.
 *
 * NOTE: The following methods will be implemented by Kirill Koukarine in the feature/kirill branch:
 *       - getTable()
 *       - getSize()
 *       - calculateHashCode()
 *       - isEmpty()
 *       - getNumberOfItems()
 *       - add()
 *       - remove()
 *       - clear()
 *       - getItem()
 *       - contains()
 *       - printTable()
 */

#include "hash_table.h"
#include <iostream>

HashNode** HashTable::getTable() { 
    // TODO: Implement method to return the actual hash table structure
    // Kirill Koukarine will implement this in feature/kirill branch
    return nullptr; 
}

int HashTable::getSize() { 
    // TODO: Implement method to return the number of buckets in the table
    // Kirill Koukarine will implement this in feature/kirill branch
    return 0; 
}

int HashTable::calculateHashCode(int currentKey) { 
    // TODO: Implement hash function to determine the bucket index for a given key
    // Kirill Koukarine will implement this in feature/kirill branch
    return 0; 
}

bool HashTable::isEmpty() { 
    // TODO: Implement method to check if the hash table is empty
    // Kirill Koukarine will implement this in feature/kirill branch
    return true; 
}

int HashTable::getNumberOfItems() { 
    // TODO: Implement method to return the number of stored elements
    // Kirill Koukarine will implement this in feature/kirill branch
    return 0; 
}

bool HashTable::add(int curKey, HashNode* myNode) { 
    // TODO: Implement method to add a key-value pair to the hash table
    // Kirill Koukarine will implement this in feature/kirill branch
    return true; 
}

bool HashTable::remove(int curKey) { 
    // TODO: Implement method to remove a key-value pair from the hash table
    // Kirill Koukarine will implement this in feature/kirill branch
    return true; 
}

void HashTable::clear() { 
    // TODO: Implement method to clear all entries in the hash table
    // Kirill Koukarine will implement this in feature/kirill branch
}

HashNode* HashTable::getItem(int curKey) { 
    // TODO: Implement method to retrieve an item from the hash table
    // Kirill Koukarine will implement this in feature/kirill branch
    return nullptr; 
}

bool HashTable::contains(int curKey) { 
    // TODO: Implement method to check if a key exists in the hash table
    // Kirill Koukarine will implement this in feature/kirill branch
    return false; 
}

void HashTable::printTable() { 
    // TODO: Implement method to print the contents of the hash table
    // Kirill Koukarine will implement this in feature/kirill branch
}
