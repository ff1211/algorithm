#include <iostream>
#include <time.h>
#include "data_structure/List.h"

using namespace std;

void printLots(const List<int> & L, const List<size_t> & P) {
    List<int>::const_iterator it_l = L.begin();
    int it_times = 0;
    List<size_t>::const_iterator it_p = P.begin();
    List<size_t>::const_iterator it_n = P.end();
    for (; it_p != it_n; ++it_p){
        while (it_times != *it_p) {
            ++it_l;
            ++it_times;
        }
        std::cout << *it_l << std::endl;
    }
}

int main(int argc, char * argv[]){

    clock_t start, end;
    double cpu_time_used, run_time;
    run_time = 0.0;
    
    for (int i = 0; i < 1; i++){
        start = clock();
        end = clock();
        run_time += (double)(end - start);
    }
    List<int> L(10);
    List<size_t> P(5);
    std::size_t index[] = {1, 2, 5, 7, 9};

    int i = 0;
    for (List<int>::iterator it = L.begin(); it != L.end(); ++it){
        *it = i;
        ++i;
    }

    i = 0;
    for (List<size_t>::iterator it = P.begin(); it != P.end(); ++it){
        *it = index[i];
        ++i;
    }

    printLots(L, P);
    
    cpu_time_used = (run_time / 10.0) / CLOCKS_PER_SEC;

    return 0;
}
