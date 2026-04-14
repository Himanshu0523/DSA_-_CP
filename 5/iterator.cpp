#include<iostream>
#include<random>
#include<vector>
#include<algorithm>
#include<stdexcept>

using namespace std;

// mt19937_64 - random number generator(RNG) engine in C++
    // Types of RNG
        // mt19937 - 32-bit Mersenne Twister
        // mt19937_64 - 64-bit Mersenne Twister
            #include<random>
        // uniform_int_distribution
        // uniform_real_distribution
    // directly from distribution without passing RNG

        // mt19937_64 rng(12345); // create RNG with seed
        // uniform_int_distribution<int> dist(1 , 10);
        // int x = dist(rng); // get random number from 1 to 10

    // 

// Truncated Fisher-Yates Shuffle (or Partial Fisher-Yates Shuffle)
void partial_shuffle(vector<int>& a, size_t k, mt19937_64& rng) {
    size_t n = a.size();
    if(k > n) throw std::invalid_argument("k must be <= n");

    for (size_t i = 0; i < k; i++) {
        std::uniform_int_distribution<size_t> dist(i , n -1);
        size_t j = dist(rng);
        std::swap(a[i] , a[j]);
    }
}



vector<vector<int>> make_k_groups(vector<int> &a, size_t k, mt19937_64& rng) {
    size_t  n = a.size();
    if (k == 0 || k > n) throw invalid_argument("k must be between 1 and n");

    // O(n)  Fisheer-Yates full shuffe
    for (size_t i = 0; i < n; i++) {
        uniform_int_distribution<size_t> dist(i , n - 1);
        size_t j = dist(rng);
        swap(a[i] , a[j]);
    }

    // Prepare groups 
    vector<vector<int>> groups(k);

    // Balanced Distribution
    size_t base = n / k;
    size_t extra = n % k;

    size_t idx = 0;
    for (size_t g = 0; g < k; g++) {
        size_t size_g = base + (g < extra ? 1 : 0);
        groups[g].reserve(size_g);

        for(size_t i = 0; i < size_g; i++)
            groups[g].push_back(a[idx++]);
    }

    return groups;
}

// best method : O(k) expected time , no O(n) array
vector<size_t> k_indices(size_t n, size_t k, mt19937_64& rng) {
    if (k > n) throw invalid_argument("K must be <= n");

    vector<size_t> res;
    res.reserve(k);

    for (size_t i = 0; i< n; i++) {
        if (res.size() < k) {res.push_back(i);}
        else {
            uniform_int_distribution<size_t> dist(0, i);
            size_t j = dist(rng);
            if (j < k)
                res[j] = i;
        }
    }
    return res;
}


// Reservoir Sampling Better than o(N)
vector<size_t> k_indices(size_t n, size_t k, mt19937& rng) {
    if(k > n) throw invalid_argument("K must be <= n");

    vector<size_t> res;
    res.reserve(k);

    for (size_t i = 0; i < n; i++) {
        if (res.size() < k) {
            res.push_back(i);
        }else {
            uniform_int_distribution<size_t> dist(0 , i);
            size_t j = dist(rng);
            if (j < k)
                res[j] = i;
        }
    }
    return res;
}