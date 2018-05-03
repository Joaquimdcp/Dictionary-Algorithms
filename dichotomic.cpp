#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;



bool dichotomic(const unsigned int &query, const vector<unsigned int> &numbersVector, int left, int right){
    if (left > right or left < 0) return false;
    if (left == right) return (numbersVector[left] == query);
    int middle = (right + left) / 2;
    if (numbersVector[middle] < query) return dichotomic(query, numbersVector, middle + 1, right);
    else if (numbersVector[middle] > query) return dichotomic(query, numbersVector, left, middle - 1);
    else return true;
}




int main(){
    //read dictionary into a vector and measure time
    ifstream dictionary("arxiu1");
    vector<unsigned int> dictionaryVector;
    unsigned int num;
    chrono::time_point<chrono::system_clock> start, end;
    chrono::duration<double> elapsed;

    start = chrono::system_clock::now();
    while (dictionary >> num) dictionaryVector.push_back(num);
    end = chrono::system_clock::now();
    elapsed = end - start;
    //cout << dictionaryVector.size() << " numbers read from dictionary in " << elapsed.count() << " seconds." << endl;
    dictionary.close();

    //Sort vector and measure time
    sort(dictionaryVector.begin(), dictionaryVector.end());
    end = chrono::system_clock::now();
    elapsed = end - start;
    cout << elapsed.count() << endl;

/**
    //use text to perform searches
    ifstream text("arxiu2");
    unsigned int query;
    unsigned int queryCounter = 0;
    unsigned int successCounter = 0;
    bool found;

    start = chrono::system_clock::now();
    while (text >> query)
    {
        queryCounter++;
        found = dichotomic(query, dictionaryVector, 0, dictionaryVector.size() - 1);
        if (found) successCounter++;
    }
    end = chrono::system_clock::now();
    elapsed = end - start;

    cout << queryCounter << " queries performed in " << elapsed.count() << " second." << endl;
    cout << successCounter << " queries found in vector." << endl;
**/
}
