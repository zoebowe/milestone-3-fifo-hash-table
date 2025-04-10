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
 * 03/15/2025 - Kirill Koukarine implemented the following methods:
 *              - clear()
 *              - getItem()
 *              - getMaxCacheSize()
 *              - contains()
 *              - printCache()
 * 04/09/25 - Edited by Zoë Elias: changed clear() to iterate with while loop instead of do-while loop.
 */

#include "cache_manager.h"
#include <iostream>

// Returns a pointer to the hash table used for cache storage.
HashTable* CacheManager::getTable() { 
    return hashTable; 
}

// Returns a pointer to the doubly linked list used for FIFO cache management.
DoublyLinkedList* CacheManager::getList() { 
    return doublyLinkedList; 
}

// Retrieves the current number of items in the cache.
int CacheManager::getSize() { 
    int size = hashTable->getNumberOfItems();
    return size;
}

// Checks if the cache is empty.
bool CacheManager::isEmpty() { 
    return hashTable->getNumberOfItems() == 0; 
}

// Adds a new key-value pair to the cache, evicting the oldest entry if necessary.
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

// Removes a key-value pair from the cache if it exists.
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
    /// Zoë Elias: Changed this method from a do-while loop, which cause a null pointer ///
    /// dereference after removing a node, creating potential segmentation faults. ///
	//DllNode* currentNode = doublyLinkedList->head;
	//DllNode* nextNode = currentNode->next;
	//do {
		//remove(currentNode->key);
		//currentNode = nextNode;
		//nextNode = currentNode->next;
	//} while (nextNode);
	//if (currentNode) {
		//remove(currentNode->key);
	//}
    /// Changed to a while loop ensuring that each node is properly processed and removed ///
    /// until the end of the list is reached. ///
    DllNode* currentNode = doublyLinkedList->head;
    while (currentNode) {
        DllNode* nextNode = currentNode->next;
        remove(currentNode->key);
        currentNode = nextNode;
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
