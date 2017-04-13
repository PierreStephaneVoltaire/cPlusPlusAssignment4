#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <regex>
#include <cstdlib>
#include <sstream>
using namespace std;
class Person
{
private:
    std::string firstName;
    std::string lastName;
    int phoneNumber;
public:
    string getFirstName(){return firstName;}
    string getlastName(){return lastName;}
    int getPhoneNumber(){return phoneNumber;}
    void setFirstName(string firstName){this->firstName=firstName;}
    void setLastName(string lastName){this->lastName=lastName;}
    void setPhoneNumber(int phoneNumber){this->phoneNumber=phoneNumber;}
    friend bool operator== (const Person &p1, const Person &p2);
    friend bool operator< (const Person &p1, const Person &p2);
    friend bool operator> (const Person &p1, const Person &p2);
};
bool operator== (const Person &p1, const Person &p2)
{
    bool same=false;
    if (p1.lastName.compare(p2.lastName)==0&&p1.firstName.compare(p2.firstName)==0)
    {
        same=true;
    }
    return same;
}
bool operator< (const Person &p1, const Person &p2)
{
    bool smaller=false;
    if (p1.lastName.compare(p2.lastName)==0)
    {
        if (p1.firstName.compare(p2.firstName)<0) {
            smaller=true;
        }
    }
    else if (p1.lastName.compare(p2.lastName)<0)
    {
        smaller=true;
    }
    return smaller;
}
bool operator> (const Person &p1, const Person &p2)
{
    bool bigger=false;
    if (p1.lastName.compare(p2.lastName)==0)
    {
        if (p1.firstName.compare(p2.firstName)>0) {
            bigger=true;
        }
    }
    else if (p1.lastName.compare(p2.lastName)>0)
    {
        bigger=true;
    }
    return bigger;
}

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

        while(curr != NULL)
        {
            if(strcmp(curr->data.getlastName().c_str(),d.c_str())==0)
            {
                p[duplicate-1]=curr->data;
                if(strcmp(curr->left->data.getlastName().c_str(),d.c_str())!=0&&strcmp(curr->right->data.getlastName().c_str(),d.c_str())!=0){break;}
                else{duplicate++;
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
BinarySearchTree  loadfile(){
    BinarySearchTree b;
    ifstream myReadFile;
    myReadFile.open("phonebook.txt");
    cout<<"file loaded"<<endl;
    if (myReadFile.is_open()) {
        string line;
        regex words("[[:alpha:]]+-*[[:alpha:]]*");
        regex digits("\\d+");


        while (getline(myReadFile, line)) {
            Person p;
            smatch m;
            regex_search(line, m, words);
            p.setFirstName(m[0]);
            line = m.suffix();
            regex_search(line, m, words);
            p.setLastName(m[0]);
            line = m.suffix();
            smatch numericResults;
            regex_search(line, numericResults, digits);
            const string numb = numericResults[0].str();
            double phonenum = stoi(numb);
            p.setPhoneNumber(phonenum);
            b.insert(p);
        }

    }
    return b;
}
int main(int argc, char* argv[])
{
    BinarySearchTree b;
    b=loadfile();
    b.search("paul");




    return 0;
}
