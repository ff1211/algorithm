#include <iostream>
#include <random>
#include <vector>
#include <iterator>
#include <string>
#include <time.h>
#include "seq/seq_alg.h"
#include "math/math_alg.h"

using namespace std;

int main(int argc, char * argv[]){

    // const int N = atoi(argv[1]);

    // vector<int> a{1, 1, 1, 2, 3, 2, 1};

    // vector<int>::const_iterator pta = a.begin();

    clock_t start, end;
    double cpu_time_used, run_time;
    vector<int> ans;
    // string a = "9";
    // string b = "99999999999999999999999999999999999999999999999999999999999994";

    run_time = 0.0;
    
    for (int i = 0; i < 1; i++){
        start = clock();
        end = clock();
        run_time += (double)(end - start);
    }
    
    cpu_time_used = (run_time / 10.0) / CLOCKS_PER_SEC;

    cout << fixed << "cpu time: " << cpu_time_used << "s" << endl;
    // if(ans.empty())
    //     cout << "no major element!" << endl;
    // else
    //     cout << "major element: " << ans[0] <<endl;

    return 0;
}
