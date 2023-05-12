#include "TemperatureDatabase.h"

#include <fstream>
#include <sstream>
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() : records{LinkedList()}{}


TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// Implement this function for part 1
	ifstream f(filename);
	if(!f.is_open()){return;}
	stringstream strs;
	bool done = false;
	int ct = 0;
	while(!done)
	{
		string id = "";
		int yr = 0;
		int mon = 0;
		double temp = 0;
		string line = "";
		getline(f,line);
		if(line.empty() && f.eof()){break;}
		else
		{
			strs.clear();
			strs.str(line);
			strs >> id;
			if(strs.fail() && ct < 2){cout << "Error: Other invalid input" << endl; ct++;}
			strs >> yr;
			if(strs.fail() && ct < 2){cout << "Error: Other invalid input" << endl; ct++;}
			if(yr < 1800 || yr > 2022){cout << "Error: Invalid year " << yr << endl;}
			strs >> mon;
			if(strs.fail() && ct < 2){cout << "Error: Other invalid input" << endl; ct++;}
			if(mon < 1 || mon > 12){cout << "Error: Invalid month " << mon << endl;}
			strs >> temp;
			if(strs.fail() && ct < 2){cout << "Error: Other invalid input" << endl; ct++;}
			if(temp != -99.99 && temp < -50 || temp > 50){cout << "Error: Invalid temperature " << temp << endl;}
			this->records.insert(id,yr,mon,temp);
		}		
	}
}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// Implement this function for part 2
	//  Leave it blank for part 1
}
