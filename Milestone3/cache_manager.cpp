/**
*
* cache_manager.cpp : This implementation file contains the methods declared in the cache_manager.h file.
*
* 3/5/25 - Created by Kirill
*/


#include "cache_manager.h"

// remove all entries from the CacheManager
cache_manager::clear(int myKeyValue, DllNode* myFifoNode) {
	clear(myFifoNode.next.key, myFifoNode.next);
	remove(myKeyValue);
}

//retrieve item from the CacheManager, and moves node to the head of doublyLinkedList
cache_manager::getItem(int curKey) {
	doublyLinkedList->moveNodeToHead(curKey);
	return getItem(curKey);
}

// retrieve max size of cache from the CacheManager
cache_manager::getMaxCacheSize(){
	return maxCacheSize;
}

//check if a node with key exists in the table, and moves node to the head of doublyLinkedList, if true
cache_manager::contains(int curKey){
	if(hashTable->contains(curKey)){
		doublyLinkedList->moveNodeToHead(curkey);
		return true;
	}
	else return false;
}

//print out the cache information
cache_manager::printCache(){
	hashTable->printTable();
	doublyLinkedList->printList();
}