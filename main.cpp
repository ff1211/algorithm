#include <iostream>
#include <random>
#include <vector>
#include <string.h>
#include <time.h>
#include "seq/seq_alg.h"
#include "math/math_alg.h"

using namespace std;

int main(int argc, char * argv[]){

    const int N = atoi(argv[1]);

    //vector<int> a{2, 1, 0, 8, 4};

    clock_t start, end;
    double cpu_time_used, run_time;
    long result;

    run_time = 0.0;

    for (int i = 0; i < 10; i++){
        start = clock();
        result = power_int2(2, N);
        end = clock();
        run_time += (double)(end - start);
    }
    
    cpu_time_used = (run_time / 10.0) / CLOCKS_PER_SEC;

    cout << fixed << "cpu time: " << cpu_time_used << "s" << endl;
    cout << "result: " << result << endl;

    return 0;
}
