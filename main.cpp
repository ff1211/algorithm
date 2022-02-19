#include <iostream>
#include <random>
#include <vector>
#include <string.h>
#include <time.h>
#include "seq/rand_perm.h"
#include "math/math_alg.h"

using namespace std;

int main(int argc, char * argv[]){

    const int N = atoi(argv[2]);

    cout << sizeof(long) << endl;

    vector<int> a(N);

    for (int i = 0; i < N; i++)
        a[i] = 1;

    clock_t start, end;
    double cpu_time_used, run_time;

    run_time = 0.0;

    for (int i = 0; i < 10; i++){
        start = clock();
        horner_rule(10, a);
        end = clock();
        run_time += (double)(end - start);
    }
    
    cpu_time_used = (run_time / 10.0) / CLOCKS_PER_SEC;

    cout << fixed << "cpu time: " << cpu_time_used << "s" << endl;

    return 0;
}
