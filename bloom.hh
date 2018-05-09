#include <iostream>
#include <bitset>
using namespace std;

class bloom {
    private:
        int comparacions;
        bitset<64> dictionary;
        int total_functions;

    public:
        void insert(unsigned int key);
        void search(unsigned int key);
}