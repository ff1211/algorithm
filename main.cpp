#include <iostream>
#include <time.h>
#include "data_structure/List.h"
#include "data_structure/Vector.h"
#include "data_structure/operation.h"
#include "data_structure/Queue.h"

using namespace std;

int main(int argc, char * argv[]){
    Vector<char> infix;
    char a[] = "a+b*c+d-e*f*g";
    for (int i = 0; i < 13; i++)
        infix.push_back(a[i]);

    Vector<char> postfix = Infix2Postfix(infix);

    for (Vector<char>::const_iterator it = postfix.begin(); it != postfix.end(); ++it){
        cout << *it;
    }
    cout << endl;
    
    return 0;
}
