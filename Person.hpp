#ifndef PERSON_HPP
#define  PERSON_HPP
#include <string>
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
#endif
