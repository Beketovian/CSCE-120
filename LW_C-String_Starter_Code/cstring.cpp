#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
  int len = 0;
  while(str[len] != '\0'){
    len++;
  }
  // returns the length of the string including zero (0)
  return len;
}

unsigned int find(char str[], char character) {
  // returns 
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found
  for(unsigned int i = 0; i < length(str);i++){
    if(str[i]==character){return i;}
  }
  return length(str);
}

bool equalStr(char str1[], char str2[]) {
  // returns true if they are equal and false if they are not
  unsigned int ct = 0;
  while(ct < length(str1) && ct < length(str2)){
    if(str1[ct] != str2[ct]){
      return false;
    }
    ct++;
  }
  return true;
}