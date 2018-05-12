/*
 * C++ Program to Implement Hash Tables chaining
 * with Singly Linked Lists
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include "linked_hashing.hh"
using namespace std;

HashNode::HashNode(unsigned int key)
{
    this->key = key;
    this->follow = NULL;
}

Linked::Linked(int size)
{
    size_table = size;
    comparacions = 0;
    htable = vector<HashNode*>(size);
    for (int i = 0; i < size_table; i++)
        htable[i] = NULL;

}

int Linked::HashFunc(unsigned int key)
{
    return key % size_table;
}

int Linked::Universal(int key)
{
    //AFEGIM UN SWITCH QUAN FAIGUE FALTA AMB UN RAND I LLEST
    return key % size_table;
}

void Linked::insert(unsigned int key)
{
    int hash_val = HashFunc(key);
    HashNode *prev = NULL;
    HashNode *entry = htable[hash_val];
    while (entry != NULL)
    {
        prev = entry;
        entry = entry->follow;
    }
    if (entry == NULL)
    {
        entry = new HashNode(key);
        if (prev == NULL)
        {
            htable[hash_val] = entry;
        }
        else
        {
            prev->follow = entry;
        }
    }
}

void Linked::remove(unsigned int key)
{
    int pos = HashFunc(key);
    HashNode *entry = htable[pos];
    HashNode *prev = NULL;
    if (entry == NULL || entry->key != key)
    {
        return;
    }
    while (entry->follow != NULL)
    {
        prev = entry;
        entry = entry->follow;
    }
    if (prev != NULL)
    {
        prev->follow = entry->follow;
    }
    delete entry;
}

bool Linked::search(unsigned int key)
{
    bool flag = false;
    int pos = HashFunc(key);
    HashNode *entry = htable[pos];
    while (entry != NULL)
    {
        comparacions++;
        if (entry->key == key) return true;
        entry = entry->follow;
    }
    return false;
}

int Linked::get_comparacions(){
    return comparacions;
}
