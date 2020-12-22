/* 
author Michael Tullis 
Date 10/27/2020
tester file for homework 4 slightly modified from original
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include "mystring.h"

#define string Mystring

using namespace std;

/*
 * Check function from the previous lab
 */
void check (const string s, const string name)
{
    cout << "checking " << name << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl << endl;
}

int main() 
{
 
    string s1("Hello, World!");
    string s1name("s1");
    check(s1, s1name);    
    
    cout << "---Testing assignment operator and == operator---\n";    
    string s2;
    s2=s1 ;
    string s2name("s2");
    check(s2,s2name);
    check(s1, s1name); 
    if(s1== s2)
        cout << "s1 and s2 are same string" << endl;
    
    string s3("Hi");
    check(s3,"s3");
    s3 = "Hey";
    check(s3,"s3");
    cout << s3 << endl; 
    if(s3 != "Hey")
        cout << "your assignment operator is wrong" << endl;
    else
        cout << "assignment operator is correct" << endl;
    cout << "--------------------------------------\n\n" ;  
    
    cout << "---Testing Push Back---\n";
    s2.push_back('?');
    check(s2,s2name);
    cout << "--------------------------------------\n\n" ;  
    
    cout << "---Testing array notation---\n";
    cout << "second char of s1: "<< s1[1] << endl;
    cout << "--------------------------------------\n\n" ;  
    
     
    cout << "---Testing += operator ---\n";
    s2 += s1;
    cout << "s2 after += s1: "<< s2 << endl;
    s3 += " you";
    cout << s3 << endl;           
    cout << "--------------------------------------\n\n" ;  
    
    
    cout << "---Testing append ---\n";
    s2.append("??");
    cout << "s2 after append s1: "<< s2 << endl;
    check(s2,"s2");
    cout << "--------------------------------------\n\n" ; 
    
    
    cout << "---Testing insert ---\n";
    s2.insert(6, "c++");
    cout << "s2 after insert: "<< s2 << endl;
    cout << "--------------------------------------\n\n" ;   
     
    
    cout << "---Testing replace ---\n";
    s2.replace(6, 7, "code");
    cout << "s2 after replace: "<< s2 << endl;
    cout << "--------------------------------------\n\n" ; 
    
   
    cout << "---Testing find_first_of ---\n";
    cout << "s2 find first of aeiou after index 2: " << s2.find_first_of("aeiou", 2, 7);
    cout << "--------------------------------------\n\n" ; 
    
    check(s1, s1name); 
    cout << "---Testing find_last_not_of ---\n";
    cout << "s1: " << s1.length() << endl;
    cout << "s1 find find_last_not_of !? after index 2: " << s1.find_last_not_of("!?");
    cout << "--------------------------------------\n\n" ;
    
    
    cout << "---Testing + ---\n";
    s3 = s1 + s2;
    cout << s3 << endl;
    cout << "--------------------------------------\n\n" ;
    
  //  myfile.close(); 
          
    return 0;
}