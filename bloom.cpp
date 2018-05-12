#include <iostream>
#include <bitset>
#include "bloom.hh"
using namespace std;


bloom::bloom()
{
    dictionary = {0};
    comparacions = 0;
    total_functions = 4;
}

int checksum(int param)
{
    int sum = 0;

    while (param > 0)
    {
        sum += param % 10;
        param /= 10;
    }

    while (sum > 9) { sum = checksum(sum); }

    return sum;
}


int bloom::hash_functions(int f, unsigned int key){
    switch(f) {
        case 0:
            return key%64;
        case 1:
            return (2*key*key+13)%64;
        case 2:
            return checksum(key);
        case 3:
            return (key+1+key*key)%64;
    }
}


void bloom::insert(unsigned int key){
    for(int i = 0; i < total_functions; i++){
        dictionary[hash_functions(i,key)] = true;
    }
}

bool bloom::search(unsigned int key){
    comparacions = 0;
    for(int i = 0; i < total_functions; i++){
        comparacions++;
        if(not dictionary[hash_functions(i,key)]) return false;
    }
    return true;
}

int bloom::get_comparacions(){
    return comparacions;
}
