// Programming Technique II

//? EXERCISE 3: STRING MANIPULATIONS
//? file: custom_string.cpp

//!----------------------------------------------------------------------------------------
//! This is the only file that you will need to modify in this exercise.
//! Also, you will submit only this file.
//! This file is the implementation for the class CustomString.
//!----------------------------------------------------------------------------------------

// Member 1's Name: LUBNA AL HAANI BINTI RADZUAN (A23CS0107)
// Member 2's Name: NUR FIRZANA BINTI BADRUS HISHAM (A23CS0156)
// Section : 03
// Link Video : https://drive.google.com/drive/folders/1nW9FEKLC4C4IQxaJGmlvS97jjwAo4Zws?usp=sharing 

#include <iostream>
#include <string>
using namespace std;

#include "custom_string.hpp"

//?----------------------------------------------------------------------------------------
//? The following methods are fully given: a constructor, getData() and setData()
//?----------------------------------------------------------------------------------------

CustomString::CustomString(const string &_data) : data(_data) {}
string CustomString::getData() const { return data; }
void CustomString::setData(const string &_data) { data = _data; }

//! Task 1: Complete the implementation of the following mutator methods:
//!        (a) pushFront()
//!        (b) pushBack()
//!        (c) pop()
//!        (d) popFront()
//!        (e) popBack()

void CustomString::pushFront(const string &s)
{
    data.insert(0, s); 
}

void CustomString::pushBack(const string &s)
{
    data.append(s);
}

string CustomString::pop(int index, int count)
{
    string s = data.substr(index, count);
    data.erase(index, count);
    return s;
}

string CustomString::popFront(int count)
{
    string s = data.substr(0, count);
    data.erase(0, count);
    return s;
}

string CustomString::popBack(int count)
{                                      
    int c = data.size() - count;
    string s = data.substr(c, count);
    data.erase(c, count);
    return s;
}

//! Task 2: Complete the implementation of the following overloaded operators:
//!        (a) operator !
//!        (b) operator *

CustomString CustomString::operator!() const
{
    string s;
    for (int i = (data.length() - 1); i >= 0; i--)
    {
        s += data[i];
    }
    return CustomString(s);
}

CustomString CustomString::operator*(int count) const
{
    string s;
    for(int i = 0; i < count; i++)
    {
        s += data;
    }
    return CustomString(s);
}

//! Task 3: Complete the implementation of the following conversion methods:
//!        (a) toDouble()
//!        (b) toUpper()

double CustomString::toDouble() const
{
    return stod(data);
}

CustomString CustomString::toUpper() const
{
    string s;
    for(int i = 0; i < data.length(); i++)
    {
        s += toupper(data[i]);
    }
    return CustomString(s);
}