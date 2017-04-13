#include "BinarySearchTree.hpp"
#include <string>
#include <iostream>
#include <cstring>
void BinarySearchTree::insert(Person d){
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    if(isEmpty()) {root = t;
    cout<<"tree empty so adding root elem\n";
}
else{
    cout<<"this is the root"<<root->data.getFirstName()<<"\n";
    cout<<"tree not empty\n";
    tree_node* curr;
    curr = root;
    while(curr)
    {
        parent = curr;
        if(t->data > curr->data) {curr = curr->right;
        cout<<"going right\n";}
        else {curr = curr->left;
        cout<<"going left\n";}
    }
    if(t->data < parent->data){
        parent->left = t;
        cout<<"added left "<<parent->left->data.getlastName()<<"\n";}
        else{
            parent->right = t;
            cout<<"added right "<<parent->right->data.getlastName()<<"\n";}
        }
    }
    //search
    Person* BinarySearchTree::search(string d)
    {
        //check if its empty
        if(isEmpty())
        {
            cout<<" This Tree is empty! "<<endl;
            return 0;
        }
        Person *p=NULL;
        int duplicate=1;
        p=new Person[duplicate];
        tree_node* curr=NULL;
        tree_node* parent;
        curr = root;
        //while the node isn't null
        while(curr != NULL)
        {
            if(strcmp(curr->data.getlastName().c_str(),d.c_str())==0)
            {
                p[duplicate-1]=curr->data;
                //check if the next left and right nodes are duplicate
                if(curr->left!=NULL||curr->right!=NULL){break;}
                else if(strcmp(curr->left->data.getlastName().c_str(),d.c_str())!=0&&strcmp(curr->right->data.getlastName().c_str(),d.c_str())!=0){break;}
                else{
                    //copy array
                    duplicate++;
                    Person* temp=new Person[duplicate];
                    copy(p,p+duplicate-1,temp);
                    delete[]p;
                    p=temp;
                }
            }
            else
            {
                parent = curr;
                if(strcmp(d.c_str(),curr->data.getlastName().c_str())>0) {curr = curr->right;}
                else {curr = curr->left;}
            }
        }
        return p;
    }
