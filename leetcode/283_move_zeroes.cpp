#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>

void moveZeroes(std::vector<int>& nums) {

    int len = nums.size();

    int count = 0;
    int i = 0;

    for (i=0;i<len;i++){
        if (nums[i]!=0){
            nums[count++] = nums[i];
        }
    }

    int num_zeroes = len - count;

    for (i=count;i<len;i++){
        nums[i]=0;
    }

}

int main(){

    std::vector<int>vec;

    int len = 10;

    for(int i=0; i<len; i++){
        vec.push_back((i*2));
    }

    // vec.insert(vec.begin(), 0);
    vec.insert(vec.begin(), 0);
    // vec.insert(vec.begin()+2, 0);
    vec.insert(vec.begin()+7, 0);
    vec.insert(vec.end(), 0);

    std::cout<<"array: ";
    for(auto it = vec.begin(); it!=vec.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";

    moveZeroes(vec);

    std::cout<<"modified array: ";
    for(auto it = vec.begin(); it!=vec.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";

    return 0;
}