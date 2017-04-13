#include "BinarySearchTree.hpp"
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
void BinarySearchTree::insert(Person d){
    tree_node* t = new tree_node;
    tree_node* parent=new tree_node;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    if(isEmpty()) {root = t;
}
else{
    tree_node* curr=new tree_node;
    curr = root;
    while(curr)
    {
        parent = curr;
        if(t->data > curr->data) {curr = curr->right;
    }
        else {curr = curr->left;
        }
        cout<<"going down\n";
    }
    if(t->data < parent->data){
        parent->left = t;
}
        else{
            parent->right = t;}
        }
    }
    //search
    vector<Person> BinarySearchTree::search(string d)
    {
		vector<Person>p;
        //check if its empty
        if(isEmpty())
        {
            cout<<" This Tree is empty! "<<endl;
            return p;
        }
  
        int duplicate=1;
	
	
		
	
	
        tree_node* curr=new tree_node;
        curr=NULL;
        tree_node* parent=new tree_node;
        curr = root;
        //while the node isn't null
        while(curr != NULL)
        {
            if(strcmp(curr->data.getlastName().c_str(),d.c_str())==0)
            {
				Person tempPerson= Person("","",0);
				cout << curr->data.getFirstName();
				//if (curr->data==NULL) {}
				tempPerson.setFirstName(curr->data.getFirstName
				());
				tempPerson.setLastName(curr->data.getlastName());
				tempPerson.setPhoneNumber(curr->data.getPhoneNumber());

				p.push_back(tempPerson); 
				int df = p.size();
                //check if the next left and right nodes are duplicate
				bool next = false;
                    if(curr->left){
						if (strcmp(curr->left->data.getlastName().c_str(), d.c_str()) == 0) { next = true; }
					}
					if (curr->right) {
						if (strcmp(curr->right->data.getlastName().c_str(), d.c_str()) == 0) { true; }
					}
					if (!next) { break; }
					else {
						parent = curr;
						if (strcmp(d.c_str(), curr->data.getlastName().c_str())>0) { curr = curr->right; }
						else { curr = curr->left; }
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