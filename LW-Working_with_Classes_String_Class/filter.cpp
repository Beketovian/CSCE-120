#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
    string sentence;
    string word;
    int ct;
    string replace;
    cout << "Please enter the sentence: ";
    cin >> sentence;
    cout << endl;
    cout << "Please enter the filter word: ";
    cin >> word;
    cout << endl;
    for(int i = 0; i < (int)word.size();i++){replace+="#";}
    for(int i = 0; i < (int)sentence.size(); i++)
    {
        if(sentence[i] == word[0]){
            ct = 0;
            for(int j = 0; j < (int)word.size(); j++){
                ct++;
            }
            if(ct == (int)word.size()){sentence.replace(i,(int)word.size(),replace);}
        }
    }
    cout << "Filtered sentence: " << sentence;
    return 0;
}
