//#include <bits/stdc++.h>
#pragma once

using namespace std;
template <class T>
struct Node
{
    T data;
    Node *next = NULL, *prev = NULL;
};

template <class T>
struct Linkedlist
{
    Node<T> *head = NULL;
    Node<T> *tail = NULL;
};