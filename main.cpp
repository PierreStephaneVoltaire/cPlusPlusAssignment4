#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <fstream>
#include <regex>
#include <vector>
#include <cstdlib>
#include <sstream>
#include "Person.hpp"
#include "BinarySearchTree.hpp"
using namespace std;
BinarySearchTree  loadfile(){
    BinarySearchTree b;
    ifstream myReadFile;
    myReadFile.open("phonebook.txt");
    cout<<"file loaded"<<endl;
    if (myReadFile.is_open()) {
        string line;
        regex words("[[:alpha:]]+");
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
	/*vector<Person>  perARR=b.search("paul");
	cout <<"\n" <<perARR.size();
	for (int i = 0; i < perARR.size(); i++) {
		cout << "\n" << perARR[i].getFirstName();
		cout << "\n" << perARR[i].getlastName();
		cout << "\n" << perARR[i].getPhoneNumber();
	}*/

	system("PAUSE");
    return 0;
}
