#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>

std::string reverseWords(std::string s) {

    int l = 0;
    int r = 0;

    while (l<s.size()){
        while(r<s.size() && s[r]!=' '){
            r++;
        }

        std::reverse(s.begin()+l, s.begin()+r);

        l=r+1;
        r=r+1;
    }

    return s;
        
}

int main(){

    std::string s = "Let's take LeetCode contest";

    std::cout<<s.size()<<std::endl;

    int count = 0;

    for (auto it = s.begin();it!=s.end(); it++){
        std::cout<<*it;
    }
    std::cout<<std::endl;

    s = reverseWords(s);

    for (auto it = s.begin();it!=s.end(); it++){
        std::cout<<*it;
    }
    std::cout<<std::endl;
    return 0;
}