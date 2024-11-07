
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

// 1. Longest Palindromic Subsequence (Recursive)
int longestPalindromicSubseq(string &s, int i, int j) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (s[i] == s[j]) return 2 + longestPalindromicSubseq(s, i + 1, j - 1);
    return max(longestPalindromicSubseq(s, i + 1, j), longestPalindromicSubseq(s, i, j - 1));
}

// 2. Longest Increasing Subsequence (Recursive)
int longestIncreasingSubseq(vector<int> &nums, int prev, int curr) {
    if (curr == nums.size()) return 0;
    int taken = 0;
    if (prev < 0 || nums[curr] > nums[prev]) {
        taken = 1 + longestIncreasingSubseq(nums, curr, curr + 1);
    }
    int notTaken = longestIncreasingSubseq(nums, prev, curr + 1);
    return max(taken, notTaken);
}

// 3. Weighted Interval Scheduling using Tabulation
struct Interval {
    int start, end, weight;
};

bool compareInterval(const Interval &a, const Interval &b) {
    return a.end < b.end;
}

int weightedIntervalScheduling(vector<Interval> &intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), compareInterval);
    
    vector<int> dp(n, 0);
    dp[0] = intervals[0].weight;

    for (int i = 1; i < n; i++) {
        int includeWeight = intervals[i].weight;
        
        int j = i - 1;
        while (j >= 0 && intervals[j].end > intervals[i].start) {
            j--;
        }

        if (j != -1) {
            includeWeight += dp[j];
        }

        dp[i] = max(dp[i - 1], includeWeight);
    }

    return dp[n - 1];
}

// 4. Sequence Alignment using Tabulation
int sequenceAlignment(string &X, string &Y, int match, int mismatch, int gap) {
    int m = X.size(), n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) dp[i][0] = i * gap;
    for (int j = 0; j <= n; j++) dp[0][j] = j * gap;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + match;
            } else {
                dp[i][j] = max({dp[i - 1][j - 1] + mismatch, dp[i - 1][j] + gap, dp[i][j - 1] + gap});
            }
        }
    }

    return dp[m][n];
}

// Test cases
int main() {
    // Longest Palindromic Subsequence
    string s = "bbbab";
    cout << "Longest Palindromic Subsequence: " << longestPalindromicSubseq(s, 0, s.size() - 1) << endl;

    // Longest Increasing Subsequence
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Longest Increasing Subsequence: " << longestIncreasingSubseq(nums, -1, 0) << endl;

    // Weighted Interval Scheduling
    vector<Interval> intervals = {{1, 3, 5}, {2, 5, 6}, {4, 6, 5}, {6, 7, 4}, {5, 8, 11}, {7, 9, 2}};
    cout << "Weighted Interval Scheduling: " << weightedIntervalScheduling(intervals) << endl;

    // Sequence Alignment
    string X = "AGGTAB", Y = "GXTXAYB";
    int match = 2, mismatch = -1, gap = -2;
    cout << "Sequence Alignment: " << sequenceAlignment(X, Y, match, mismatch, gap) << endl;

    return 0;
}
