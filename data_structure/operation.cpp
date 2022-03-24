#include "operation.h"

// Print the elements in L that are in positions specified by P.
void printLots(const List<int> & L, const List<size_t> & P) {
    List<int>::const_iterator it_l = L.begin();
    int it_times = 0;
    for (List<size_t>::const_iterator it_p = P.begin(); it_p != P.end(); ++it_p){
        while (it_times != *it_p) {
            ++it_l;
            ++it_times;
        }
        std::cout << *it_l << std::endl;
    }
}