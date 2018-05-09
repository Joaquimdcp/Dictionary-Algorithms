#include <iostream>
#include <fstream>
#include "dichotomic_quim.hh"
#include "bst.hh"
using namespace std;


int main(){
    bst dic;
    ifstream dictionary("claus");
    unsigned int num;
    int i = 0;
    while (dictionary >> num){
        dic.insert(num);
        cout << "LOAD " << i << " ELEMENTS " << endl;
        i++;
    }

    ifstream text("text");
    unsigned int query;
    while (text >> query){
        dic.search(query);
        cout << "NUMERO DE COMPARACIONS " << dic.get_comparacions() << endl;
    } 
    
}
