#include "Percolation.h"
#include "PercolationQuick.h"
#include "PercolationStats.h"
#include <ctime>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    if(argc != 3 && argc != 4) return 1;
    int time_count = stoi(string(argv[1]));
    int n = stoi(string(argv[2]));
    int count = 0;
    vector<int> thresholds;
    vector<float> times;
    std::vector<int> shuffle;
    for(int i = 0; i < n * n; i++){ shuffle.push_back(i); }


    while(count++ < time_count) {
        random_shuffle(shuffle.begin(), shuffle.end());
        if(!string(argv[3]).compare("fast")) {
            Percolation a(n);
            int i;
            const clock_t begin_time = clock();
            for (i = 0; i < n * n; i++) {
                if(a.percolatestats(shuffle[i] / n, shuffle[i] % n)) { break; }
                a.grid[shuffle[i]] = 1;
            }
            const clock_t end_time = clock();
            times.push_back((end_time  - begin_time)/(double)CLOCKS_PER_SEC);
            thresholds.push_back(i);
        } else if(!string(argv[3]).compare("slow")) {
            PercolationQuick a(n);
            int i;
            const clock_t begin_time = clock();
            for (i = 0; i < n * n; i++) {
                if(a.percolatestats(shuffle[i] / n, shuffle[i] % n)) { break; }
                a.grid[shuffle[i]] = 1;
            }
            const clock_t end_time = clock();
            times.push_back((end_time  - begin_time)/(double)CLOCKS_PER_SEC);
            thresholds.push_back(i);
        } else { return 1; }

    }

    int total_thrshold = 0;
    int total_var = 0;
    double total_time = 0;
    double total_var_time = 0;
    for(int i : thresholds) total_thrshold += i;
    double mean_threshold = total_thrshold / (double)thresholds.size();
    for(int i : thresholds) total_var += pow((i - mean_threshold), 2);
    double stdv_threshold = sqrt(total_var / (double)thresholds.size());
    for(float i : times) total_time += i;
    double mean_time= total_time / (double)times.size();
    for(float i : times) total_var_time += pow((i - mean_time), 2);
    double stdv_time = sqrt(total_var_time / (double)times.size());

    cout << "mean threshold=" << mean_threshold << endl;
    cout << "std dev=" << stdv_threshold << endl;
    cout << "time=" << total_time << endl;
    cout << "mean time=" << mean_time << endl;
    cout << "stddev time=" << stdv_time / 1000.0 << endl;

    cout << "\n*p=" << mean_threshold/((double)(n * n)) << endl;
    return 0;
}
