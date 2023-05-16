using namespace std;
class Solution {
public:
    int fib(int n, map<int, int>& memo){

        if(n==0){memo[0] = 0; return 0;}
        if(n==1){memo[1] = 1; return 1;}

        if(memo.find(n)!=memo.end())
            return memo[n];
        else{
            memo[n] = fib(n-2, memo)+fib(n-1, memo);
        }
        return memo[n];
    } 
    int climbStairs(int n) {
        map<int, int> memo{};
        return fib(n+1, memo);
    }
};
