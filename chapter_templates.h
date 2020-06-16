#ifndef C_TEMPLATES_H
#define C_TEMPLATES_H

#include<iostream>
#include<cstring>

using namespace std;

// template <class gType> void swapNums(gType, gType); // declare the generic function

template <class gType> void swapNums(gType &num1, gType &num2)
{
    gType temp;
    //
    temp = num1;
    num1 = num2;
    num2 = temp;

    cout<<"swapping done\n";
}
#endif