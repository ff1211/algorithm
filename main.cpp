#include <iostream>
#include <random>
#include <vector>
#include <iterator>
#include <string>
#include <time.h>
#include "seq/seq_alg.h"
#include "math/math_alg.h"
#include "data_struc/data_structure.h"
using namespace std;

int main(int argc, char * argv[]){

    // const int N = atoi(argv[1]);

    clock_t start, end;
    double cpu_time_used, run_time;
    run_time = 0.0;
    
    for (int i = 0; i < 1; i++){
        start = clock();
        end = clock();
        run_time += (double)(end - start);
    }
    
    cpu_time_used = (run_time / 10.0) / CLOCKS_PER_SEC;

    List<int> chou;
    int chou_num[] = {1,1,4,5,1,4};
    for (size_t i = 0; i < 6; i++)
        chou.push_back(chou_num[i]);

    for(List<int>::iterator it = chou.begin(); it != chou.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << fixed << "cpu time: " << cpu_time_used << "s" << endl;
    // if(ans.empty())
    //     cout << "no major element!" << endl;
    // else
    //     cout << "major element: " << ans[0] <<endl;

    return 0;
}
