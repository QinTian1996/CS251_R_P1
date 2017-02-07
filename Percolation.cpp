#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Percolation.h"

using namespace std;

Percolation::Percolation(int n) : a(n * n){
   this->n = n;
   int i = 0;
   int total = n * n;
   while(i++ < total) {
       grid.push_back(0);
   }
}

void Percolation::open(int x, int y) {
   if(y < 0 || x < 0 || x >= n || y >= n) {
       return;
   }
   grid[tr(x,y)] = 1;
}

bool Percolation::isOpen(int x, int y) {
   if(y < 0 || x < 0 || x >= n || y >= n) {
       return 0;
   }
   return grid[tr(x,y)];
}

bool Percolation::isFull(int x, int y) {
   if(y < 0 || x < 0 || x >= n || y >= n) {
       return 0;
   }
   return grid[tr(x,y)] == 2;
}

int Percolation::tr(int x, int y) {
   return (n - 1 - x) * n + y;
}

bool Percolation::percolates() {

   int x = 0, y = 0;

   for(x = n-1; x >= 0; x--) {
       for(y = 0; y <= n-1; y++) {

           if(grid[tr(x, y)] != 1) { continue; }

           if(x > 0 && grid[tr(x-1, y)] != 0 && !a.connected(tr(x,y), tr(x-1,y))) {
               a.Union(tr(x,y), tr(x-1,y));
           }
           if(x < n-1 && grid[tr(x+1, y)] != 0 && !a.connected(tr(x,y), tr(x+1,y))) {
               a.Union(tr(x,y), tr(x+1,y));
           }
           if(y > 0 && grid[tr(x, y-1)] != 0 && !a.connected(tr(x,y), tr(x,y-1))) {
               a.Union(tr(x,y), tr(x,y+1));
           }
           if(y < n-1 && grid[tr(x, y+1)] != 0 && !a.connected(tr(x,y), tr(x,y+1))) {
               a.Union(tr(x,y), tr(x,y+1));
           }

           if(a.find(tr(x, y)) < n) grid[tr(x, y)] = 2;

       }
   }

   x = 0;
   for(y = 0; y < n; y ++) {
       //cout << "Find: " << tr(x,y) << ": "<< a.find(tr(x, y)) << endl;
       if(a.find(tr(x, y)) < n) {
           return true;
       }
   }
   return false;
}

/*int main(int argc, char const *argv[]) {
    int n = 0;
    cin >> n;
    Percolation a(n);
    while(cin.peek() != EOF) {
        int x, y;
        cin >> x;
        cin >> y;
        a.open(x, y);
    }

    bool p = a.percolates();
    if(p)cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}*/
