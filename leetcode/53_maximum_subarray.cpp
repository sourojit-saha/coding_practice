#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>

int max_SubArray(std::vector<int>nums){
    int sum = nums[0];
    int result = nums[0];

    for (int i = 1; i<nums.size(); i++){
        sum = std::max(sum, sum+nums[i]);

        if (sum>result){
            result = sum;
        }
    }

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

    // int sum = vec[0];
    // int result = vec[0];

    // for (int i=1; i<vec.size(); i++){
    //     sum = std::max(sum, sum+vec[i]);

    //     if (sum>result){
    //         result = sum;
    //     }
        
    // }

    int result = max_SubArray(vec);

    std::cout<<result<<std::endl;

    return 0;
}