/**
 * @author - Zoe Elias
 * @file cache_manager.cpp - This file implements the methods declared in cache_manager.h.
 * 03/14/2025 - Z. Elias created the file and added initial comments.
 *
 */

#include "cache_manager.h"
#include <iostream>

CacheManager::CacheManager(int myMaxCacheSize, int myHashTableSize) {}

HashTable* CacheManager::getTable() { return nullptr; }

DoublyLinkedList* CacheManager::getList() { return nullptr; }

int CacheManager::getSize() { return 0; }

bool CacheManager::isEmpty() { return true; }

bool CacheManager::add(int curKey, DllNode* myNode) { return true; }

bool CacheManager::remove(int curKey) { return true; }

void CacheManager::clear() {}

DllNode* CacheManager::getItem(int curKey) { return nullptr; }

int CacheManager::getMaxCacheSize() { return 0; }

bool CacheManager::contains(int curKey) { return false; }

void CacheManager::printCache() {}
