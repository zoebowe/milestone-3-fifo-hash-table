/**
 * @author - Zoe Elias
 * @file cache_manager.cpp - This file implements the methods declared in cache_manager.h.
 * 03/14/2025 - Z. Elias created the file and implemented the following methods:
 *              - getTable()
 *              - getList()
 *              - getSize()
 *              - isEmpty()
 *              - add()
 *              - remove()
 * 
 * NOTE: The following methods will be implemented by Kirill Koukarine in the feature/kirill branch:
 *       - clear()
 *       - getItem()
 *       - getMaxCacheSize()
 *       - contains()
 *       - printCache()
 * 
 * These will be merged into the main branch once both implementations are complete.
 */

#include "cache_manager.h"
#include <iostream>

HashTable* CacheManager::getTable() { 
    return hashTable; 
}

DoublyLinkedList* CacheManager::getList() { 
    return doublyLinkedList; 
}

int CacheManager::getSize() { 
    int size = hashTable->getNumberOfItems();
    return size;
}

bool CacheManager::isEmpty() { 
    return hashTable->getNumberOfItems() == 0; 
}

bool CacheManager::add(int curKey, DllNode* myNode) {
    if (hashTable->getNumberOfItems() >= maxCacheSize) {
        std::cout << "Cache is full! Cannot add key: " << curKey << std::endl;
        return false; // Cache is full
    }

    if (hashTable->contains(curKey)) {
        std::cout << "Key " << curKey << " already exists in the cache." << std::endl;
        return false; // Prevent duplicate entries
    }

    // Insert into HashTable
    HashNode* newHashNode = new HashNode(curKey, myNode); // Wrap DllNode inside HashNode
    hashTable->add(curKey, newHashNode);

    // Check size before inserting into the doubly linked list
    int beforeSize = doublyLinkedList->getSize();

    // Insert into Doubly Linked List (FIFO order)
    doublyLinkedList->insertAtHead(curKey, myNode);

    // Check size after insertion
    int afterSize = doublyLinkedList->getSize();

    // Confirm insertion success
    if (afterSize > beforeSize) {
        std::cout << "Added key to cacheManager: " << curKey << std::endl;
        return true;
    } else {
        std::cout << "Failed to add key to cacheManager: " << curKey << std::endl;
        return false;
    }
}

bool CacheManager::remove(int curKey) {
    if (!hashTable->contains(curKey)) {
        std::cout << "Key " << curKey << " not found in cache." << std::endl;
        return false; // Key not found
    }

    // Remove from HashTable
    hashTable->remove(curKey);

    // Remove from Doubly Linked List
    doublyLinkedList->remove(curKey);

    std::cout << "Removed key: " << curKey << " from cacheManager" << std::endl;
    return true;
}

void CacheManager::clear() { 
    // TODO: Implement cache clearing logic
    // Kirill Koukarine will implement this in feature/kirill branch
}

DllNode* CacheManager::getItem(int curKey) { 
    // TODO: Implement retrieval logic
    // Kirill Koukarine will implement this in feature/kirill branch
    return nullptr; 
}

int CacheManager::getMaxCacheSize() { 
    // TODO: Return max cache size
    // Kirill Koukarine will implement this in feature/kirill branch
    return 0; 
}

bool CacheManager::contains(int curKey) { 
    // TODO: Implement search logic
    // Kirill Koukarine will implement this in feature/kirill branch
    return false; 
}

void CacheManager::printCache() { 
    // TODO: Implement cache printing
    // Kirill Koukarine will implement this in feature/kirill branch
}
