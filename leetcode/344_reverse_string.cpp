#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>

void reverseString(std::vector<char>&s){
    std::reverse(s.begin(), s.end());
}

int main(){

    std::vector<char>s = {'h', 'e', 'l', 'l', 'o'};

    std::cout<<"string: ";
    for(auto it = s.begin(); it!=s.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;

    reverseString(s);

    std::cout<<"reverse: ";
    for(auto it = s.begin(); it!=s.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
    return 0;
}