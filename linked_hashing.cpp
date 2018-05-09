/*
 * C++ Program to Implement Hash Tables chaining
 * with Singly Linked Lists
 */
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>
using namespace std;

/*
 * HashNode Class Declaration
 */
class HashNode
{
    public:
      int key;
	    int value;
	    HashNode* follow;
        HashNode(int key, int value)
        {
            this->key = key;
	        this->value = value;
	        this->follow = NULL;
        }
};

/*
 * HashMap Class Declaration
 */
class HashMap
{
    private:
        HashNode** htable;

    public:
        HashMap()
        {
            htable = new HashNode*[TABLE_SIZE];
            for (int i = 0; i < TABLE_SIZE; i++)
                htable[i] = NULL;
        }

        ~HashMap()
        {
            for (int i = 0; i < TABLE_SIZE; ++i)
	          {
                HashNode* entry = htable[i];
                while (entry != NULL)
	              {
                    HashNode* prev = entry;
                    entry = entry->follow;
                    delete prev;
                }
            }
            delete[] htable;
        }
        /*
         * Hash Function
         */
        int HashFunc(int key)
        {
            return key % TABLE_SIZE;
        }

        int Universal(int key)
        {
            //AFEGIM UN SWITCH QUAN FAIGUE FALTA AMB UN RAND I LLEST
            return key % TABLE_SIZE;
        }


        /*
         * Insert Element at a key
         */
        void Insert(int key, int value)
        {
            int hash_val = HashFunc(key);
            HashNode* prev = NULL;
            HashNode* entry = htable[hash_val];
            while (entry != NULL)
            {
                prev = entry;
                entry = entry->follow;
            }
            if (entry == NULL)
            {
                entry = new HashNode(key, value);
                if (prev == NULL)
	              {
                    htable[hash_val] = entry;
                }
	        else
	        {
                    prev->follow = entry;
                }
            }
            else
            {
                entry->value = value;
            }
        }
        /*
         * Remove Element at a key
         */
        void Remove(int key)
        {
            int pos = HashFunc(key);
            HashNode* entry = htable[pos];
            HashNode* prev = NULL;
            if (entry == NULL || entry->key != key)
            {
            	  cout << "No Element found at key " << key <<endl;
                return;
            }
            while (entry->follow != NULL)
	    {
                prev = entry;
                entry = entry->follow;
            }
            if (prev != NULL)
            {
                prev->follow = entry->follow;
            }
            delete entry;
            cout<<"Element Deleted"<<endl;
        }
        /*
         * Search Element at a key
         */
        int Search(int key)
        {
            bool flag = false;
            int pos  = HashFunc(key);
            HashNode* entry = htable[pos];
            while (entry != NULL)
	    {
                if (entry->key == key)
	        {
                    cout<<"Value found at"<< pos ;
                    flag = true;
                }
                entry = entry->follow;
            }
            if (!flag)
                return -1;
        }
};
