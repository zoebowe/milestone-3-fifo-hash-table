/**
 * @author - Zoe Elias
 * @file doubly_linked_list.cpp - This file implements the methods declared in doubly_linked_list.h.
 * 03/14/2025 - Z. Elias created the file and implemented the following methods:
 *              - getSize()
 *              - isEmpty()
 *              - insertAtHead()
 *              - insertAtTail()
 *              - remove()
 *              - removeHeaderNode()
 *              - removeTailNode()
 *              - moveNodeToHead()
 *              - moveNodeToTail()
 *              - clear()
 *              - printList()
 *              - reversePrintList()
 * 
 */

#include "doubly_linked_list.h"
#include <iostream>
#include <fstream>

extern std::ofstream& getOutFile(); // Declare external output file stream

// Constructor: Initializes an empty list
DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Destructor: Deletes all nodes to free memory
DoublyLinkedList::~DoublyLinkedList() {
    clear();
}

// Returns the size of the list
int DoublyLinkedList::getSize() {
    return size;
}

// Checks if the list is empty
bool DoublyLinkedList::isEmpty() {
    return size == 0;
}

// Insert at head
void DoublyLinkedList::insertAtHead(int key, DllNode* newNode) {
    if (!newNode) return;
    newNode->next = head;
    newNode->prev = nullptr;
    if (head) {
        head->prev = newNode;
    } else {
        tail = newNode;
    }
    head = newNode;
    size++;
}

// Insert at tail
void DoublyLinkedList::insertAtTail(int key, DllNode* newNode) {
    if (!newNode) return;
    newNode->prev = tail;
    newNode->next = nullptr;
    if (tail) {
        tail->next = newNode;
    } else {
        head = newNode;
    }
    tail = newNode;
    size++;
}

// Remove a node with a specific key
void DoublyLinkedList::remove(int key) {
    if (isEmpty()) return;

    DllNode* current = head;
    while (current && current->key != key) {
        current = current->next;
    }
    if (!current) return;

    if (current == head) {
        removeHeaderNode();
    } else if (current == tail) {
        removeTailNode();
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        size--;
    }
}

// Remove the head node
void DoublyLinkedList::removeHeaderNode() {
    if (isEmpty()) return;
    DllNode* temp = head;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    size--;
}

// Remove the tail node
void DoublyLinkedList::removeTailNode() {
    if (isEmpty()) return;
    DllNode* temp = tail;
    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    size--;
}

// Move a node to the head
void DoublyLinkedList::moveNodeToHead(int key) {
    if (isEmpty() || head->key == key) return;
    DllNode* current = head;
    while (current && current->key != key) {
        current = current->next;
    }
    if (!current || current == head) return;
    if (current == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    current->next = head;
    head->prev = current;
    current->prev = nullptr;
    head = current;
}

// Move a node to the tail
void DoublyLinkedList::moveNodeToTail(int key) {
    if (isEmpty() || tail->key == key) return;
    DllNode* current = head;
    while (current && current->key != key) {
        current = current->next;
    }
    if (!current || current == tail) return;
    if (current == head) {
        head = head->next;
        head->prev = nullptr;
    } else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    current->prev = tail;
    tail->next = current;
    current->next = nullptr;
    tail = current;
}

// Clear the entire list
void DoublyLinkedList::clear() {
    while (head) {
        DllNode* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

// Print the doubly linked list from head to tail
void DoublyLinkedList::printList() {
    std::ofstream& outFile = getOutFile();
    DllNode* current = head;
    while (current) {
        std::cout << current->key << " ";
        outFile << current->key << " ";
        current = current->next;
    }
    std::cout << std::endl;
    outFile << std::endl;
}

// Print the doubly linked list from tail to head
void DoublyLinkedList::reversePrintList() {
    std::ofstream& outFile = getOutFile();
    DllNode* current = tail;
    while (current) {
        std::cout << current->key << " ";
        outFile << current->key << " ";
        current = current->prev;
    }
    std::cout << std::endl;
    outFile << std::endl;
}
