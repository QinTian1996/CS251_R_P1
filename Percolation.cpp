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
        if(x < 0 || y < 0 || y >= n || x >= n) {
            return;
        }
        grid[x + y * n] = 1;
    }

    bool isOpen(int x, int y) {
        if(x < 0 || y < 0 || y >= n || x >= n) {
            return 0;
        }
        return grid[x + y * n];
    }

    bool isFull(int x, int y) {
        if(x < 0 || y < 0 || y >= n || x >= n) {
            return 0;
        }
        return grid[x + y * n] == 2;
    }

    bool rec(int x, int y) {

        grid[x + y * n] = 2;

        if(y == 0) return true;

        if(y > 0 && grid[x + (y-1) * n] == 1) {
            bool up = rec(x, y-1);
            if(up) return up;
        }

        if(y < n - 1 && grid[x + (y+1) * n] == 1) {
            bool down = rec(x, y+1);
            if(down) return down;
        }

        if(x > 0 && grid[x - 1 + y * n] == 1) {
            bool left = rec(x-1, y);
            if(left) return left;
        }

        if(x < n - 1 && grid[x + 1 + y * n] == 1) {
            bool right = rec(x+1, y);
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
            if(grid[i] == 1 && rec(i, n-1)) return true;
        }
        return false;
    }

};


/*int main(int argc, char const *argv[]) {
    string file_name;
    cin >> file_name;
    ifstream file_stream;
    file_stream.open(file_name);
    int n = 0;
    file_stream >> n;
    //cout << n;
    Percolation a(n);
    while(file_stream.peek() != EOF) {
        int x, y;
        file_stream >> y;
        file_stream >> x;
        a.open(x, y);
    }

    //simple print grid
    for(int i = 0; i < a.grid.size();i++) {
        cout << a.grid[i];
        if((i + 1) % n == 0) { cout<<endl; }
        else { cout << " "; }
    }

    if(a.percolates()) cout << "Yes" <<endl;
    else cout << "No" << endl;

    return 0;
}
*/
