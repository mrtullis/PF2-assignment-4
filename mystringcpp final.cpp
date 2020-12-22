/* 
author Michael Tullis 
Date 10/27/2020
main file for mystring adapted from lab for homework 4
*/

#include "mystring.h"

// default constructor
Mystring::Mystring() 
{
    ptr_buffer  = new char[1];
    *ptr_buffer = '\0';
    buf_size    = 1;
    len         = 0;
}

// constructor from c-style string or "abc"
Mystring::Mystring(const char * s) 
{
    len        = strlen(s);
    buf_size   = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, s);

}

// copy constructor to be implemented
Mystring::Mystring(const Mystring& orig) 
{
    len = orig.length();
    ptr_buffer = new char[len + 1];
    buf_size = len + 1;
   strcpy(ptr_buffer,orig.ptr_buffer);
} 
void Mystring::reserve(size_type n){
    if(buf_size >= n)
        return;
    buf_size = n;
    char *temp = ptr_buffer;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, temp);
    delete[] temp;
}
// one of the over loaded assignment operator if you have time
Mystring& Mystring::operator=(const Mystring& orig)
{
    if(this != &orig)
    {
    delete [ ] ptr_buffer;
    ptr_buffer = new char[strlen(orig.ptr_buffer) + 1];
    strcpy( ptr_buffer, orig.ptr_buffer );
    len = orig.length();
    }
    return *this;
}
 Mystring& Mystring::operator=(const char * orig){
 delete [] ptr_buffer;
    len = strlen(orig);
    ptr_buffer = new char[strlen(orig) + 1];
    strcpy (ptr_buffer, orig);

    return *this;
 } 
 // overloading the ==
bool operator==(const char * left, const Mystring& right)
{
    return (strcmp(left, right.c_str()) == 0);
}
bool operator==(const Mystring& left, const Mystring& right)
{
    return (strcmp(left.c_str(), right.c_str()) == 0);
}
bool operator==(const Mystring& left, const char * right)
{
    return (strcmp(left.c_str(), right) == 0);
}
// overloading the !=
bool operator!=(const char * left, const Mystring& right)
{
    return (strcmp(left, right.c_str()));
}
bool operator!=(const Mystring& left, const Mystring& right)
{
    return (strcmp(left.c_str(), right.c_str()));
}
bool operator!=(const Mystring& left, const char * right)
{
    return (strcmp(left.c_str(), right));
}
// array notation 
char Mystring::operator[](size_type pos) const{
    return *(ptr_buffer + pos);
}
char& Mystring::operator[](size_type pos){
    return *(ptr_buffer + pos);
}
// overloading the +=
Mystring& Mystring::operator+=(const Mystring& str){
    len = len + str.len;
    reserve(len);
    strcat(ptr_buffer , str.ptr_buffer);
    return *this; 
}
Mystring& Mystring::operator+=(const char * str){
    len = len + strlen(str);
    reserve(len);
    strcat(ptr_buffer, str);
    return *this;
}
// append is up now
Mystring& Mystring::append(const Mystring& str){
    len = len + str.len;
    reserve(len);
    strcat(ptr_buffer, str.ptr_buffer);
    return *this;
 }
 
 Mystring& Mystring::append(const char * str){
    len = len + strlen(str);
    reserve(len);
    strcat(ptr_buffer, str);
    return *this; 
 }
 // insert
 Mystring& Mystring::insert(size_type pos, const Mystring& str){
    len = len + str.len;
    reserve(len);
    Mystring temp = ptr_buffer + pos;
    strcpy(ptr_buffer + pos, str.c_str());
    append(temp);
    return *this;
 }
 Mystring& Mystring::insert(size_type pos, const char * str){
    len = len + strlen(str);
    reserve(len);
    Mystring temp = ptr_buffer + pos;
    strcpy(ptr_buffer + pos, str);
    append(temp);
    return *this;
 }
 //replace 
 Mystring& Mystring::replace(size_type start, size_type span, const Mystring& str){
    len = len + str.len;
    reserve(len);
    Mystring temp(ptr_buffer + start + span);
    strcpy(ptr_buffer + start, str.ptr_buffer);
    append(temp);
    return *this;
 }
 Mystring& Mystring::replace(size_type start, size_type span, const char * str){
    len = len + strlen(str);
    reserve(len);
    Mystring temp(ptr_buffer + start + span);
    strcpy(ptr_buffer + start, str);
    append(temp);
    return *this;
 }
 //find first of
 Mystring::size_type Mystring::find_first_of (const char* s, size_type pos, size_type n) const{
      for(size_t i = pos; i < n; i++) {
        for(size_t j = 0; j < strlen(s); j++) {
            if(*(ptr_buffer + i) == *(s + j))
                return i;
        }
    }
    return npos;
 }
 // find last not of
 Mystring::size_type Mystring::find_last_not_of (const char* s, size_type pos) const{
    bool inthere = false;   
     if(pos >= len)
     pos = len;
     
    for(size_t i = pos ; i > 0; i--) {
        inthere = false; 
        for(size_t j = 0; j < strlen(s); j++) {
            if(*(ptr_buffer + i) == *(s + j))
                inthere = true;
        }
        if(inthere){
            return (i-1);
        }
    }
    return npos;
 }
// overloading the +
Mystring operator+(const Mystring& first, const Mystring& second){
    Mystring holder = first;
    holder.append(second);
    return holder;
} 
//push back 
void Mystring::push_back(char c){
    buf_size++;
    reserve(buf_size);
    ptr_buffer[len] = c;
    len++;
}
//clear 
void Mystring::clear(){
    delete[] ptr_buffer;
    ptr_buffer = new char[1];
    *ptr_buffer = '\0';
    len = 0;
    buf_size = 1;
}
// some simple methods implemented for you
 Mystring::size_type Mystring::size() const 
 {
     return len;
 }
 
 Mystring::size_type Mystring::length() const
 {
     return len;
 }
 
 Mystring::size_type Mystring::capacity() const
 {
       return buf_size;
 }
 
 Mystring::size_type Mystring::max_size() const
 {
       return (int)pow(2,30) -4 ;
 }
 
// Destructor
Mystring::~Mystring() 
{
    delete [] ptr_buffer;
}

// Provided for the lab so we may cout mystring
ostream& operator<<(ostream& out, const Mystring& str) 
{
    out << str.c_str();
    return out;
}

// implemented for the lab to support the implementation of <<
const char * Mystring::c_str() const 
{
    return ptr_buffer;
}