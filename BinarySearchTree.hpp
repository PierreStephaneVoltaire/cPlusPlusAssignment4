#ifndef BINARYSEARCHTREE_HPP
#define  BINARYSEARCHTREE_HPP
#include "Person.hpp"
#include <vector>
class BinarySearchTree
{
private:
    struct tree_node
    {
        tree_node* left;
        tree_node* right;
        Person data;
		tree_node() { left = NULL; right = NULL; data = Person(); }
    };
    tree_node* root;
public:
    BinarySearchTree()
    {
        root = NULL;
    }

    bool isEmpty() const { return root==NULL; }
    vector<Person> search(string);
    void insert(Person);
	vector<Person> BinarySearchTree::preOrder(tree_node*, vector<Person>);
    //void deleteNode(tree_node);
};
#endif
