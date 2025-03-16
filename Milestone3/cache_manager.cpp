/**
*
* cache_manager.cpp : This implementation file contains the methods declared in the cache_manager.h file.
*
* 3/5/25 - Created by Kirill
*/


#include "cache_manager.h"

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

//print out the cache information using old print statements
void CacheManager::printCache(){
	hashTable->printTable();
	doublyLinkedList->printList();
}