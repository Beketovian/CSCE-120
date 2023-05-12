// TODO: Implement this header file
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
using namespace std;
class MyString
{
    public:
        MyString();//constructor
        MyString(const MyString& str); //copy constructor
        MyString(const char* s);//from c-string constructor
        ~MyString(); //destructor

        void resize(size_t n); //resize
        size_t capacity() const; //capacity
        size_t size() const; //size
        size_t length() const; //length
        const char* data() const noexcept; //data
        bool empty() const; //empty
        const char& front() const;//front
        const char& at(size_t index) const;//at
        void clear();//clear
        friend ostream& operator<<(ostream& output, const MyString& str);//operator<<
        MyString& operator=(const MyString& str);//operator=
        MyString& operator+=(const MyString& str);//operator+=
        size_t find(const MyString& str, size_t pos = 0) const noexcept;//find

        //EC ---------------
        bool friend operator==(const MyString& lhs, const MyString& rhs) noexcept;//operator==
        //operator+




        // void GetSize() const;
    

    private:
        size_t Size;
        size_t Capacity;
        char* strar;


};
#endif 