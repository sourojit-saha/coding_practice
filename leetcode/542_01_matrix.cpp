#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

void print_matrix(std::vector<std::vector<int>>mat){
    for (int i = 0; i < mat.size(); i++){

        for (int j = 0; j < mat[i].size(); j++)
        {
            std::cout << mat[i][j];
        }
        std::cout<<std::endl;
    }
}

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {

    int rows = mat.size();
    int cols = mat[0].size();

    int row_dir[] = {-1, 0, 1, 0};
    int col_dir[] = {0, -1, 0, 1};

    std::vector<std::vector<int>> vis(rows, std::vector<int>(cols, 0));
    std::vector<std::vector<int>> dist(rows, std::vector<int>(cols, 0));

    std::queue<std::pair<std::pair<int, int>, int>> q;

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){

            if (mat[i][j]==0){
                vis[i][j]=1;
                q.push({{i,j}, 0});

            }

            else{
                vis[i][j]=0;
            }

        }
    }

    while (!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;

        q.pop();

        dist[row][col] = steps;

        for (int i=0; i<4; i++){
            int nrow = row + row_dir[i];
            int ncol = col + col_dir[i];

            if (nrow>=0 && nrow<rows && ncol>=0 && ncol<cols && vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                q.push({{nrow, ncol}, steps+1});
            }
        }
    }







    print_matrix(vis);

    std::cout<<std::endl;

    print_matrix(dist);

    return dist;
    
}



int main(){

    std::vector<std::vector<int>> mat;
    mat.push_back({0,0,0});
    mat.push_back({0,1,0});
    mat.push_back({1,1,1});

    // print_matrix(mat);

    updateMatrix(mat);

    // for (int i = 0; i < mat.size(); i++)
    // {
    //     for (int j = 0; j < mat[i].size(); j++)
    //     {
    //         std::cout << mat[i][j];
    //     }
    //     std::cout<<std::endl;
    // }

    return 0;
}