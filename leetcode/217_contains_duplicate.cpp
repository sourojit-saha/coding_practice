#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>

bool containsDuplicate(std::vector<int>nums){
    std::sort(nums.begin(), nums.end());
    for(auto it = nums.begin(); it+1!=nums.end(); it++){
        // std::cout<<*it<<" "<<*(it+1)<<std::endl;
        if(*it == *(it+1)){
            return 1;
        }
    }
    return 0;

}

int main(){

    std::vector<int>vec;

    int len = 10;

    for(int i=0; i<len; i++){
        vec.push_back((i*2) - 3);
    }

    vec.push_back(10);
    vec.push_back(5);
    std::cout<<"array: ";
    for(auto it = vec.begin(); it!=vec.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";

    std::sort(vec.begin(), vec.end());

    std::cout<<"sorted array: ";
    for(auto it = vec.begin(); (it)!=vec.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";

    bool result = containsDuplicate(vec);

    std::cout<<result<<std::endl;



    return 0;
}