#include <iostream>
#include <time.h>
#include "data_structure/List.h"
#include "data_structure/operation.h"
#include "data_structure/Queue.h"

using namespace std;

int main(int argc, char * argv[]){
    Queue<int> q;

    for (int i = 0; i < 16; i++)
        q.push(i+1);

    for (int i = 0; i < 8; i++)
        q.pop();

    for (int i = 0; i < 16; i++)
        q.push(i+17);

    while(q.size()) {
        cout << q.front() << " ";
        q.pop();        
    }
    cout << endl;
    
    return 0;
}
