// Prob1: Determine whether a string has all unique characters 
// Auth: Sharath Nagendra, Date: 02/21/19

#include<iostream>
using namespace std; 

bool isUniqueCharacters(string str){
	if(str.length() > 128)
		return false;

	bool char_set[128];
	for(int i=0; i<str.length(); i++){
		int val = str.at(i);
		if(char_set[val]){
			return false;
		}
		char_set[val] = true;
	}
	return true;
}

int main(){
	string str = "ball";
	bool res = isUniqueCharacters(str);
	cout<<res<<endl;
	return 0;
}
