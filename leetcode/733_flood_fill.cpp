#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>
#include <set>

std::vector<std::vector<int>> fill(std::vector<std::vector<int>>& image, int sr, int sc, int color, int source_color) {

        int rows = image.size();
        int cols = image[0].size();

        if (sr<0 || sr>=rows || sc<0 || sc>=cols || image[sr][sc]!=source_color){
            return image;
        }

        image[sr][sc] = color;

        fill(image, sr-1, sc, color, source_color);
        fill(image, sr+1, sc, color, source_color);
        fill(image, sr, sc-1, color, source_color);
        fill(image, sr, sc+1, color, source_color);    

        return image;
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) {
        
        int source_color = image[sr][sc];
        if (image[sr][sc]==color){
            // do nothing
            return image;
        }
        else {
            fill(image, sr, sc, color, source_color);
        }

        return image;
}



int main(){

    // std::vector<std::vector<int>> image{{1,1,1,1},
    //                                     {1,1,0,1},
    //                                     {1,0,1,1}};

    std::vector<std::vector<int>> image{{1,1,1},
                                        {1,1,0},
                                        {1,0,1}};

    std::cout<<image.size()<<std::endl;
    std::cout<<image[1][2]<<std::endl;

    std::vector<std::vector<int>> new_image = floodFill(image, 1, 1, 3);

    std::cout<<"done"<<std::endl;

    for (int i = 0; i < new_image.size(); i++)
    {
        for (int j = 0; j < new_image[i].size(); j++)
        {
            std::cout << new_image[i][j];
        }
        std::cout<<std::endl;
    }



    return 0;
}