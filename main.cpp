#include <iostream>
#include <fstream>
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

    ifstream dictionary("claus");
    unsigned int num;
    chrono::time_point<chrono::system_clock> start, end;
    chrono::duration<double> elapsed;
    int i = 0;

    start = chrono::system_clock::now();
    while (dictionary >> num){
        dic.insert(num);
        //cout << "LOAD " << i << " ELEMENTS " << endl;
        i++;
    }
    //dic.sortDic();                                // Descomentar quan sigui dichotomic
    end = chrono::system_clock::now();
    elapsed = end - start;

    //cout << "Insertion time: " << elapsed.count() << " s." << endl;

    ifstream text("text");
    unsigned int query;
    start = chrono::system_clock::now();
    while (text >> query){
        dic.search(query);
        //cout << "NUMERO DE COMPARACIONS " << dic.get_comparacions() << endl;
    }
    end = chrono::system_clock::now();
    elapsed = end - start;

    cout << "Search time: " << elapsed.count() << " s." << endl;

}
