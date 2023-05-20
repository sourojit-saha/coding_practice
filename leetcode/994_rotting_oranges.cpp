#include <iostream>
#include <math.h>
#include <ctime>
#include <array>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

// 0 = empty cell
// 1 = fresh orange
// 2 = rotten orange

void print_matrix(std::vector<std::vector<int>>mat){
    for (int i = 0; i < mat.size(); i++){

        for (int j = 0; j < mat[i].size(); j++)
        {
            std::cout << mat[i][j];
        }
        std::cout<<std::endl;
    }
}

std::queue<std::pair<int, int>> get_rotten(std::vector<std::vector<int>>&grid){
    int rows = grid.size();
    int cols = grid[0].size();

    std::queue<std::pair<int, int>>rotten_q;

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            if (grid[i][j]==2){
                rotten_q.push({i, j});
            }
        }
    }

    return rotten_q;
}

int get_fresh(std::vector<std::vector<int>>&grid){
    int rows = grid.size();
    int cols = grid[0].size();
    int num_fresh = 0;

    std::queue<std::pair<int, int>>rotten_q;

    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            if (grid[i][j]==1){
                num_fresh++;
            }
        }
    }

    return num_fresh;
}

std::pair<bool, int> update_grid(std::vector<std::vector<int>>& grid, std::queue<std::pair<int, int>>rotten_q){
    
    int rows = grid.size();
    int cols = grid[0].size();
    
    int row_dir[] = {-1, 1, 0, 0};
    int col_dir[] = {0, 0, -1, 1};

    int num_fresh = get_fresh(grid);
    bool updated = 0;

    while(!rotten_q.empty()){
        int r = rotten_q.front().first;
        int c = rotten_q.front().second;

        rotten_q.pop();

        for (int k=0; k<4; k++){
            int new_row = r + row_dir[k];
            int new_col = c + col_dir[k];

            if (new_row>=0 && new_col>=0 && new_row<rows && new_col<cols && grid[new_row][new_col]==1){
                grid[new_row][new_col]=2;
                updated = 1;
                num_fresh--;
            }
        }
    }

    return {updated, num_fresh};
}

int orangesRotting(std::vector<std::vector<int>>& grid) {

    int rows = grid.size();
    int cols = grid[0].size();

    int row_dir[] = {-1, 1, 0, 0};
    int col_dir[] = {0, 0, -1, 1};

    bool updated = 1;
    int count = 0;
    std::pair<bool, int>status;
    std::queue<std::pair<int, int>>rotten_q;

    while (updated){
        rotten_q = get_rotten(grid);
        status = update_grid(grid, rotten_q);
        updated = status.first;
        count++;
    }

    if (status.second){
        return -1;
    }
    
    return count-1;
}

int main(){

    std::vector<std::vector<int>> grid {{2,1,1},
                                        {1,1,0},
                                        {0,0,1}};

    // std::vector<std::vector<int>> grid {{1}};

    
    print_matrix(grid);

    int time = orangesRotting(grid);

    std::cout<<"----"<<std::endl;

    print_matrix(grid);

    std::cout<<"----"<<std::endl;
    std::cout<<"time: "<<time<<std::endl;

    return 0;
}