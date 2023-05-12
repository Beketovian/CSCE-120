#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    if (digit == 48 || digit == 30){return 0;}
    if (digit == 49 || digit == 31){return 1;}
    if (digit == 50 || digit == 32){return 2;}
    if (digit == 51 || digit == 33){return 3;}
    if (digit == 52 || digit == 34){return 4;}
    if (digit == 53 || digit == 35){return 5;}
    if (digit == 54 || digit == 36){return 6;}
    if (digit == 55 || digit == 37){return 7;}
    if (digit == 56 || digit == 38){return 8;}
    if (digit == 57 || digit == 39){return 9;}
    throw std::invalid_argument("input invalid");  
}

char decimal_to_digit(unsigned int decimal) {
    if (decimal == 0){return '0';}
    if (decimal == 1){return '1';}
    if (decimal == 2){return '2';}
    if (decimal == 3){return '3';}
    if (decimal == 4){return '4';}
    if (decimal == 5){return '5';}
    if (decimal == 6){return '6';}
    if (decimal == 7){return '7';}
    if (decimal == 8){return '8';}
    if (decimal == 9){return '9';}
    throw std::invalid_argument("input invalid");
    } 


string trim_leading_zeros(string num) {
    bool neg = false;
    int size = num.length();
    //for negatives:
    if(num[0] == '-'){
        neg = true;
        num.erase(0,1);
        if(num[0] == '0'){size--;}  
    }
    int ct = 0;
    while(num.at(0) == '0'){
        ct++;
        if(ct == size){
            num = "0";
            return num;
        }
        num = num.substr(1);
    }
    if(neg){num.insert(0,"-");}
    return num;
}


string add(string lhs, string rhs) {    
    // //turn into int
    // int l = 0;
    // for(char c: lhs){
    //     if(c >= '0' && c <= '9'){l = l * 10 + (c-'0');}
    // }
    // int r = 0;
    // for(char c: rhs){
    //     if(c >= '0' && c <= '9'){r = r * 10 + (c-'0');}
    // }
    // int sum;
    // if(lneg == false && rneg == false){sum = l+r;}
    // else if(lneg == true && rneg == false){sum = r-l;}
    // else if(lneg == false && rneg == true){sum = l-r;}
    // else{sum = -l-r;}
    // //turn sum into string and return
    // string s = std::to_string(sum);
    // return s;

    string str_ans;
    int sum = 0;
    int carry = 0;

    if (lhs.at(0) == '-' && rhs.at(0) == '-')
    {
        lhs.erase(lhs.begin());
        lhs.insert(0,"0");
        rhs.erase(rhs.begin());
        rhs.insert(0,"0");
    //set to 0 rhs
    while (rhs.size() < lhs.size()){rhs.insert(0,"0");}
    //set to 0 lhs
    while (lhs.size() < rhs.size()){lhs.insert(0,"0");}    

    for (long unsigned int i = 1; i <= lhs.size(); i++){
        sum = carry + digit_to_decimal(lhs.at(lhs.size() - i)) + digit_to_decimal(rhs.at(rhs.size() - i));
        carry = sum / 10;
        str_ans.insert(str_ans.begin(), decimal_to_digit(sum % 10));
    }
    str_ans.insert(str_ans.begin(), '-');
    return trim_leading_zeros(str_ans);
    }
    
    lhs.insert(0,"0");
    rhs.insert(0,"0");
    //put 0's
    while (lhs.size() < rhs.size()){lhs.insert(0,"0");}
    while (rhs.size() < lhs.size()){rhs.insert(0,"0");}

    for (long unsigned int i = 1; i <= lhs.size(); i++)
    {
        sum = carry + digit_to_decimal(lhs.at(lhs.size() - i)) + digit_to_decimal(rhs.at(rhs.size() - i));
        carry = sum / 10;
        str_ans.insert(str_ans.begin(), decimal_to_digit(sum % 10));
    }

    return trim_leading_zeros(str_ans);






    // //find negative
    // bool lneg = false;
    // bool rneg = false;
    // if(lhs.at(0) == '-'){
    //     lhs.erase(0,1);
    //     lneg = true;
    //     }
    // if(rhs.at(0) == '-'){
    //     rhs.erase(0,1);
    //     rneg = true;
    //     }  
    // //trim leading 0
    // lhs = trim_leading_zeros(lhs);
    // rhs = trim_leading_zeros(rhs);
    // bool carry = false;
    // int carryval = 0;
    // int sum;
    // string value;
    // unsigned int smallerlen = lhs.length()-rhs.length();
    // for(int i = 0; i < smallerlen; i++){
    //     if(carry){carryval = 1;}
    //     else{carryval = 0;}
    //     carry = false;
    //     int l = digit_to_decimal(lhs[i]);
    //     int r = digit_to_decimal(rhs[i]);
    //     if(lneg == false && rneg == false){sum = l+r+carryval;}
    //     else if(lneg == true && rneg == false){sum = r-l+carryval;}
    //     else if(lneg == false && rneg == true){sum = l-r+carryval;}
    //     else{sum = -l-r+carryval;}
    //     if(sum < 9){value[i] = decimal_to_digit(sum);} //turn sum into string and put it into place of final value
    //     else{
    //         carry = true;
    //         value[i] = decimal_to_digit(sum % 10);
    //     }
    // return value;
    // }
}

string multiply(string lhs, string rhs) {
    // //find negative
    // bool lneg = false;
    // bool rneg = false;
    // if(lhs.at(0) == '-'){
    //     lhs.erase(0,1);
    //     lneg = true;
    //     }
    // if(rhs.at(0) == '-'){
    //     rhs.erase(0,1);
    //     rneg = true;
    //     }  
    // //trim leading 0
    // lhs = trim_leading_zeros(lhs);
    // rhs = trim_leading_zeros(rhs);
    // //turn into int
    // int l = 0;
    // for(char c: lhs){
    //     if(c >= '0' && c <= '9'){l = l * 10 + (c-'0');}
    // }
    // int r = 0;
    // for(char c: rhs){
    //     if(c >= '0' && c <= '9'){r = r * 10 + (c-'0');}
    // }
    // int prod;
    // if(lneg == false && rneg == false){prod = l*r;}
    // else if(lneg == true && rneg == false){prod = -1*r*l;}
    // else if(lneg == false && rneg == true){prod = -1*l*r;}
    // else{prod = l*r;}
    // //turn sum into string and return
    // string s = std::to_string(prod);
    // return s;
    

    //find negative

    int ct = 0;
    int deci1 = 0;
    int carry = 0;
    string output = "0";    

    if (lhs.at(0) == '-'){
        if(rhs.at(0) == '-'){
        lhs.erase(lhs.begin());
        rhs.erase(rhs.begin());

    while (lhs.length() < lhs.length() + rhs.length()){lhs.insert(0,"0");}
    while (rhs.length() < lhs.length() + rhs.length()){rhs.insert(0,"0");}

    
    for (long unsigned int i = 1; i <= rhs.length(); i++)
    {
        ct++;
        string s1;       
        for (int c = 1; c < ct; c++){
            s1.insert(0,"0");
        }
        for (long unsigned int a = 1; a <= lhs.length(); a++){
            deci1 = carry + (digit_to_decimal(lhs.at(lhs.length() - a)) * digit_to_decimal(rhs.at(rhs.length() - i)));
            carry = deci1 / 10;
            s1.insert(s1.begin(), decimal_to_digit(deci1 % 10));
        }
        output = add(s1, output);        
    }    
    return output;
    }
}

    if (rhs.at(0) == '-' && lhs.at(0) != '-')
    {
        string s1;
        rhs.erase(rhs.begin());
        while (lhs.length() < lhs.length() + rhs.length()){lhs.insert(0,"0");}
        while (rhs.length() < lhs.length() + rhs.length()){rhs.insert(0,"0");}
        int carry = 0;
        for (long unsigned int i = 1; i <= rhs.length(); i++){
            ct++;
            for (int c = 1; c < ct; c++){
                s1.insert(0,"0");
            }
            for (long unsigned int a = 1; a <= lhs.length(); a++){
                deci1 = carry + (digit_to_decimal(rhs.at(rhs.length() - i)) * digit_to_decimal(lhs.at(lhs.length() - a)));
                carry = deci1 / 10;
                s1.insert(s1.begin(), decimal_to_digit(deci1 % 10));
            }
            output = add(s1, output);            
        }
        output.insert(output.begin(), '-');
        return output;
    }

    if (lhs.at(0) == '-' && rhs.at(0) != '-'){
        string s1;
        lhs.erase(lhs.begin());

    while (lhs.length() < lhs.length() + rhs.length()){lhs.insert(0,"0");}
    while (rhs.length() < lhs.length() + rhs.length()){rhs.insert(0,"0");}

    for (long unsigned int i = 1; i <= rhs.length(); i++){
        ct++;        
        for (int c = 1; c < ct; c++){s1.insert(0,"0");}
        for (long unsigned int a = 1; a <= lhs.length(); a++){
            deci1 = carry + (digit_to_decimal(rhs.at(rhs.length() - i)) * digit_to_decimal(lhs.at(lhs.length() - a)));
            carry = deci1 / 10;
            s1.insert(s1.begin(), decimal_to_digit(deci1 % 10));
        }
        output = add(s1, output);        
    }
    output.insert(output.begin(), '-');
    return output;
    }


    while (lhs.length() < lhs.length() + rhs.length()){lhs.insert(0,"0");}
    while (rhs.length() < lhs.length() + rhs.length()){rhs.insert(0,"0");}
    for (long unsigned int i = 1; i <= rhs.length(); i++){
        string s1;
        ct++;
        for (int c = 1; c < ct; c++){
            s1.insert(0,"0");
        }
        for (long unsigned int a = 1; a <= lhs.length(); a++){
            deci1 = digit_to_decimal(rhs.at(rhs.length() - i)) * digit_to_decimal(lhs.at(lhs.length() - a)) + carry;
            carry = deci1 / 10;
            s1.insert(s1.begin(), decimal_to_digit(deci1 % 10));
        }
        output = add(s1, output);        
    }
    return output;
}


