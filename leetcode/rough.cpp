#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>
#include <set>

void rotate(std::vector<int> &nums, int k){

    int step = k%nums.size();

    std::reverse(nums.begin(), nums.end());

    std::reverse(nums.begin(), nums.begin()+step);

    std::reverse(nums.begin()+step, nums.end());

}

int main(){

    std::set<std::pair<int, int>> visited;



    return 0;
}