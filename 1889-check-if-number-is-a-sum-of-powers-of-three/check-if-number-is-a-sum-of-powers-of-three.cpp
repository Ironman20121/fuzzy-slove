class Solution {
public:
    bool checkPowersOfThree(int n) {

        function<bool(int ,int )> backtrack = [&](int i, int curr){
            if (curr == n)return true;
            if(curr > n || pow(3,i) >n){
                return false;
            }

            if( backtrack (i+1,curr + pow(3,i))){
                return true;
            }
            return backtrack(i+1,curr);
            
        };

        return backtrack(0,0);
        
    }
};