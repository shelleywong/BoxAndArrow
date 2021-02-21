// Copyright (c) 2021, Shelley Wong
// All rights reserved.
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// @file    List/list.cpp
// @author  Wong, Shelley
// @brief   Implementation of Linked-list class for list of integers

#include "list.h"
#include <iostream>
#include <stdlib.h>
#include <emscripten/bind.h>

using namespace emscripten;

using std::cout;

// Constructor
List::List(){
    m_head = NULL;
}

// Destructor
List::~List()
{
    while(m_head != NULL){
        Node *temp = m_head;
        m_head = m_head->m_next;
        delete temp;
    }
}

// @brief           Insert value into the list at the head
// @param value     Integer value to be inserted at the head
void List::insert(int value){
    m_head = new Node(value, m_head);
}

// @brief Print all of the elements in the list
void List::print(){
    Node *ptr = m_head;
    while(ptr != NULL){
        cout<<ptr->m_value<<" ";
        ptr = ptr->m_next;
    }
    cout<<"\n";
}

// @brief   Find the length of the linked list
// @return the number of elements in the list
//
// Determine the number of elements in the list
int List::length(){

    // Write your code here
    return 0;

}

// @brief           Lookup value in the list
// @param value     Integer value we are looking for
// @return the 'index' (location where the value can be 
//  found in the list (start index at node 0)
//
// If the given value is in the list, return the index of 
// where the node was found in the list; otherwise,
// return -1 (value was not found in the list)
int List::lookup(int value){

    // Write your code here
    return 0;

}

// @brief           Insert at the end (no duplicates)
// @param value     Integer value to be inserted at the head
// @return true if insert was successful;
//  return false if value was a duplicate (not inserted into list)
bool List::insert_at_end(int value){

    // Write your code here
    return true;

}

// @brief           Remove value from the list
// @param value     Integer value to be removed from list
// @return -1 if value is not removed (because it is not
//  in the list); otherwise, return the 'index' where the
//  value was found and removed.
int List::remove(int value){

    // Write your code here
    return 0;

}

// @brief           Remove value from head of list
// @return false if value is not removed (because the list
//  is empty); otherwise, return true (value removed).
bool List::remove_head(){

    // Write your code here
    return true;
    
}

// Binding code
EMSCRIPTEN_BINDINGS(my_class_example) {
    class_<List>("List")
        .constructor<>()
        .function("insert", &List::insert)
        .function("print", &List::print)
        .function("length", &List::length)
        .function("lookup", &List::lookup)
        .function("insert_at_end", &List::insert_at_end)
        .function("remove", &List::remove)
        .function("remove_head", &List::remove_head)
    ;
}
