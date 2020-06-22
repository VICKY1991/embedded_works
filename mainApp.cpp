#include <iostream>
#include "dynString.h"
#include "chapter_templates.h"
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

void exceptionHandlingDemo();
void formattedIODemo();
void demoVectors();


void fileIODemo()
{
    char inBuff[4], inBuff1[20];
    int age;
    //
    // create streams
    ofstream writer;
    ifstream reader;

    writer.open("sample.txt", ios::out); // open this file in write mode, create if not present already

    if(!writer)
        cout<<"File creation/opening failed\n";

    else
    {
        cout<<"File opened and ready for writing\n";
        // write something into it
        char str[] = "sambit mohapatra, hello how are you 1991?\n";
        writer<<str;
    }

    writer.close(); // close the file
    
    reader.open("sample.txt", ios::in); // open file in read mode
    if(!reader)
        cout<<"File opening failed, is it present?\n";

    else
    {
        reader>>inBuff;
        reader>>age;
        reader>>inBuff1;

        cout<<inBuff;
        cout<<age;
    }
    
        
    reader>>inBuff; // some reading

}



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

    // create a MPU6050 object
    MPU6050 mpu6050_obj();
    MPU6050 MPU6050_obj1(10.2, 12.2, 11.0, -0.23);

    MPU6050_obj1.showSensorData(); // from the base class
    MPU6050_obj1.getMPU6050Data(); // from this class
    MPU6050_obj1.storeSensorData(9.9, 1.1, 2.2);
    MPU6050_obj1.getMPU6050Data();

    // create pointer of base class
    Sensors *bptr, baseObj;
    float calibData[] = {1.1, 2.2, 3.3};
    
    // assign the base class object address to the base clas pointer
    bptr = &baseObj;
    bptr->calibrateSensor(calibData, 3); // invoke the virtual function

    // create objects of the two derived classses
    MPU5050 objx;
    bptr = &objx;

    bptr->calibrateSensor(calibData, 2);

    int n1 = 10;
    int n2 = 20;
    float m1 = 23.32, m2 = 45.56;

    cout<<"before swapping n1 : "<<n1<<endl;
    cout<<"before swapping n2 : "<<n2<<endl;

    swapNums(n1, n2);

    cout<<"after swapping n1 : "<<n1<<endl;
    cout<<"after swapping n2 : "<<n2<<endl;

    cout<<"before swapping m1 : "<<m1<<endl;
    cout<<"before swapping m2 : "<<m2<<endl;

    swapNums(m1, m2);

    cout<<"after swapping m1 : "<<m1<<endl;
    cout<<"after swapping m2 : "<<m2<<endl;
    
    exceptionHandlingDemo();

    formattedIODemo();

    fileIODemo();

    demoVectors();
     
    return 0;
}



void exceptionHandlingDemo()
{
    int a = 10, b = 0;

    // demonstrate a divide by 0 exception
    try
    {
        if(b == 0)
            throw -1;

        cout<<a/b<<endl;
        
    }
    catch(...)
    {
        cout<<"divide by 0 exception"<<endl;
    }
    
}

/*
* Demo the formatted io flags
*/
void formattedIODemo()
{
    // set the hex flag
    cout.setf(ios::hex);
    cout.setf(ios::showbase);
    cout<< 0x64 <<endl;

}



void demoVectors()
{
    // create 2 float vectors
    vector<float> fvec1(5), fvec2(5);

    int i;
    //
    for(i = 0; i < 5; i++)
    {
        fvec1[i] = i; // iitialize the vectors
        fvec2[i] = i*i; // initialize the second vector

    }

    // display size of vector
    cout<<"size : "<<fvec1.size()<<endl;

    // print the  type of the data
    cout<<typeid(fvec1).name()<<endl;

    // add the vectors
    // vector<float> sum_vec = fvec2 + fvec1;

}