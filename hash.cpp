#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <vector>
#include "hash.hh"

using namespace std;

hash_table::hash_table(int hashSize)
{
    dictionary = vector<vector<unsigned int> > (hashSize);
}

hash_table::~hash_table()
{
    return;
}

int hash_table::hash_function(int key){
    return key % dictionary.size();
}

bool hash_table::search(int key)
{
    int pos = hash_function(key) ;
    for(int i = 0; i<dictionary[ pos].size(); i++ ){
        if(dictionary[pos][i] == key ) return true;
    }
    return false;
}

void hash_table::insert(int key){
    int pos = hash_function(key);
    dictionary[ pos].push_back(key);
}
