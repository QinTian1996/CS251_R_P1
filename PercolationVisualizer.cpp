#include "Percolation.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[]) {
    string file_name;
    cin >> file_name;
    ifstream file_stream;
    file_stream.open(file_name.c_str());
    int n = 0;
    file_stream >> n;
    ofstream of;
    of.open("visualMatrix.txt");
    if(!of.is_open()) return 1;
    cout << n << endl << endl;
    of << n << endl << endl;
    Percolation a(n);
    while(file_stream.peek() != EOF) {
        int x, y;
        file_stream >> x;
        file_stream >> y;
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


    /*
    if(a.percolates()) { cout << "Yes" <<endl; of << "Yes" << endl; }
    else { cout << "No" << endl; of << "No" << endl; }
    */

    of.close();

    return 0;
}
