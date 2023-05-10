#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>

bool isBadVersion(int version){
    if (version>=4){
        return true;
    }
    else return false;
}

int firstBadVersion(int n){
    bool is_bad = false;
    int low_version = 0;
    int high_version = n;

    if (high_version == 1 && isBadVersion(high_version)==true){
        return high_version;
    }
    while(low_version<=high_version){
        int mid_version = (low_version + high_version) / 2;


        // else if (high_version == 1 && isBadVersion(hi))

        if (isBadVersion(mid_version)==true && isBadVersion(mid_version-1)==false){
            return mid_version;
        }

        if (!isBadVersion(mid_version)){
            low_version = mid_version + 1;
        }
        else if (isBadVersion(mid_version)){
            high_version = mid_version -1 ;
        }

    }
    return -1;
    
}

int main(){

    int bad_version = firstBadVersion(10);
    std::cout<<bad_version<<std::endl;


return 0;

 
}