#include <Wire.h>     // Including the wire library

#include <MPU6050.h>  // Including the MPU6050 library

MPU6050 accelerometer;          // Initializing a variable name accelerometer of type MPU6050


void setup()

{

Serial.begin(115200);       // Starting the serial communication at 115200 baud rate.

Serial.println("Initializing the MPU6050 sensor. Wait for a while");

delay(2000);

while(!accelerometer.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)) // Checking whether the mpu6050 is sensing or not

{
Serial.println("Something is Wrong!");
delay(500);
}
}



void loop()

{

Vector sensor_data = accelerometer.readNormalizeAccel();    // Reading the acceleration values from the sensor

int UpDown_value = -(atan2(sensor_data.XAxis, sqrt(sensor_data.YAxis*sensor_data.YAxis + sensor_data.ZAxis*sensor_data.ZAxis))*180.0)/M_PI;  // Calculating the pitch value

Serial.print(" UpDown = ");

Serial.print(UpDown_value);        // Printing the UpDown values on the Serial Monitor

int LeftRight_value = (atan2(sensor_data.YAxis, sensor_data.ZAxis)*180.0)/M_PI;    // Calculating the Raw value

Serial.print(" LeftRight = ");

Serial.println(LeftRight_value);        // printing the LeftRight values on the serial monitor

delay(10);

}
