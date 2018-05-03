#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <vector>
#include "dichotomic_quim.hh"

using namespace std;

dicothomic::dicothomic()
{
    dictionary = {0};
}

dicothomic::~dicothomic()
{
    return;
}

bool dicothomic::search(unsigned int key)
{
    return dichotomic_s(key, dictionary, 0, int(dictionary.size() - 1));
}

bool dicothomic::dichotomic_s(const unsigned int &query, const vector<unsigned int> &numbersVector, int left, int right)
{
    if (left > right or left < 0) return false;
    if (left == right) return (numbersVector[left] == query);
    int middle = (right + left) / 2;
    if (numbersVector[middle] < query) return dichotomic_s(query, numbersVector, middle + 1, right);
    else if (numbersVector[middle] > query) return dichotomic_s(query, numbersVector, left, middle - 1);
    else return true;
}


void dicothomic::insert(int key){
    dictionary.push_back(key);
    sort(dictionary.begin(), dictionary.end());
}

int dicothomic::get(int key){
    return dictionary[key];
}
