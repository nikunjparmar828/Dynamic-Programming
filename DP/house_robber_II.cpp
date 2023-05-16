class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()){return 0;}

        vector<set<int>> dp1(nums.size(), {0});
        vector<set<int>> dp2(nums.size(), {0});
        int max_element = 0;

        for(int i=0; i<dp1.size(); i++){
            dp1[i].insert(nums[i]);

            for(int j=i+2; j<dp1.size()-1; j++){
                dp1[j].insert(*(dp1[i].rbegin()) +nums[j]);
            }
        }
        for(int i=1; i<dp2.size(); i++){
            dp2[i].insert(nums[i]);

            for(int j=i+2; j<dp2.size(); j++){
                dp2[j].insert(*(dp2[i].rbegin()) +nums[j]);
            }
        }

        for(auto x: dp1){
            if(*(x.rbegin()) > max_element){
                max_element = *(x.rbegin());
            }
        }
        for(auto x: dp2){
            if(*(x.rbegin()) > max_element){
                max_element = *(x.rbegin());
            }
        }
        
        return max_element;
    }
};
