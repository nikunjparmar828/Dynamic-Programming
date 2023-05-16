class Solution {
public:
    int path(int i, int j, std::vector<std::vector<int>>& dp){
        if(i>=dp.size() || j>=dp[0].size()){return 0;}
        if(i==dp.size()-1 && j==dp[0].size()-1){return 1;}
        if(dp[i][j]){return dp[i][j];}
        return dp[i][j] = path(i+1, j, dp) + path(i, j+1, dp);
    }
    int uniquePaths(int m, int n) {
        int i=0, j=0;
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        return path(i, j, dp);
    }
};
