#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>
#include <set>

int lengthOfLongestSubstring(std::string s){

    std::cout<<s<<std::endl;
    // std::set<char> char_set;
    int lptr = 0;
    int rptr = 0;
    int len = s.size();
    int res = 0;
    std::vector<char> char_vect;

    bool duplicate = 0;

    while (rptr<len){
        
        auto pos = std::find(char_vect.begin(), char_vect.end(), s[rptr]);
        // auto pos = std::find(s.begin(), s.end(), s[rptr]);
        // std::cout<<"pos: "<<pos::std::endl;
        duplicate = pos != char_vect.end();

        if (!duplicate){
            std::cout<<"New: "<<s[rptr]<<" Adding: "<<s[rptr]<<std::endl;
            char_vect.push_back(s[rptr]);
            rptr++;
            res = std::max(res, rptr - lptr);
        }

        else if (duplicate){
            std::cout<<"Duplicate: "<<s[rptr]<<" Erasing: "<<*char_vect.begin()<<std::endl;
            char_vect.erase(char_vect.begin());
            lptr++;
        }


        std::cout<<"array: ";
        for(auto it = char_vect.begin(); it!=char_vect.end(); it++){
            std::cout<<*it<<" ";
        }
        std::cout<<"\n---"<<std::endl;

    }

        return res;
    }



int main(){

    std::string s = "abcabcbb";
    // std::string s = "sourujit";

    int res = lengthOfLongestSubstring(s);    

    std::cout<<res<<std::endl;

    return 0;
}