#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <time.h>
#include "seq/seq_alg.h"
#include "math/math_alg.h"

using namespace std;

int main(int argc, char * argv[]){

    const int N = atoi(argv[1]);

    //vector<int> a{5, 4, 3, 2, 1};

    clock_t start, end;
    double cpu_time_used, run_time;
    string result[10];
    string a = "9";
    string b = "99999999999999999999999999999999999999999999999999999999999994";

    run_time = 0.0;

    for (int i = 0; i < 10; i++){
        start = clock();
        result[i] = adder_str(a, b);
        end = clock();
        run_time += (double)(end - start);
    }
    
    cpu_time_used = (run_time / 10.0) / CLOCKS_PER_SEC;

    cout << fixed << "cpu time: " << cpu_time_used << "s" << endl;
    cout << "result: " << result[5] << endl;

    return 0;
}
