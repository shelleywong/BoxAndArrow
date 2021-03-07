// Copyright (c) 2021, Shelley Wong
// All rights reserved.
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// @file    Tree/tree.cpp
// @author  Wong, Shelley
// @brief   Implementation of Tree class for binary tree of integers
#include "tree.h"
#include <emscripten/bind.h>

using namespace emscripten;
using namespace std;

// Tree Constructor
Tree::Tree() { 
    m_root = NULL; 
}

// Tree Destructor: Node's destructor is recursive
Tree::~Tree() { 

    // Write your code here

} 

// Node constructor 
// (initialized with value, inserted as a leaf Node)
Tree::Node::Node(int value) { 

    // Write your code here

}

// Node destructor (recursive)
Tree::Node::~Node() { 

    // Write your code here

}  

// @brief           Public function to insert value into the tree
// @param value     The value we want to insert in the tree
// @return true if insert was successful; 
//  return false if string was already in the tree
bool Tree::insert(int value) { 

    // Write your code here
    return false;
}

// @brief           Private recursive insert function
// @param value     The value we want to insert in the tree
// @param cur_root  Our current location in the tree
// @return true if insert was successful; 
//  return false if string already in the tree (no duplicates)
bool Tree::insert_r(int value, Node *&cur_root){

    // Write your code here
    return false;
}

// @brief           Public function to look up value in the tree
// @param value     The value we want to lookup
// @return true if target value was found; otherwise, return false
bool Tree::find(int value) { 

    // Write your code here
    return false;
}

// @brief           Private recursive lookup function
// @param value     The value we want to lookup
// @param cur_root  Our current location in the tree
// @return true if target value was found; otherwise, return false
bool Tree::find_r(int value, Node *cur_root){

    // Write your code here
    return false;
}

// @brief           Determine the size of the tree
// @return the size of the tree (number of nodes); 
//  return 0 if tree is empty (there are 0 nodes in an empty tree)
int Tree::size(){

    // Write your code here
    return 0;
}

// @brief           Private recursive size function
// @param cur_root  Our current location in the tree
// @return size of the tree (number of nodes); return 0 if tree is empty 
//  (Count all nodes in all left and right subtrees)
int Tree::size_r(Node *cur_root){

    // Write your code here
    return 0;
}

// @brief           Determine if the tree is balanced
// @return -1 if the tree is not height-balanced;
//  otherwise, return the height of the tree
//  (height is number of nodes on longest path from root to leaf)
int Tree::balanced(){

    // Write your code here
    return -1;
}

// @brief           Private recursive balanced function
// @param cur_root  Our current location in the tree
// @return -1 if the tree is not height-balanced;
//  otherwise, return the height of the tree
//
// Check all nodes of left and right subtrees, and if any cur_node 
// has unbalanced left and right subtrees, the entire tree is not 
// balanced (an empty tree is considered balanced)
int Tree::balanced_r(Node *cur_root){

    // Write your code here
    return -1;
}

// @brief   Print the nodes of the tree in order
// @return a string of space-separated integers 
//  (the values of our tree, in increasing order)
string Tree::print_inorder(){
    
    // Write your code here
    string result = "";
    return result;
}

// @brief           Private recursive print-in-order function
// @param cur_root  Our current location in the tree
// @param result    String of node values in in-order 
// 
// Append each value to the result string (will be printed in 
// increasing order) -- traverse every node in the tree
void Tree::print_inorder_r(Node *cur_root, string &result){

    // Write your code here

}

// @brief   Print the nodes of the tree in preorder
// @return a string of space-separated integers
// This traversal visits all root nodes before visiting leaf nodes
string Tree::print_preorder(){

    // Write your code here
    string result = "";
    return result;
}

// @brief           Private recursive print-pre-order function
// @param cur_root  Our current location in the tree
// @param result    String of node values in pre-order 
//
// Append each value to the result string (will print root nodes before 
// leaf nodes) -- traverse every node in the tree
void Tree::print_preorder_r(Node *cur_root, string &result) {

    // Write your code here

}

// @brief   Print the nodes of the tree in postorder
// @return a string of space-separated integers
// This traversal visits all leaf nodes before visiting root nodes
string Tree::print_postorder(){

    // Write your code here
    string result = "";
    return result;
}

// @brief           Private recursive print-post-order function
// @param cur_root  Our current location in the tree
// @param result    String of node values in post-order 
//
// Append each value to the result string (will print leaf nodes before 
// root nodes) -- traverse every node in the tree
void Tree::print_postorder_r(Node *cur_root, string &result) {

    // Write your code here

}

// @brief           A function to help the JSAV slideshow visualize 
//                  our C++ code results
// @param value     The value being inserted or looked up
// @return a string of integer values 0, 1, and 2 
//
// Initialize an empty result string, then call the private 
// recursive helper_r() with the value passed in as a parameter,
// the root of the tree, and the empty result string. 
// The result string will be made up of integers 0, 1, and 2. 
// 0 indicates that the value has been found. 
// 1 indicates that we should look to the left subtree next.
// 2 indicates that we should look to the right subtree next.
string Tree::helper(int value) { 

    // Write your code here
    string result = "";
    return result;
}

// @brief           Private recursive function to help our helper()
// @param value     The value being inserted or looked up
// @param cur_root  Our current location in the tree
// @param result    Our printed result
// @return a string of integer values 0, 1, and 2 
//
// This function has a similar format to the private recursive 
// insert and find functions. If current subtree is empty, return
// the result string. If the value at the current root matches the
// target value passed in as a parameter, add a "0" to the string
// and return; the value has been found. Otherwise, compare the
// target value to the value of the current node. If the node should
// be in the left subtree, add "1" to the result and visit the left
// subtree; otherwise, add "2" to the result and visit the right 
// subtree.
string Tree::helper_r(int value, Node *cur_root, string &result) {

    // Write your code here
    return result;
}


// Binding code
EMSCRIPTEN_BINDINGS(my_tree_class) {
    class_<Tree>("Tree")
        .constructor<>()
        .function("insert", &Tree::insert)
        .function("find", &Tree::find)
        .function("size", &Tree::size)
        .function("balanced", &Tree::balanced)
        .function("print_inorder", &Tree::print_inorder)
        .function("print_preorder", &Tree::print_preorder)
        .function("print_postorder", &Tree::print_postorder)
        .function("helper", &Tree::helper)
    ;
}
