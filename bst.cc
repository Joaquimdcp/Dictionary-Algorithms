#include "bst.hh"

bst::bst()
{
    root = NULL;
}

bst::~bst()
{
    free();
}

void bst::free(node *nd)
{
    if (nd != NULL)
    {
        free(nd->left);
        free(nd->right);
        delete nd;
    }
}

void bst::insert(int key, node *nd)
{

    if (key < nd->value)
    {
        if (nd->left != NULL)
        {
            insert(key, nd->left);
        }
        else
        {
            nd->left = new node;
            nd->left->value = key;
            nd->left->left = NULL;
            nd->left->right = NULL;
        }
    }
    else if (key >= nd->value)
    {
        if (nd->right != NULL)
        {
            insert(key, nd->right);
        }
        else
        {
            nd->right = new node;
            nd->right->value = key;
            nd->right->right = NULL;
            nd->right->left = NULL;
        }
    }
}

void bst::insert(int key)
{
    if (root != NULL)
    {
        insert(key, root);
    }
    else
    {
        root = new node;
        root->value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

node *bst::search(int key, node *nd)
{
    if (nd != NULL)
    {
        if (key == nd->value)
        {
            return nd;
        }
        if (key < nd->value)
        {
            return search(key, nd->left);
        }
        else
        {
            return search(key, nd->right);
        }
    }
    else
    {
        return NULL;
    }
}

node *bst::search(int key)
{
    return search(key, root);
}

void bst::free()
{
    free(root);
}

void bst::inorder_print()
{
    inorder_print(root);
    cout << "\n";
}

void bst::inorder_print(node *nd)
{
    if (nd != NULL)
    {
        inorder_print(nd->left);
        cout << nd->value << ",";
        inorder_print(nd->right);
    }
}

void bst::print_tree()
{
    print_tree(root);
    cout << "\n";
}

void bst::print_tree(node *nd)
{
    if (nd != NULL)
    {
        inorder_print(nd->left);
        inorder_print(nd->right);
        cout << nd->value << ",";
    }
}