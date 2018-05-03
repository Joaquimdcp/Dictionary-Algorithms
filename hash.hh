#include <iostream>
using namespace std;


class hash_table
{
  public:
    hash_table(int hashSize);
    ~hash_table();

    void insert(int key);
    bool search(int key);

  private:
    vector<vector<unsigned int> > dictionary;
    int hash_function(int key);
};

