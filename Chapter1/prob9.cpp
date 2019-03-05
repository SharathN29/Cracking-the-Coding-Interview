/*
* Cracking the coding interview, Chapter 1 Problem 9
* String Rotation: Assume you have a method isSubstring which checks ifone word is a substring of another. 
* Given two strings, 51 and 52, write code to check if 52 is a rotation of 51 using only one call to isSubstring.
* 
* Approach: 
* example s1 = "waterbottle", s2 = "erbottlewat", clearly s2 is rotation is s1
* lets say s1 = xy ==> wat + erbottle
* similarly s2 = yx ==> erbottle + wat
* Therefore s1s1 = "waterbottlewaterbottle", clearly s2 is substring of s1s1
* So if a string is formed by rotation of another string, it will always be substring of concatenated original string to itself.
*/

#include<iostream>
#include<string>

bool isRotation(std::string s1, std::string s2){
    size_t len1 = s1.length();
    size_t len2 = s2.length();
    if(len1 == 0 || len1 != len2)
        return false;

    std::string contactS1 = s1 + s1;
    if(contactS1.find(s2) != std::string::npos)
        return true;
    else 
        return false;
}

int main(){
    std::string s1, s2;
    std::cout<<"Enter string 1: ";
    std::cin>>s1;
    std::cout<<"Enter string 2: ";
    std::cin>>s2;
    if(isRotation(s1, s2))
        std::cout<<"Yes! " << s2 << " is rotation of " << s1 << std::endl;
    else 
        std::cout<<"No! " << s2 << " is not a rotation of " << s1 << std::endl;

    return 0;
}