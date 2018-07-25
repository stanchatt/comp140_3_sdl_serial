#include "stdafx.h"
#include "serialInterface.h"
#include <iostream>


SerialInterface::SerialInterface()
{
	std::vector <serial::PortInfo> devicesFound = serial::list_ports();

	std::vector <serial::PortInfo>::iterator iter = devicesFound.begin();

	while (iter != devicesFound.end())
	{
		serial::PortInfo device = *iter++;
		std::string port = device.port.c_str();

		try {
			mySerial = new serial::Serial(port, 115200, serial::Timeout::simpleTimeout(250));

			if (mySerial->isOpen())
			{
				std::cout << "Connection success: " << port << "\n";
				connect = true;

				break;
			}
		}
		catch (std::exception &e) {

		}
	}
}
SerialInterface::~SerialInterface()
{

}

void SerialInterface::send(std::string msg)
{
	if (connect)
	{
		mySerial->write(msg);
	}
}

void SerialInterface::getPositions()
{
	if (connect)
	{
		mySerial->write("P");

		std::string result = mySerial->readline();

		std::string sub1 = result.substr(0, 4);
		pot1 = std::stoi(sub1);


		std::string sub2 = result.substr(5, 9);
		pot2 = std::stoi(sub2);

	}
}

void SerialInterface::ledFlash(std::string input)
{
	if (connect)
	{
		mySerial->write(input);

		//std::string result = mySerial->readline();
	}
}

void SerialInterface::close()
{
	mySerial->flush();
	mySerial->close();
}