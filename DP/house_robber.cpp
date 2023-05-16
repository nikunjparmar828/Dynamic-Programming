class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()){return 0;}

        vector<set<int>> dp(nums.size(), {0});
        int max_element = 0;
        
        for(int i=0; i<dp.size(); i++){
            if(i<2){
                dp[i].insert(nums[i]);
            }
            for(int j=i+2; j<dp.size(); j++){
                dp[j].insert(*(dp[i].rbegin()) +nums[j]);
            }
        }
        for(auto x: dp){
            if(*(x.rbegin()) > max_element){
                max_element = *(x.rbegin());
            }
        }
        return max_element;
    }
};
