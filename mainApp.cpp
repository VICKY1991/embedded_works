#include <iostream>
#include "dynString.h"
#include "chapter_templates.h"

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
  
     
    return 0;
}
