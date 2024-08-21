class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        if (n == 0) return 0;  // If the string is empty, no turns are needed.
        
        // Step 1: Initialize the DP table
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
        
        // Step 2: Base case - every single character substring requires one turn
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        // Step 3: Fill the DP table for all substrings
        for (int len = 2; len <= n; len++) {  // len is the length of the substring
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;  // j is the end index of the substring
                dp[i][j] = len;  // Initialize with a maximum value (worst case)

                for (int k = i; k < j; k++) {
                    // Total turns required if we split the substring at position k
                    int totalTurns = dp[i][k] + dp[k+1][j];
                    
                    // If s[k] == s[j], we can reduce the turn count
                    if (s[k] == s[j]) {
                        totalTurns -= 1;
                    }

                    // Find the minimum turns
                    dp[i][j] = min(dp[i][j], totalTurns);
                }
            }
        }
        // Step 4: The result for the entire string is in dp[0][n-1]
        return dp[0][n-1];
    }
};