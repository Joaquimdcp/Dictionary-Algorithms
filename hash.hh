#include <iostream>
using namespace std;


class hash_table
{
  public:
    hash_table(int hashSize);
    ~hash_table();

    void insert(int key);
    bool search(int key);
    int get_comparacions();


  private:
    vector<vector<unsigned int> > dictionary;
    int comparacions;
    int hash_function(int key);

};

