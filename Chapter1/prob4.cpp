#include<iostream>

int getCharIndex(char c){
    int idx = -1;
    if(c >= 'a' && c <= 'z')
        idx = c - 'a';
    else if (c >= 'A' && c <= 'Z')
        idx = c - 'A';
        
    return idx;
}

void countFrequency(const std::string & str, int *frequency){
    int idx;
    for(const char & c : str){
        idx = getCharIndex(c);
        if(idx != -1)
            ++frequency[idx];
    }
}

bool isPermutationOfPalindrome(const std::string & str){
    int frequency[26] = {0};
    countFrequency(str, frequency);

    bool oddStringAppeared = false;
    std::cout<<std::endl;

    for(int i = 0; i < 26; i++){
        if(frequency[i] % 2 && oddStringAppeared)
            return false;
        else if(frequency[i] % 2 && !oddStringAppeared)
            oddStringAppeared = true;
    }
    return true;
}

int main(){
    std::string str("Tact Coa");
    std::cout<<isPermutationOfPalindrome(str)<<std::endl;

    std::string str1("A big cat");
    std::cout<<isPermutationOfPalindrome(str1)<<std::endl;
}