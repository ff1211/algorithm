#include "math_alg.h"

long long power_int1 (int base, unsigned int power){
    long long result = 1;

    for (int i = 0; i < power; i++)
        result *= base;

    return result;
}

//recursion
long long power_int2 (int base, unsigned int power){
    if(power == 0)
        return 1;
    else if(power == 1)
        return base;
    else if(!(power % 2))
        return power_int2(base*base, power/2);
    else
        return power_int2(base*base, power/2) * base;
}