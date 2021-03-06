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


//------------------------------- for the base sensors ---------------------------------------------------------//
void Sensors::calibrateSensor(float calib_params[], int n)
{
    int i;
    //
    for(i = 0; i < n; i++)
    {
        this->raw_data += n*n;
    }

    cout<<"calibrated with base sensor : "<<this->raw_data<<endl;
}

//----------------------------------- for MPU6050 --------------------------------------------------------------------------------------------//

// take 3 floats and add to default values in the object
void MPU6050::storeSensorData(float g_x, float g_y, float g_z)
{
    this->gyro_x += g_x;
    this->gyro_y += g_y;
    this->gyro_z += g_z;

}


void MPU6050::getMPU6050Data()
{
    float offset;

    cout<<"gyro_x : "<<this->gyro_x<<endl;
    cout<<"gyro_y : "<<this->gyro_y<<endl;
    cout<<"gyro_z : "<<this->gyro_z<<endl;
    
    offset = Sensors::getCalibData(); // it is same as writing getCalibData(), just makes it more clear and explicit

    cout<<"offset : "<<offset<<endl;
}


void MPU6050::calibrateSensor(float calib_data[], int n)
{
    int i;
    //
    for(i = 0; i < n; i++)
    {
        this->gyro_x += n*n;
    }

    cout<<"calibrated with MPU6050 class sensor : "<<this->gyro_x<<endl;
}

//--------------------------- For MPU5050 ------------------------------------------------------------------------------------------------------//
void MPU5050::storeSensorData(float g_x, float g_y, float g_z)
{
    this->gyro_x += g_x;
    this->gyro_y += g_y;
    this->gyro_z += g_z;

}

void MPU5050::getMPU5050Data()
{
    float offset;

    cout<<"gyro_x : "<<this->gyro_x<<endl;
    cout<<"gyro_y : "<<this->gyro_y<<endl;
    cout<<"gyro_z : "<<this->gyro_z<<endl;
    
    offset = Sensors::getCalibData(); // it is same as writing getCalibData(), just makes it more clear and explicit

    cout<<"offset : "<<offset<<endl;
}


void MPU5050::calibrateSensor(float calib_data[], int n)
{
    int i;
    //
    for(i = 0; i < n; i++)
    {
        this->gyro_x += n*n;
    }

    cout<<"calibrated with MPU5050 class sensor : "<<this->gyro_x<<endl;
}