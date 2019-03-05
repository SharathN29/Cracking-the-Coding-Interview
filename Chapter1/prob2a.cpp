// Check Permutation - Given two strings, write a method to decide whether if one is a permutation of the other 

#include<iostream>
using namespace std;

bool permutation(string s, string t){
    if(s.length() != t.length())
        return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s==t;
}

int main(){
    string s = "god";
    string t = "dog";
    bool res = permutation(s,t);
    cout<<res<<endl;
}