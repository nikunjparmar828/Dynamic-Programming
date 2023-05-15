class Solution {
public:
    bool flag = false;
    unordered_map<int, vector<string>> mp;
    unordered_map<string, bool> dp;

    string stringOperation(string s, string ws){
        // remove ws from s and return the new string
        string tempS;
        int i=0;
        for(; i<ws.length(); i++){
            if(s[i]!=ws[i]){return "101";}
        }
        for(; i<s.length(); i++){
            tempS.push_back(s[i]);
        }
        return tempS;
    }

    bool findWord(string s, vector<string>& subDict){
        if(subDict.empty()){return flag;}

        for(auto subString: subDict){
            string ns = stringOperation(s, subString);
            if(ns=="101"){continue;}
            if(ns.empty()){flag = true;}
            if(dp.find(ns)!=dp.end()){return dp[ns];}
            dp[ns] = findWord(ns, mp[(int)ns[0]]); 
        }
        return flag;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        for(auto w: wordDict){
            mp[(int)w[0]].push_back(w);
        }

        findWord(s, mp[(int)s[0]]);

        return flag;
    }
};
