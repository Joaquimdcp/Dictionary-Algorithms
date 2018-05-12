#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "trie.hh"

using namespace std;

Trie::Trie()
{
    comparacions = 0;
    root.key = -1;
}

Trie::~Trie()
{
    root.key = -1;
}

// function to convert decimal to binary
void decToBinary(unsigned int n, vector<int>& resultatBin)
{
    int i = 0;
    while (n > 0)
    {
        resultatBin[i] = n % 2;
        n = n / 2;
        i++;
    }
}

void Trie::insert(unsigned int n)
{

    map<int, Slot *> *current_tree = &root.stree;
    map<int, Slot *>::iterator it;

    vector<int> word_bin(1000);
    decToBinary(n, word_bin);

    for (int i = 0; i < word_bin.size(); ++i)
    {
        int val = word_bin[i];
        if ((it = current_tree->find(val)) != current_tree->end())
        {
            current_tree = &it->second->stree;
            continue;
        }

        if (it == current_tree->end())
        {
            Slot *new_node = new Slot();
            new_node->key = val;
            (*current_tree)[val] = new_node;
            current_tree = &new_node->stree;
        }
    }
}

bool Trie::search(unsigned int n)
{
    map< int, Slot* > sub_tree = root.stree;
    map< int, Slot* >::iterator it;

    vector<int> word_bin(1000);
    decToBinary(n, word_bin);

    for (int i = 0; i < word_bin.size(); ++i)
    {
        comparacions++;
        if ((it = sub_tree.find(word_bin[i])) == sub_tree.end()) //POTSER PODEM CANVIARO PERO NOMES HI HA DOS VALORS PER TANT...
            return false;

        sub_tree = it->second->stree;
    }
    return true;
}

int Trie::get_comparacions(){
    return comparacions;
}