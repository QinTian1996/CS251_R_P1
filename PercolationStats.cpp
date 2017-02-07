#include "Percolation.h"
#include <ctime>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
    if(argc != 3 && argc != 4) return 1;
    int times = stoi(string(argv[1]));
    int n = stoi(string(argv[2]));
    int count = 0;
    vector<int> thresholds;
    vector<float> times;
    std::vector<int> shuffle;
    for(int i = 0; i < n * n; i++){ shuffle.push_back(i); }


    while(count++ < times) {
        random_shuffle(shuffle.begin(), shuffle.end());
        if(!compare("fast", string(argv[3]))) {
            Percolation a(n);
            int i;
            const clock_t begin_time = clock();
            for (i = 0; i < n * n; i++) {
                if(a.percolates()) { break; }
                a.grid[shuffle[i]] = 1;
            }
            const clock_t end_time = clock();
            times.push_back(end_time  - begin_time);
            thresholds.push_back(i);
        } else if(!compare("slow", string(argv[3]))) {
            PercolationSlow a(n);
            int i;
            const clock_t begin_time = clock();
            for (i = 0; i < n * n; i++) {
                if(a.percolates()) { break; }
                a.grid[shuffle[i]] = 1;
            }
            const clock_t end_time = clock();
            times.push_back(end_time  - begin_time);
            thresholds.push_back(i);
        } else { return 1; }

    }

    return 0;
}
