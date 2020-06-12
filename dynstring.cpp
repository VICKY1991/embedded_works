#include "dynString.h"

char* dynString::getStr()
{
    return (char*)this->str;
}


// the string on the rhs of the invoking object is s1
char* dynString::operator+(char s1[])
{
    strcat(this->str, s1); // the invoking object is accessed with this

    return (char*)this->str;
}
    
