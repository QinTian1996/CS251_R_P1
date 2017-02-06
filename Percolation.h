#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Percolation {

public:

    std::vector<int> grid;
    int n;

     Percolation(int n) {
        this->n = n;
        int i = 0;
        int total = n * n;
        while(i++ < total) {
            grid.push_back(0);
        }
    }

    void open(int x, int y) {
        if(y < 0 || x < 0 || x >= n || y >= n) {
            return;
        }
        grid[tr(x,y)] = 1;
    }

    bool isOpen(int x, int y) {
        if(y < 0 || x < 0 || x >= n || y >= n) {
            return 0;
        }
        return grid[tr(x,y)];
    }

    bool isFull(int x, int y) {
        if(y < 0 || x < 0 || x >= n || y >= n) {
            return 0;
        }
        return grid[tr(x,y)] == 2;
    }

    int tr(int x, int y) {
        return (n - 1 - x) * n + y;
    }
    bool rec(int x, int y) {

        grid[tr(x,y)] = 2;

        if(x == 0) return true;

        if(x < n-1 && grid[tr(x+1,y)] == 1) {
            bool up = rec(x+1, y);
            if(up) return up;
        }

        if(x > 0 && grid[tr(x-1,y)] == 1) {
            bool down = rec(x-1,y);
            if(down) return down;
        }

        if(y > 0 && grid[tr(x, y-1)] == 1) {
            bool left = rec(x, y-1);
            if(left) return left;
        }

        if(y < n-1 && grid[tr(x, y+1)] == 1) {
            bool right = rec(x, y+1);
            if(right) return right;
        }

        return false;

    }
    bool percolates() {
        int i;
        for(i = 0; i < grid.size();i++) {
            if(grid[i] == 2) {
                grid[i] = 1;
            }
        }
        for(i = 0; i < n; i++) {
            if(grid[i] == 1 && rec(n-1, i)) return true;
        }
        return false;
    }

};
