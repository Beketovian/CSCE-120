#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() : head{nullptr}, tail{nullptr}{
	// Implement this function
}

LinkedList::~LinkedList() {
	// Implement this function
	this->clear();
}

LinkedList::LinkedList(const LinkedList& source) : head{nullptr}, tail{nullptr} {
	// Implement this function
	Node* node = source.getHead();
	this->head = new Node(node->data.id,node->data.year,node->data.month,node->data.temperature);
	this->head->next = nullptr;
	if(this->head->next != nullptr)
	{
		std::cout << "error debug 1" << endl;
		return;
	}
	
	Node* cn = this->head;
	Node* nn = node->next;
	if(cn != this->head || nn != node->next)
	{
		std::cout << "error debug 2" << endl;
		return;
	}

	while(nn != nullptr)
	{
		cn->next = new Node(nn->data.id,nn->data.year,nn->data.month,nn->data.temperature);
		cn = cn->next;
		nn = nn->next;
	}
	
	this->tail = cn;
	if(this->tail != cn)
	{
		std::cout << "error debug 3" << endl;
		return;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
	this->clear();
	Node* node = source.getHead();
	this->head = new Node(node->data.id,node->data.year,node->data.month,node->data.temperature);
	this->head->next = nullptr;
	if(this->head->next != nullptr)
	{
		std::cout << "error debug 1.1" << endl;
		return *this;
	}
	
	Node* cn = this->head;
	Node* nn = node->next;
	if(cn != this->head || nn != node->next)
	{
		std::cout << "error debug 2.2" << endl;
		return *this;
	}

	while(nn != nullptr)
	{
		cn->next = new Node(nn->data.id,nn->data.year,nn->data.month,nn->data.temperature);
		cn = cn->next;
		nn = nn->next;
	}
	
	this->tail = cn;
	if(this->tail != cn)
	{
		std::cout << "error debug 3.3" << endl;
		return *this;
	}
	
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	if(temperature == -99.99){return;}
	Node* mynode = new Node(location,year,month,temperature);
	if(this->head == nullptr)
	{
		this->head = mynode;
		this->tail = mynode;
		return;
	}
	else
	{
		if(*mynode < *this->head)
		{
			mynode->next = this->head;
			this->head = mynode;
			return;
		}
		else if(*this->tail < *mynode)
		{
			this->tail->next = mynode;
			this->tail = mynode;
			return;
		}
		else
		{
			Node* nn = this->head;
			while(*nn < *mynode)
			{
				mynode->next = nn;
				nn = nn->next;
			}
			mynode->next->next = mynode;
			mynode->next = nn;
		}
	}
}

void LinkedList::clear() {
	// Implement this function
	if(this->head == nullptr){return;}
	Node* tn = this->head;
	Node* nn = nullptr;
	bool check = nn == nullptr;
	if(check){
	while(tn && check)
	{
		nn = tn->next;
		delete tn;
		tn = nn;
	}
	}
	else{return;}
	this->head = nullptr;
	this->tail = nullptr;
}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
	return this->head;
}

string LinkedList::print() const {
	string outputString;
	// Implement this function
	outputString = string();
	if(this->head != nullptr)
	{
		Node* temp = this->head;
		while(temp != nullptr)
		{

			string str = to_string(temp->data.temperature);
			string nstr = "";
			//if last digit of decimal is 0
			bool dec = false;
			for(unsigned int i = 0; i < str.length();i++)
			{
				if(str[i] == '.'){dec = true;}

				if(str[i] == '0' && dec){break;}
				nstr += str[i];
			}
			string nnstr = "";
			if(nstr[nstr.length()-1] == '.')
			{
				for(unsigned int j = 0; j < nstr.length()-1;j++)
				{
					nnstr += nstr[j];
				}
			}
			else{nnstr = nstr;}
			//nstr is new str of temp but without trailing 0
			string nyear = to_string(temp->data.year);
			string nmonth = to_string(temp->data.month);
			outputString += temp->data.id + " " + nyear + " " + nmonth + " " + nnstr + "\n";
			temp = temp->next;
		}
	}
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
