#include "seq_alg.h"

void ran_perm1(vector<int> & permutation){
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<int> rand(1, permutation.size()); // distribution in range [1, size]

    for (int i = 0; i < permutation.size(); i++){
        bool repeat = 0;

        do{
            repeat = 0;
            permutation[i] = rand(rng);
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
    random_device dev;
    mt19937 rng(dev());
    uniform_int_distribution<unsigned int> rand(1, permutation.size()); // distribution in range [1, size]
    vector<bool> repeat(permutation.size(), 0);

    for (int i = 0; i < permutation.size(); i++){
        while (1){
            int rand_num = rand(rng);
            if(!repeat[rand_num-1]){
                repeat[rand_num-1] = 1;
                permutation[i] = rand_num;
                break;
            }
        }
    }
}

void ran_perm3(vector<int> & permutation){
    random_device dev;
    mt19937 rng(dev());
    for (int i = 0; i < permutation.size(); i++)
        permutation[i] = i + 1;

    for(int i = 0; i < permutation.size(); i++) {
        uniform_int_distribution<int> rand(0, i); // distribution in range [0, i]
        swap(permutation[i], permutation[rand(rng)]);
    }  
}

int binary_search(int x, const vector<int> & seq){
    int low = 0, high = seq.size()-1;
    int mid;

    while (high >= low){
        mid = (high+low)/2;

        if(x < seq[mid])
            high = mid - 1;
        else if(x == seq[mid])
            return mid;
        else
            low = mid + 1;
    }

    return -1;
}

vector<int> major_ele_candi(const vector<int> & a){
    vector<int> candi;
    int N = a.size();

    if(N < 2 || (N == 2 && a[0] != a[1]))
        return a;

    int nn = N - 1;
    for (int i = 0; i < nn; i+=2)
        if(a[i] == a[i+1])
            candi.push_back(a[i]);
    if(N & 1)
        candi.push_back(a[nn]);
    
    return major_ele_candi(candi);
}

vector<int> major_ele(const vector<int> & a){
    vector<int> candi = major_ele_candi(a);
    vector<int> ans;
    
    int n = candi.size(), N = a.size();
    int N_div2 = N / 2;
    int candi_num[2]={};

    for (int i = 0; i < n; i++){
        for (int j = 0; j < N; j++)
            if(candi[i] == a[j])
                candi_num[i]++;

        if(candi_num[i] > N_div2)
            ans.push_back(candi[i]);
    }
    return ans;
}

bool search_matrix1(int x, unsigned int N, const vector<int> & a){
    int i = 0;
    int j = N-1;

    while (j >= 0 && i < N){
        int a_ij = a[i*N + j];
        if(x > a_ij)
            i++;
        else if(x == a_ij)
            return 1;
        else
            j--;
    }
    return 0; 
}

int max_value0(const vector<int> & a){
    int N = a.size();
    int candi = 0;

    for (int k = 0; k < N; k++)
        if(a[k] > candi)
            candi = a[k];   
    return candi + candi;
}

int max_value1(const vector<int> & a){
    int N = a.size();
    int mini = a[0];
    int result = 0;

    for (int k = 0; k < N; k++){
        mini = min(a[k], mini);
        result = max(result, a[k] - mini);
    }
    return result;
}