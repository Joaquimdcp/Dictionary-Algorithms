#include <iostream>
#include <vector>
using namespace std;

class HashNode
{
  public:
    unsigned int key;
    HashNode *follow;
    HashNode(unsigned int key);
};

class Linked
{
  private:
    vector<HashNode*> htable;
    int size_table;
    int comparacions;

  public:
    Linked(int size);

    /*
         * Hash Function
         */
    int HashFunc(unsigned int key);
    int get_comparacions();

    int Universal(int key);

    /*
         * Insert Element at a key
         */
    void insert(unsigned int key);
    /*
         * Remove Element at a key
         */
    void remove(unsigned int key);
    bool search(unsigned int key);
};
