#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Slot {
  int key;
  map<int, Slot*> stree;
};

class Trie {
  public:
    Trie();
    ~Trie();

    void insert(unsigned int n);
    bool search(unsigned int n);
    int get_comparacions();


  private:
    int comparacions;
    Slot root;
    vector<Slot*> stree;
};