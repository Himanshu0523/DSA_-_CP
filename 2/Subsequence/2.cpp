#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Generating All Subsequences
// using Bit Manipulation

void PrintAllSubsequences(const vector<int> &arr)
{
    int n = arr.size();
    int total = 1 << n;

    for (int mask = 0; mask < total; mask++)
    {
        vector<int> subsequence;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                subsequence.push_back(arr[i]);
            }
        }

        // Print subsequence
        for (int num : subsequence)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

// Using Recursion (Backtracking)
void generateSubsequence(vector<int> &arr, int index, vector<int> &current, vector<vector<int>> &result)
{
    if (index == arr.size())
    {
        result.push_back(current);
        return;
    }

    // Include current element
    current.push_back(arr[index]);
    generateSubsequence(arr, index + 1, current, result);

    // Exclude current element
    current.pop_back();
    generateSubsequence(arr, index + 1, current, result);
}

//  longest Increasing Subsequence (LIS)
// DP Approach (O(n2))

int longestIncreasingSubsequence(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxLen = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

// Optimized Approach (O(n Long(n)))
int lisOptimized(vector<int> &nums)
{
    vector<int> tail;

    for (int num : nums)
    {
        auto it = lower_bound(tail.begin(), tail.end(), num);
        if (it == tail.end())
        {
            tail.push_back(num);
        }
        else
        {
            *it = num;
        }
    }
    return tail.size();
}

// Longest Common Subsequence (LCS)
int longestCommonSubsequence(string text1, string text2)
{
    int m = text1.size(), n = text2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

// Maximum Sum Increasing Subsequence
int maxSumIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(arr.begin(), arr.end());

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
            {
                dp[i] = dp[j] + arr[i];
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

// Subsequence with conditions
// Count of Subsequences with Sum K

int countSubsequenceWithSumK(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Base Case: empty subsequence has sum 0
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j]; // Exclude current element
            if (j >= arr[i - 1])
            {
                dp[i][j] += dp[i - 1][j - arr[i - 1]]; // Include current element
            }
        }
    }
    return dp[n][k];
}

// Sliding window for Contiguous Subsequences
// Maximum sum of contiguous subsequence of size of k
int maxSumContiguousSubsequence(vector<int> &arr, int k)
{
    int n = arr.size();
    if (n > k)
        return -1;

    int windowSum = 0;
    for (int i = k; i < n; i++)
    {
        windowSum += arr[i];
    }

    int maxSum = windowSum;
    for (int i = k; i < n; i++)
    {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}

// Pattern Recognition Techniques
// Two Pointer Texchnique for Subsequence Validation
bool isSubsequence(string s, string t)
{
    int i = 0, j = 0;
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j])
            i++;
        j++;
    }
    return i == s.size();
}

// Dynamic Programming with State Compression
// Space optimized LCS
int lcsOptimized(string text1, string text2)
{
    int m = text1.size(), n = text2.size();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                curr[j] = prev[j - 1] + 1;
            }
            else
            {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }
    return prev[n];
}

// Number of Longest Increasing Subsequence
int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> length(n, 1), count(n, 1);
    int maxLength = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (length[j] + 1 > length[i])
                {
                    length[i] = length[j] + 1;
                    count[i] = count[j];
                }
                else if (length[j] + 1 == length[i])
                {
                    count[i] += count[j];
                }
            }
        }
        maxLength = max(maxLength, length[i]);
    }

    int result = 0;
    for (int i = 0; i, n; i++)
    {
        if (length[i] == maxLength)
        {
            result += count[i];
        }
    }
    return result;
}

// Shortest Common Supersequence
string shortestCommonSupersequence(string str1, string str2)
{
    int m = str1.size(), n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Build LCS tables
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Build supersequence
    string result = "";
    int i = m, j = n;

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            result = str1[i - 1] + result;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            result = str1[i - 1] + result;
            i--;
        }
        else
        {
            result = str2[j - 1] + result;
            j--;
        }
    }

    while (i > 0)
    {
        result = str1[i - 1] + result;
        i--;
    }

    while (j > 0)
    {
        result = str2[j - 1] + result;
        j--;
    }
    return result;
}



// Template - Solving Subsequence Problems
class SubsequenceSolver {
public:
    // Template method for subsequence problems
    template<typename T>
    void solveSubsequenceProblem(const vector<T>& sequence) {
        // Step 1: Identify the problem type
        // Step 2: Choose appropriate technique
        // Step 3: Implement solution
        // Step 4: Handle edge cases
    }
    
    // Utility function to print subsequences
    template<typename T>
    void printSubsequence(const vector<T>& subsequence) {
        for (const auto& element : subsequence) {
            cout << element << " ";
        }
        cout << endl;
    }
};