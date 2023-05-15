class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        int dp[n+1][m+1];
        
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<=n; i++){dp[i][0]=0;}
        for(int j=0; j<=m; j++){dp[0][j]=0;}

        for(int k=1; k<=n; k++){
            for(int l=1; l<=m; l++){
                if(text1[k-1]==text2[l-1]){
                    dp[k][l] = dp[k-1][l-1] + 1;
                }else{
                    dp[k][l] = max(dp[k-1][l], dp[k][l-1]);
                }
            }
        }

        return dp[n][m];
    }
};
