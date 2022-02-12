#include "rand_perm.hpp"

void ran_perm1(vector<int> & permutation){
    uniform_int_distribution<int> dist(1, permutation.size()); // distribution in range [1, size]

    for (int i = 0; i < permutation.size(); i++){
        bool repeat = 0;

        do{
            repeat = 0;
            permutation[i] = dist(rng);
            for (int j = 0; j < i; j++){
                if(permutation[j] == permutation[i]){
                    repeat = 1;
                    break;
                }
            }
        } while (repeat);
    }
}

void ran_perm2(vector<int> & permutation){
    uniform_int_distribution<unsigned int> dist(1, permutation.size()); // distribution in range [1, size]
    vector<bool> repeat(permutation.size(), 0);

    for (int i = 0; i < permutation.size(); i++){
        while (1){
            int rand_num = dist(rng);
            if(!repeat[rand_num-1]){
                repeat[rand_num-1] = 1;
                permutation[i] = rand_num;
                break;
            }
        }
    }
}

void ran_perm3(vector<int> & permutation){
    for (int i = 0; i < permutation.size(); i++)
        permutation[i] = i + 1;

    for(int i = 0; i < permutation.size(); i++) {
        uniform_int_distribution<int> dist(0, i); // distribution in range [0, i]
        swap(permutation[i], permutation[dist(rng)]);
    }  
}