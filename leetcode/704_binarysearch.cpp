#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>

int binary_search(std::vector<int> vec, int target){

    int low_idx = 0;
    int high_idx = vec.size()-1;

    while(low_idx<=high_idx){
        int mid_idx = (low_idx + high_idx) / 2;

        if (vec[mid_idx]==target){
            return  mid_idx;
        }
        else if (vec[mid_idx]<target){
            low_idx = mid_idx + 1;
        }
        else {
            high_idx = mid_idx - 1;
        }
    } 
    return -1;
}


int main(){

    std::vector<int> vec;

    int target = 3;

    int len = 10;

    for(int i=0; i<len; i++){
        vec.push_back((i*2) + 3);
    }
    std::cout<<"array: ";
    for(auto it = vec.begin(); it!=vec.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<"\n";

    int idx = binary_search(vec, target);

    std::cout<<idx<<std::endl;

    return 0;

 
}