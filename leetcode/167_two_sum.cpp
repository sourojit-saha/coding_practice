#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>

std::vector<int>twoSum(std::vector<int>&numbers, int target){
    int left_idx = 0;
    int right_idx = numbers.size()-1;
    int sum = 0;
    std::vector<int>result;

    while(left_idx<right_idx){
        sum = numbers[left_idx]+numbers[right_idx];

        if (sum>target){
            right_idx--;
        }
        else if (sum<target){
            left_idx++;
        }

        else if (sum == target){
            result.push_back(left_idx+1);
            result.push_back(right_idx+1);
            break;
        }
    };

    return result;

}

int main(){

    std::vector<int>vec;

    int len = 10;

    for(int i=0; i<len; i++){
        vec.push_back((i*2)-3);
    }

    std::cout<<"array: ";
    for(auto it = vec.begin(); it!=vec.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";

    int target = 8;

    std::vector<int> result = twoSum(vec, target);

    std::cout<<"index: ";
    for(auto it = result.begin(); it!=result.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";

    

    return 0;
}