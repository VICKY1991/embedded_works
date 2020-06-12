#ifndef DYNSTRING_H
#define DYNSTRING_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// a dynamic string class with overloaded operators for funny processing
class dynString
{
    char str[100]; // to hold the initialized string address
public:

    dynString(); // default constructor

    // parameterized constructor - inline
    dynString(char sin[])
    {
        strcpy(this->str, sin); // just copy the address
        cout<<"init string : "<<this->str<<endl;

    }

    // create a public member function to get the string from the object
    char* getStr();

    // create an overloaded operator for concatenating 2 strings
    char* operator+(char[]);

};

#endif