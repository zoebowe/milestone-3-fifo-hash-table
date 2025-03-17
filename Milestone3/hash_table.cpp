/**
*
* hash_table.cpp : This is the cpp file for HashTable which defines hash_table.h functions
*
* 3/16/25 created by Kirill
*/


#include "hash_node.h"
#include "hash_table.h"
#include <iostream>
#include <sstream>

	/**
	*
	* getTable
	*
	* Method to return the hash table
	*/
	HashNode** HashTable::getTable(){
		return table;
    }

	/**
	*
	* getSize
	*
	* Method to return the size of the hash table
	*/
	int HashTable::getSize() {
		return numberOfBuckets;
	}

	/**
	*
	* calculateHashCode
	*
	* Method to calculate the hashCode
	*/
	int HashTable::calculateHashCode(int currentKey) {
		return currentKey % getSize();
	}

	/**
	*
	* isEmpty
	*
	* Method to check if HashTable is empty
	*/
	bool HashTable::isEmpty() {
		int size = getSize();
		for (int i = 0; i < size; i++) {
			if (table[i]) return false;
		}
		return true;
	}

	/**
	*
	* getNumberOfItems
	*
	* Method to return number of items in the hash table
	*/
	int HashTable::getNumberOfItems() {
		return numberOfItems;
	}

	/**
	*
	* add
	*
	* Method to add a node to the hash table
	*/
	bool HashTable::add(int curKey, HashNode* myNode) {
		int hash = calculateHashCode(curKey);
		HashNode* prevNode = table[hash];
		if (!table[hash]) {
			table[hash] = myNode;
		}
		else {
			while (prevNode->next) {
				prevNode = prevNode->next;
			}


			prevNode->next = myNode;
			myNode->prev = prevNode;
		}

		numberOfItems++;
		return true;
	}

	/**
	*
	* remove
	*
	* Method to remove node with curKey
	*/
	bool HashTable::remove(int curKey) {
		int hash = calculateHashCode(curKey);
		if (!table[hash]) return false;
		HashNode* myNode = table[hash];
		while (myNode) {
			if (myNode->key == curKey) {
				break;
			}

			myNode = myNode->next;
		} 

		if (!myNode) return false;

		//   deletion portion

		//replace head
		if (myNode->prev) {
			myNode->prev->next = myNode->next;
		} else {
			table[hash] = myNode->next;
		}

		//shift linked list
		if (myNode->next) {
			myNode->next->prev = myNode->prev;
		}

		delete myNode;

		numberOfItems--;
		return true;
	}

	/**
	*
	* clear
	*
	* Method to remove all entries from the table
	*/
	void HashTable::clear() {
		int size = getSize();
		for (int i = 0; i < size; i++) {
			while (table[i]) remove(table[i]->key);
		}
		numberOfItems = 0;
	}

	/**
	*
	* getItem
	*
	* Method to retrieve item from the hash table
	*/
	HashNode* HashTable::getItem(int curKey) {
		int hash = calculateHashCode(curKey);
		HashNode* myNode = table[hash];
		while (myNode) {
			if (myNode->key == curKey) {
				return myNode;
			}

			myNode = myNode->next;
		}

		return nullptr;
	}

	/**
	*
	* contains
	*
	* Method to check if a node with key exists in the table
	*/
	bool HashTable::contains(int curKey) {
		return getItem(curKey) > 0;
	}

	/**
	*
	* printTable
	*
	* Method to print out the contents of table
	*/
	void HashTable::printTable() {
		std::ofstream& outFile = getOutFile();
		int size = getSize();
		bool empties = false;
		for (int i = 0; i < size; i++) {
			if (!table[i]) {
				if (!empties) {
					std::cout << "\nEmpty:";
					outFile << "\nEmpty:";
					empties = true;
				}
				std::cout << i << ", ";
				outFile << i << ", ";

				continue;
			}
			else {
				empties = false;
				std::cout << "\n";
				outFile << "\n";
			}
			std::cout << "\nindex: ";
			outFile << "\nindex: ";
			HashNode* myNode = table[i];
			while (myNode) {
				/*
				std::cout << "[Account: " << myNode->getFifoNode()->fullName <<
					", address: " << myNode->address <<
					", city: " << myNode->city <<
					", state: " << myNode->state <<
					", zip: " << myNode->zip <<
					"] ";
				*/
				std::cout << myNode->key << ", ";
				outFile << myNode->key << ", ";
				myNode = myNode->next;
			}
			std::cout << "\n";
			outFile << "\n";
		}
	}