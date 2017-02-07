#include "WeightedQuickUnionUF.h"

using namespace std;

class Percolation {

public:

    vector<int> grid;
    WeightedQuickUnionUF a;
    int n;

     Percolation(int n);

    void open(int x, int y);

    bool isOpen(int x, int y);

    bool isFull(int x, int y);

    int tr(int x, int y);

    bool percolates();

    bool percolatestats (int x, int y);

};
