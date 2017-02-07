#include "Percolation.h"
#include "PercolationVisualizer.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    int n = 0;
    cin >> n;
    ofstream of;
    of.open("visualMatrix.txt");
    if(!of.is_open()) return 1;
    cout << n << endl << endl;
    of << n << endl << endl;
    Percolation a(n);
    while(cin.peek() != EOF) {
        int x, y;
        cin >> x;
        cin >> y;
        a.open(x, y);
        a.percolates();
        for(int i = 0; i < a.grid.size();i++) {
            cout << a.grid[i];
            of << a.grid[i];
            if((i + 1) % n == 0) { cout<<endl; of << endl; }
            else { cout << " "; of << " "; }
        }
        cout << endl;
        of << endl;
        if(a.percolates()) { break; }
    }

    of.close();

    return 0;
}
