#include <iostream>
#include "dynString.h"

using namespace std;

int main()
{
    char *ret;

    cout<<"hello world"<<endl;
    //
    // create a dynstring object
    dynString s1("sambit");
    //
    ret = (char*)s1.getStr();
    cout<<"string from the member function : "<<ret<<endl;

    ret = s1 + (char*)"mohapatra";
    cout<<"overload output : "<<ret<<endl;
    return 0;
}