#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>
#include <set>

int get_area(std::vector<std::vector<int>> & grid, int r, int c, int rows, int cols){

    if (r<0 || r>=rows || c<0 || c>=cols || grid[r][c]!=1){
        return 0;
    }

    grid[r][c]=2;


    int area = 0;

    area = 1 + get_area(grid, r-1, c, rows, cols) +
                get_area(grid, r+1, c, rows, cols) + 
                get_area(grid, r, c-1, rows, cols) + 
                get_area(grid, r, c+1, rows, cols);

    return area;
}

int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {

    int rows = grid.size();
    int cols = grid[0].size();
    int area = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            area = std::max(area, get_area(grid, i, j, rows, cols));
        }
        std::cout<<std::endl;
    }

    return area;
}

int main(){

    std::vector<std::vector<int>> grid {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                        {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                        {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                        {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                        {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                        {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                        {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                        {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    // std::vector<std::vector<int>> grid{{1,1,1},
    //                                     {1,1,0},
    //                                     {1,0,1}};


    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            std::cout << grid[i][j];
        }
        std::cout<<std::endl;
    }

    int area = maxAreaOfIsland(grid);

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            std::cout << grid[i][j];
        }
        std::cout<<std::endl;
    }

    std::cout<<"\narea: "<<area<<std::endl;



    return 0;
}