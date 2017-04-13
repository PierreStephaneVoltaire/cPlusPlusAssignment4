#include "Person.hpp"

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
