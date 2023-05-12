#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    string input;
    bool done = false;
    string lhs;
    string rhs;
    while(!done){
    cout << ">> " << endl;
    getline(cin, input);
    if(input == "q" || input == "quit"){break;}
    bool ad = false;
    if(input.find("+") > 0){ad = true;}
        for(long unsigned int i = 0; i < input.length(); i++)
        {
            if(input[i] == '+' || input[i] == '*'){
                lhs = input.substr(0,i-1);
                rhs = input.substr(i+2,input.length()-1);
            }
        }
        if(ad){cout << "ans =" << endl << endl<< "    " << add(lhs,rhs) << endl << endl;}
        else{cout << "ans =" << endl << endl <<"    " <<  multiply(lhs,rhs) << endl << endl;}
    }
    cout << "farvel!" << endl << endl;
}

