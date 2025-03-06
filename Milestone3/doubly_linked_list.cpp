/**
* @author - Zoe Elias, Kirill Koukarine
* @file - doubly_linked_list.cpp - This is the implementation file for doubly_linked_list.h with insertion, deletion, and traversal methods.
* 03/06/2025 - Zoe Elias created file and created stubs for compilation and running code.
*
*/


//TODO: This file contains stub implementations. Functions need to be properly implemented.
//NOTE for Kirill Koukarine: You can implement the functions and modify this code however you like!

#include "doubly_linked_list.h"

DoublyLinkedList::DoublyLinkedList() { head = tail = nullptr; size = 0; }
DoublyLinkedList::~DoublyLinkedList() {}
int DoublyLinkedList::getSize() { return 0; }
bool DoublyLinkedList::isEmpty() { return true; }
void DoublyLinkedList::insertAtHead(int, DllNode*) {}
void DoublyLinkedList::insertAtTail(int, DllNode*) {}
void DoublyLinkedList::remove(int) {}
void DoublyLinkedList::removeHeaderNode() {}
void DoublyLinkedList::removeTailNode() {}
void DoublyLinkedList::moveNodeToHead(int) {}
void DoublyLinkedList::moveNodeToTail(int) {}
void DoublyLinkedList::clear() {}
void DoublyLinkedList::printList() {}
void DoublyLinkedList::reversePrintList() {}
