#include <iostream>
#include <random>
#include <vector>
#include <string.h>
#include <time.h>
#include "./seq/rand_perm.h"

using namespace std;

int main(int argc, char * argv[]){

    const int N = atoi(argv[2]);

    vector<int> perm(N);

    clock_t start, end;
    double cpu_time_used, run_time;

    run_time = 0.0;

    for (int i = 0; i < 10; i++){
        start = clock();
        if(strcmp(argv[1], "a") == 0)
            ran_perm1(perm);
        else if(strcmp(argv[1], "b") == 0)
            ran_perm2(perm);
        else
            ran_perm3(perm);
        end = clock();

        run_time += (double)(end - start);
    }
    
    cpu_time_used = (run_time / 10.0) / CLOCKS_PER_SEC;

    cout << fixed << "cpu time: " << cpu_time_used << "s" << endl;

    return 0;
}
