#include<iostream>
#include<vector>
using namespace std;



class Node
{
    public:
        int key;
	    Node* follow;
        Node(int key)
        {
            this->key = key;
	        this->follow = NULL;
        }
};

class HashTable {
    private:
        vector< Node* > dictionary;
        int size_table;

        int hash_function(int key)
        {
            return key % size_table;
        }

    public:
        HashTable(int size){
            size_table = size;
            dictionary = vector< Node* >(size);
            for (int i = 0; i < size; i++)
                dictionary[i] = NULL;
        }

        void Insert(int key, int value)
        {
            int pos = hash_function(key);

            Node* prev = NULL;
            Node* entry = dictionary[pos];
            while (entry != NULL)
            {
                prev = entry;
                entry = entry->follow;
            }

            if (entry == NULL)
            {
                entry = new Node(key);
                if (prev == NULL)
	            {
                    dictionary[pos] = entry;
                }
	            else
	            {
                    prev->follow = entry;
                }
            }
            else
            {
                entry->key = key;
            }
        }
};