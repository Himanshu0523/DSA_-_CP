#include <bits/stdc++.h>
#include <math.h>

using namespace std;

// Get MiNimum Square

// Given a number N, Find the minimun number of squares of any number that sums to N , For example : if N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as minimum number of square is 1 , i.e. (10*10).

// example
//  i/p :-  N = 100 , o/p :-  1 , explain - 10 * 10 = 100
//  i/p :-  N = 6 , o/p :-  3 , explain - 1 * 1 + 1* 1+ 2 * 2 = 6

//  intitution are
//           N  = 5,
// perfect_Square( n * n) < N ,
// n  =  1 to (n*n < N)

class Solution
{
public:
    int solve(int n , vector<int> &dp)
    {
        if (n == 0)return 0; // base case
        if (dp[n] != -1)return dp[n];

        int mini = n;
        for (int i = 1; i * i <= n; i++)
        {
            int temp = i * i;
            mini = min(mini, 1 + solve(n - temp , dp));
        }

        return dp[n] = mini;
    }

    int MinSquare(int N)
    {   
        vector<int> dp(N + 1 , -1);
        return solve(N , dp);
    }


    int otherMethod(int n){
        int root = sqrt(n);
        if (root * root == n) {
            return 1;
        }
        vector<int>dp(n, 0);

        vector<int>Squares;
        for (int i = 1; i*i < n; i++){
            Squares.push_back(i);
        }
        
        for(int i = 1; i <= n; i++){
            for(int square : Squares){
                if(i < square)break;
                dp[i] = min(dp[i] , 1+dp[n-square]);
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution obj;
    cout << obj.MinSquare(1000);
    return 0;
}