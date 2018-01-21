#include "Debug.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace GAME;
using namespace std;

/// TODO: rewrite to write this log file to the hard drive

void Debug::Log(const EMessageType MsgType, const char Class[], const char Method[], const char Contents[], bool writeToConsole) {
	//ofstream myfile;
	FILE *myfile = new FILE();

	myfile = fopen("DEBUGLOG.txt", "a");
	//myfile.open("DEBUGLOG.txt");
	switch (MsgType) {
	case EMessageType::INFO:
		fprintf(myfile, "INFO: %s :: %s :: %s \n", Class, Method, Contents);
		if (writeToConsole) {
			printf("INFO: %s :: %s :: %s \n", Class, Method, Contents);
		}
		break;
	case EMessageType::WARNING:
		//	myfile << "WARNING: " << Class << "::" << Method << "() - " << Contents << "\n" << std::endl;
		fprintf(myfile, "WARNING: %s :: %s :: %s \n", Class, Method, Contents);
		if (writeToConsole) {
			printf("WARNING: %s :: %s :: %s \n", Class, Method, Contents);
		}
		break;
	case EMessageType::ERROR:
		//	myfile << "ERROR: " << Class << "::" << Method << "() - " << Contents << "\n" << std::endl;
		fprintf(myfile, "ERROR: %s :: %s :: %s \n", Class, Method, Contents);
		if (writeToConsole) {
			printf("ERROR: %s :: %s :: %s \n", Class, Method, Contents);
		}
		break;
	case EMessageType::FATAL_ERROR:
		//myfile << "FATAL ERROR: " << Class << "::" << Method << "() - " << Contents << "\n" << std::endl;
		fprintf(myfile, "FATAL_ERROR: %s :: %s :: %s \n", Class, Method, Contents);
		if (writeToConsole) {
			printf("FATAL_ERROR: %s :: %s :: %s \n", Class, Method, Contents);
		}
		break;
	}

	fclose(myfile);
}