// Copyright (c) 2021, Shelley Wong
// All rights reserved.
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// @file    Tree/tree.h
// @author  Wong, Shelley
// @brief   Declaration of Tree class for binary tree of integers
#ifndef TREE_H
#define TREE_H 

#include <iostream>
using std::string;

class Tree 
{
    public:
        Tree();
        ~Tree();
        bool insert(int value);
        bool find(int value);
        int size();
        int balanced();
        string print_inorder();
        string print_preorder();
        string print_postorder();
        string helper(int value);

    private:
        class Node
        {
            public:
                Node(int value);
                ~Node();
                int m_value;
                Node *m_left;
                Node *m_right;
        };
        Node *m_root;

        bool insert_r(int value, Node *&cur_root);
        bool find_r(int value, Node *cur_root);
        int size_r(Node *cur_root);
        int balanced_r(Node *cur_root);
        void print_inorder_r(Node *cur_root, string &result);
        void print_preorder_r(Node *cur_root, string &result);
        void print_postorder_r(Node *cur_root, string &result);
        string helper_r(int value, Node *cur_root, string &result);
};
#endif
