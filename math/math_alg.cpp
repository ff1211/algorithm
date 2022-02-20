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

long gcd(long a, long b){
    while (b != 0){
        long rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

string adder_str(const string & a, const string & b) {
    // write code here
    int n, s_size, t_size;
    s_size = a.size();
    t_size = b.size();

    n = (s_size > t_size)? s_size : t_size;
    
    string result;
    int carry = 0;
    
    for(int i=0; i<n || carry!=0; i++){
        int add;
        add = carry;
        add = add + ( (i >= s_size)? 0 : (a[s_size-i-1]-'0') );
        add = add + ( (i >= t_size)? 0 : (b[t_size-i-1]-'0') );
        
        result.insert(0, 1, char(add%10+'0'));
        carry = add / 10;
    }
    
    return result;
}