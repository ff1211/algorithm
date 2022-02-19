#include "math_alg.h"

long power_int1 (long base, unsigned int power){
    long result = 1;

    for (int i = 0; i < power; i++)
        result *= base;

    return result;
}

//recursion
long power_int2 (long base, unsigned int power){
    if(power == 0)
        return 1;
    else if(power == 1)
        return base;
    else if(!(power % 2))
        return power_int2(base*base, power/2);
    else
        return power_int2(base*base, power/2) * base;
}

long horner_rule (long x, const vector<int> a){
    long poly = 0;
    int n = a.size() - 1;

    for (int i = n; i >= 0; i--)
        poly = x * poly + a[i];

    return poly;
}