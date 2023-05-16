class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        // edge cases
        if(n==1){return 1;}

        if(nums[0]>0){dp[0]=1;}

        for(int i=0; i<n; i++){
            int j = nums[i];

            while(j>0 && dp[i] == 1){
                if(i+j < n){
                    dp[i+j] = 1;                 
                }
                j--;
            }
            if(dp[n-1]==1){return dp[n-1];}
        }

        return dp[n-1];
    }
};
