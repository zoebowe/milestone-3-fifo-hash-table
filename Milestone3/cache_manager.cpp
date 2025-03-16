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

// remove all entries from the CacheManager
void CacheManager::clear() {
	DllNode* currentNode = doublyLinkedList->head;
	DllNode* nextNode = currentNode->next;
	do {
		remove(currentNode->key);
		currentNode = nextNode;
		nextNode = currentNode->next;
	} while (nextNode);
	if (currentNode) {
		remove(currentNode->key);
	}
}

//retrieve item from the CacheManager, and moves node to the head of doublyLinkedList
DllNode* CacheManager::getItem(int curKey) {
	doublyLinkedList->moveNodeToHead(curKey);
	return getItem(curKey);
}

// retrieve max size of cache from the CacheManager
int CacheManager::getMaxCacheSize(){
	return maxCacheSize;
}

//check if a node with key exists in the table, and moves node to the head of doublyLinkedList, if true
bool CacheManager::contains(int curKey){
	if(hashTable->contains(curKey)){
		doublyLinkedList->moveNodeToHead(curKey);
		return true;
	}
	else return false;
}

//print out the cache information
void CacheManager::printCache(){
	hashTable->printTable();
	doublyLinkedList->printList();
}