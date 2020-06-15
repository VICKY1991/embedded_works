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


class Sensors
{
    // private data items
    float raw_data;
    float converted_data_out;

public:

    Sensors()
    {
        cout<<"default base constructor\n";
    }
    //
    // parameterized constructor
    Sensors(float offset)
    {
        this->raw_data = offset;
        this->converted_data_out = this->raw_data + 20.0;
        cout<<"received offset : "<<offset<<endl;
    }

    // member function
    void showSensorData()
    {
        cout<<"offset : "<<this->raw_data<<endl;
        cout<<"converted data : "<<this->converted_data_out<<endl;
    }

    float getCalibData()
    {
        return this->raw_data;
    }

    // create a virtual function
    virtual void calibrateSensor(float [], int);

};

// class implements a MPU6050, inherits the global Sensors
class MPU6050:virtual public Sensors
{
    //
    float gyro_x, gyro_y, gyro_z;

public:
    
    // default constructor, still needs to initi the base class with zeros
    MPU6050():Sensors(0)
    {
        cout<<"MPU object created with default offset\n";
    }
    //
    // parameterized constructor, initializes base class object
    MPU6050(float g_x, float g_y, float g_z, float offset):Sensors(offset)
    {
        cout<<"Base class initializer : "<<offset<<endl;
        this->gyro_x = g_x;
        this->gyro_y = g_y;
        this->gyro_z = g_z;

        cout<<"MPU6050 init params : "<<this->gyro_x, this->gyro_y, this->gyro_z, offset;
        cout<<endl;
    }

    // member function
    void storeSensorData(float, float, float);
    void getMPU6050Data();

    // declare the inherited virtual function again
    virtual void calibrateSensor(float[], int);
    
    

};


// another class that also inherits base sensors using virtual base class
class MPU5050:virtual public Sensors
{
    //
    float gyro_x, gyro_y, gyro_z;

public:
    
    // default constructor, still needs to initi the base class with zeros
    MPU5050():Sensors(0)
    {
        cout<<"MPU object created with default offset\n";
    }
    //
    // parameterized constructor, initializes base class object
    MPU5050(float g_x, float g_y, float g_z, float offset):Sensors(offset)
    {
        cout<<"Base class initializer : "<<offset<<endl;
        this->gyro_x = g_x;
        this->gyro_y = g_y;
        this->gyro_z = g_z;

        cout<<"MPU6050 init params : "<<this->gyro_x, this->gyro_y, this->gyro_z, offset;
        cout<<endl;
    }

    // member function
    void storeSensorData(float, float, float);
    void getMPU5050Data();

    // declare the virtual function again
    virtual void calibrateSensor(float[], int);
};

#endif