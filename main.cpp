#include <iostream>
#include "data_structure/Vector.h"
#include "data_structure/Bst.h"
#include "data_structure/Avlt.h"

using namespace std;


int main(int argc, char * argv[]){
    Avlt<int> a;
    int aa[] = {4,2,6,1,3,5,7};
    for (int i = 0; i < 7; ++i)
        a.insert(aa[i]);
    a.print_tree(cout);
    cout << "a's height"<< a.height() << endl;
    for (int i = 16; i > 7; --i)
        a.insert(i);
    a.print_tree(cout);
    cout << "a's height"<< a.height() << endl;
    return 0;
}
