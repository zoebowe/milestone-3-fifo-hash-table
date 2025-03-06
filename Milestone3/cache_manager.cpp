/**
*
*  cache_manager.cpp : This is the implementation file for cache_manager.h, using a FIFO list and hash table for caching.
*
*  03/06/2025 - Created by Zoe Elias.
* 03/06/2025 - Modified by Zoe Elias; created stubs for compilation and running code.
*/


//TODO: This file contains stub implementations. Functions need to be properly implemented.
//NOTE for Kirill Koukarine: You can implement the functions and modify this code however you like!

#include "cache_manager.h"

HashTable* CacheManager::getTable() { return nullptr; }
DoublyLinkedList* CacheManager::getList() { return nullptr; }
bool CacheManager::isEmpty() { return true; }
int CacheManager::getSize() { return 0; }
bool CacheManager::add(int, DllNode*) { return false; }
bool CacheManager::remove(int) { return false; }
void CacheManager::clear() {}
DllNode* CacheManager::getItem(int) { return nullptr; }
int CacheManager::getMaxCacheSize() { return 0; }
bool CacheManager::contains(int) { return false; }
void CacheManager::printCache() {}
