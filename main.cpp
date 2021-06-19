#include <iostream>
#include <vector>
#include <stack>

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
                    auto [x,y] = stack.top();
                    stack.pop();
                    world[x][y] = 0;
                    if(x < world.size()-1 && world[x+1][y] == 1) {
                        stack.push({x+1, y});
                    }
                    if(x > 0 && world[x-1][y] == 1) {
                        stack.push({x-1, y});
                    }
                    if(y < world[i].size()-1 && world[x][y+1] == 1) {
                        stack.push({x, y+1});
                    }
                    if(y > 0 && world[x][y-1] == 1) {
                        stack.push({x, y-1});
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
