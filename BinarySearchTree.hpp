#ifndef BINARYSEARCHTREE_HPP
#define  BINARYSEARCHTREE_HPP
#include "Person.hpp"
class BinarySearchTree
{
private:
    struct tree_node
    {
        tree_node* left;
        tree_node* right;
        Person data;
    };
    tree_node* root;
public:
    BinarySearchTree()
    {
        root = NULL;
    }

    bool isEmpty() const { return root==NULL; }
    Person* search(string);
    void insert(Person);
    //void deleteNode(tree_node);
};
#endif
