#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>

void rotate(std::vector<int> &nums, int k){

    int step = k%nums.size();

    std::reverse(nums.begin(), nums.end());

    std::reverse(nums.begin(), nums.begin()+step);

    std::reverse(nums.begin()+step, nums.end());

}

int main(){

    std::vector<int>vec;

    int len = 1;

    for(int i=0; i<len; i++){
        vec.push_back((i*2) - 3);
    }

    std::cout<<"array: ";
    for(auto it = vec.begin(); it!=vec.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";


    int step = 3;

    rotate(vec, step);

    std::cout<<"modified array: ";
    for(auto it = vec.begin(); it!=vec.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";


    return 0;
}