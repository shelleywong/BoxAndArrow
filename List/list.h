// Copyright (c) 2021, Shelley Wong
// All rights reserved.
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.
//
// @file    List/list.h
// @author  Wong, Shelley
// @brief   Declaration of Linked-list class for list of integers

#ifndef LIST_H
#define LIST_H
#include <string>
using std::string;

class List
{
    public:
        List();
        ~List();
        void insert(int value);
        string print();
        int length();
        int lookup(int value);
        bool insert_at_end(int value);
        int remove(int value);
        bool remove_head();

    private:
        class Node
        {
            public:
                Node(int value, Node *next)
                { m_value = value; m_next = next; }
                int m_value;
                Node *m_next;
        };
        Node *m_head;
};
#endif

