// TODO: Implement this source file
#include "MyString.h"
#include <iostream>

//constructor
MyString::MyString() : Size(0), Capacity(1), strar(new char[1])
{
    strar[0] = '\0';
}
//copy constructor
MyString::MyString(const MyString& str) : Size(str.size()), Capacity(str.capacity()), strar(new char[Capacity])
 {
    //set last to \0
    strar[Size] = '\0';
    //copy str to strar
    for(size_t i = 0; i < Size; i++)
    {
        strar[i] = str.strar[i];
    }     
 }
 //from c-string
 MyString::MyString(const char* s) : Size(0), Capacity(1), strar(nullptr)
 {
    if(s[0] == '\0')
    {
        Size = 0;
        Capacity = 1;
        strar = new char[Capacity];
    }
    else
    {
        size_t ct = 0;
        while(s[ct] != '\0')
        {
            ct++;
        }
        Size = ct;
        Capacity = Size+1;
        strar = new char[Capacity];
        for(size_t i = 0; i < Capacity; i++)
        {
            strar[i] = s[i];
        }
    }
    strar[Size] = '\0';
 }
 //destructor
 MyString::~MyString()
 {
    delete[] strar;
 }
// void MyString::GetSize() const{
//     std::cout << size;
// }

//resize
void MyString::resize(size_t n)
{
    char* orig = strar; //original string
    if(n >= Capacity)
    {
        Capacity = n; //        
        strar = new char[n];
        int ct = 0; //counter for new size
        for(size_t i = 0; i < n; i++)//
        {
            strar[i] = orig[i];
            ct++;
        }
        Size = ct;       
    }
}
size_t MyString::capacity() const//capacity
    {
        return Capacity;
    }

size_t MyString::size() const//size
    {
        return Size;
    }
size_t MyString::length() const//length
    {
        return Size;
    }
const char* MyString::data() const noexcept//data
    {
        return strar;
    }
bool MyString::empty() const//empty
    {
        if(strar[0] == '\0'){return true;}
        return false;        
    }

const char& MyString::front() const//front
{
    return strar[0];
}

const char& MyString::at(size_t index) const//at
{
    if(index >= Size)
    {
        throw std::out_of_range("index out of range");
    }
    else{return this->strar[index];}
}

void MyString::clear()//clear
{
    Size = 0;
    strar[0] = '\0';
}

ostream& operator<<(ostream& output, const MyString& str)//operator<<
{
    for(size_t i = 0; i < str.Size; i++)
    {
        output << str.strar[i];
    }
    return output;
}

MyString& MyString::operator=(const MyString& str)//operator=
{
    if(this == &str)
    {
        return *this;
    }
    delete[] strar;
    Size = str.Size;
    Capacity = str.Size+1;
    strar = new char[Capacity];
    size_t ct = 0;
    while(str.strar[ct] != '\0')
    {
        strar[ct] = str.strar[ct];
        ct++;
    }
    strar[Size] = '\0';
    return *this;
}

MyString& MyString::operator+=(const MyString& str)//operator+=
{
    size_t ct = str.Size;
    size_t orsize = ct + Size + 1;
    char* temp = new char[orsize];
    int ind = 0;
    for(size_t i = 0; i < Size; i++)
    {
        if(strar[i] != '\0')
        {
            temp[i] = strar[i];
        }
    }
    while(str.strar[ind] != '\0')
    {
        temp[ind+Size] = str.strar[ind];
        ind++;
    }
    Size = orsize-1;
    temp[Size] = '\0';
    Capacity = orsize;
    delete[] strar;
    strar = temp;
    return *this;
}

size_t MyString::find(const MyString& str, size_t pos) const noexcept
{
    bool eq = false;
    for(size_t i = pos; i < Size; i++)
    {
        if(strar[i] == str.strar[0])
        {
            for(size_t j = 0; j < str.Size;j++)
            {
                if(strar[i+j] != str.strar[j])
                {
                    eq = false;
                    break;
                }
                else{eq = true;}
            }
            if(eq){return i;}
        }
    }
    return -1;
}

bool operator==(const MyString& lhs, const MyString& rhs) noexcept
{
    if(lhs.size() == rhs.size() && lhs.capacity() == rhs.capacity())
    {
        for(size_t i = 0; i < lhs.size(); i++)
        {
            if(lhs.strar[i] != rhs.strar[i])
            {
                return false;
            }
        }
        return true;
    }
    else{return false;}
}

