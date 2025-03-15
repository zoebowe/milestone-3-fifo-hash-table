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
    // Handle Cache Full Condition (FIFO Eviction)
    if (hashTable->getNumberOfItems() >= maxCacheSize) {  
        if (doublyLinkedList->tail) {  
            int oldestKey = doublyLinkedList->tail->key;

            // Remove from both hash table and doubly linked list
            hashTable->remove(oldestKey);
            doublyLinkedList->remove(oldestKey);
        }
    }

    // Prevent duplicate entries
    if (hashTable->contains(curKey)) {
        return false;
    }

    // Insert into HashTable
    HashNode* newHashNode = new HashNode(curKey, myNode);
    hashTable->add(curKey, newHashNode);

    // Insert into Doubly Linked List (FIFO order)
    doublyLinkedList->insertAtHead(curKey, myNode);

    return true;
}

bool CacheManager::remove(int curKey) {
    if (!hashTable->contains(curKey)) {
        return false; // Key not found
    }

    // Remove from HashTable and Doubly Linked List
    hashTable->remove(curKey);
    doublyLinkedList->remove(curKey);

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
