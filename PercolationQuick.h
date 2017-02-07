#include "QuickUnionUF.h"

using namespace std;

class PercolationQuick {

public:

    vector<int> grid;
    QuickUnionUF a;
    int n;

    PercolationQuick(int n);

    void open(int x, int y);

    bool isOpen(int x, int y);

    bool isFull(int x, int y);

    int tr(int x, int y);

    bool percolates();

    bool percolatestats (int x, int y);

};
