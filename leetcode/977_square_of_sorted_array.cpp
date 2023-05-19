#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>

std::vector<int> soretdSquares(std::vector<int> &nums){

    std::vector<int>result;
    for (auto it=nums.begin(); it!=nums.end(); it++){
        result.push_back((*it)*(*it));
    }

    std::sort(result.begin(), result.end());

    return result;
    
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



    std::vector<int>result = soretdSquares(vec);
    // for (auto it=vec.begin(); it!=vec.end(); it++){
    //     result.push_back((*it)*(*it));
    // }

    // std::sort(result.begin(), result.end());


    std::cout<<"result: ";
    for(auto it = result.begin(); it!=result.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";



    return 0;
}