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

    // create a MPU6050 object
    MPU6050 mpu6050_obj();
    MPU6050 MPU6050_obj1(10.2, 12.2, 11.0, -0.23);

    MPU6050_obj1.showSensorData(); // from the base class
    MPU6050_obj1.getMPU6050Data(); // from this class
    MPU6050_obj1.storeSensorData(9.9, 1.1, 2.2);
    MPU6050_obj1.getMPU6050Data();
    return 0;
}