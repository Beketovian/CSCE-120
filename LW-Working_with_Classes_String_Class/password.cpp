#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
string pw;
string com;
string inv = "";
cout << "Please enter your text input: ";
cin >> pw;
int length = pw.length();
cout << "input: " << pw << endl;
for(int i = 0; i < length; i++){
    if(pw.at(i) == 'a') {pw.at(i) = '@';}
    if(pw.at(i) == 'e') {pw.at(i) = '3';}
    if(pw.at(i) == 'i') {pw.at(i) = '!';}
    if(pw.at(i) == 'o') {pw.at(i) = '0';}
    if(pw.at(i) == 'u') {pw.at(i) = '^';}
}
for(int i = length-1; i >= 0; i--){inv += pw.at(i);}
com = pw + inv;
cout << "output: " << com << endl;
    return 0;
}
