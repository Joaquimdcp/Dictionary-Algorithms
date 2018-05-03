#include <iostream>

using namespace std;

struct node
{
    int value;
    node *left;
    node *right;
};

class bst
{
  public:
    bst();
    ~bst();

    void insert(int key);
    node *search(int key);
    void free();
    void inorder_print();
    void print_tree();

  private:
    void free(node *nd);
    void insert(int key, node *nd);
    node *search(int key, node *nd);
    void inorder_print(node *nd);
    void print_tree(node *nd);

    node *root;
};
