#include <iostream>
#include <fstream>
#include <chrono>
#include "dichotomic_quim.hh"
#include "bst.hh"
#include "hash.hh"
using namespace std;


int main(){

    //dichotomic dic;

    int hashSize;                                   //Comentar
    cout << "Input hash table size:" << endl;       //quan
    cin >> hashSize;                                //sigui
    hash_table dic = hash_table(hashSize);          //dichotomic
    dichotomic dic2 = dichotomic();


    ifstream dictionary("claus");
    unsigned int num;
    chrono::time_point<chrono::system_clock> start, end;
    chrono::duration<double> elapsed;
    int i = 0;

    start = chrono::system_clock::now();
    while (dictionary >> num){
        dic.insert(num);
        dic2.insert(num);
        //cout << "LOAD " << i << " ELEMENTS " << endl;
        i++;
    }
    dic2.sortDic();                                // Descomentar quan sigui dichotomic
    end = chrono::system_clock::now();
    elapsed = end - start;

    cout << "Insertion time: " << elapsed.count() << " s." << endl;


    ifstream text("text");
    unsigned int query;
    start = chrono::system_clock::now();
    while (text >> query){
        dic.search(query);
        dic2.search(query);

    }
    end = chrono::system_clock::now();
    elapsed = end - start;

    cout << "Search time: " << elapsed.count() << " s." << endl;
    cout << "NUMERO DE COMPARACIONS DICOTOMICA" << dic2.get_comparacions() << endl;
    cout << "NUMERO DE COMPARACIONS HASH TABLE ARRAY" << dic2.get_comparacions() << endl;
}
