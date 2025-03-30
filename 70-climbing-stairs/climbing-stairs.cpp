class Solution {
public:
    int climbStairs(int n) {
    map<int,int>t; 

        function<int(int)> dfs = [&](int i){
            if (i >= n) {
                int ans = 0;
                if(i==n){ans =1;}
                return ans;
            }
            if( t.find(i) != t.end() ){
                return t[i];
            }
            return t[i]=dfs(i+1) + dfs(i+2);
        };
        return dfs(0);
    }
};