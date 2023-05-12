#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
string word;
int ct = 0;
cout << "Please enter a sentence (end with 'quit'): ";
cin >> word;
while(word != "quit"){
string inv = "";
for(int i = word.size()-1; i >= 0; i--){inv += word.at(i);}
bool same = false;
for(int i = 0; i < int(word.size()); i++){
    if(word.at(i) == inv.at(i)){same = true;}
    else{
        same = false;
        break;
    }
}
    if(same){ct += 1;}
    cin >> word;
}
cout << "You have typed " << ct << " palindromes.";
    return 0;
}
