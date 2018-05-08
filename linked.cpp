#include<iostream>
#include<vector>
using namespace std;



typedef struct {
    int key;
    Node* follow;
} Node;

class HashTable {
    private:
        vector<Node> dictionary;

    public:
        HashTable(int size){
            dictionary = vector<Node>(size);
            for (int i = 0; i < size; i++)
                dictionary[i] = NULL;
        }
}