#include <iostream>
#include <bitset>
using namespace std;

class bloom {
    private:
        int comparacions;
        bitset<64> dictionary;
        int total_functions;

    public:
        bloom();
        void insert(unsigned int key);
        bool search(unsigned int key);
        int hash_functions(int f, unsigned int key);
        int get_comparacions();
};