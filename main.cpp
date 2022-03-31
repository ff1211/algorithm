#include <iostream>
#include <time.h>
#include "data_structure/List.h"
#include "data_structure/operation.h"

using namespace std;

int main(int argc, char * argv[]){
    string filename("input.txt");
    cout << balancing_symb(filename) << endl;
    return 0;
}
