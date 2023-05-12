#include <string>
#include "Node.h"

using namespace std;

// Default constructor
Node::Node() : next{nullptr}, data{TemperatureData()}{} // remember to initialize next to nullptr

// Parameterized constructor
Node::Node(string id, int year, int month, double temperature) : next{nullptr}, data{TemperatureData(id,year,month,temperature)}{}
// remember to initialize next to nullptr

bool Node::operator<(const Node& b) {
	return this->data < b.data;
}
