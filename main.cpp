#include <iostream>
#include <vector>
#include <stack>

// 0 0 0 1 1 1 0 1 0
// 0 0 0 1 0 1 0 0 1
// 0 1 0 1 1 1 0 0 0
// 0 1 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// 0 1 1 0 0 0 0 0 1
// 0 1 1 0 0 0 0 1 1

int counter_isle(std::vector<std::vector<int > > world){
    int counter = 0;
    for(int i = 0; i < world.size(); i++) {
        for(int j = 0; j < world[i].size(); j++) {
            if(world[i][j] == 1) {
                counter++;
                std::stack<std::pair<int,int>>stack;
                stack.push({i, j});
                while(!stack.empty()) {
                    auto pair = stack.top();
                    stack.pop();
                    world[pair.first][pair.second] = 0;
                    if(pair.first < world.size()-1 && world[pair.first+1][pair.second] == 1) {
                        stack.push({pair.first+1, pair.second});
                    }
                    if(pair.first > 0 && world[pair.first-1][pair.second] == 1) {
                        stack.push({pair.first-1, pair.second});
                    }
                    if(pair.second < world[i].size()-1 && world[pair.first][pair.second+1] == 1) {
                        stack.push({pair.first, pair.second+1});
                    }
                    if(pair.second > 0 && world[pair.first][pair.second-1] == 1) {
                        stack.push({pair.first, pair.second-1});
                    }
                }
            }
        }
    }
    return counter;
}

int main()
{
    std::vector<std::vector<int > > srcWorld {
        {0, 0, 0, 1, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0, 1, 0, 0, 0},
        {0, 1, 1, 1, 1, 1, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0, 0, 1},
        {0, 1, 1, 0, 0, 0, 0, 1, 1},
    };
    std::cout << "count isle = " << counter_isle(srcWorld) << std::endl;
    return 0;
}
