#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <vector>
#include "dichotomic_quim.hh"

using namespace std;

dichotomic::dichotomic()
{
    dictionary = {0};
    comparacions = 0;
}

dichotomic::~dichotomic()
{
    return;
}

bool dichotomic::search(unsigned int key)
{
    return dichotomic_s(key, dictionary, 0, int(dictionary.size() - 1));
}

bool dichotomic::dichotomic_s(const unsigned int &query, const vector<unsigned int> &numbersVector, int left, int right)
{
    if (left > right or left < 0){
      comparacions++;
      return false;
    }
    if (left == right) {
      comparacions++;
      return (numbersVector[left] == query);
    }
    int middle = (right + left) / 2;
    if (numbersVector[middle] < query){
      comparacions++;
      return dichotomic_s(query, numbersVector, middle + 1, right);
    }
    else if (numbersVector[middle] > query){
      comparacions++;
      return dichotomic_s(query, numbersVector, left, middle - 1);
    }
    else return true;
}


void dichotomic::insert(int key){
    dictionary.push_back(key);
    //sort(dictionary.begin(), dictionary.end());
}

void dichotomic::sortDic(){
    sort(dictionary.begin(), dictionary.end());
}

int dichotomic::get(int key){
    return dictionary[key];
}


int dichotomic::get_comparacions(){
  return comparacions;
}
