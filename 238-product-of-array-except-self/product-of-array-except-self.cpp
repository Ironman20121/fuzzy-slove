class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        vector<int>prefix;
        vector<int>postfix;
        int val = 1;
        for(auto &i:nums){
            val*=i;
            prefix.push_back(val);
           
        }
        //1,2,3,4
        //1,2,6,24
        //24,24,12,4
        val = 1;
        for(int i=nums.size()-1;i>=0;i--){
            val*=nums[i];
            postfix.insert(postfix.begin()+0,val);
        }
        //no perfix for first make it one 
        ans.push_back(postfix[1]);

        for(int i=1;i<nums.size() -1;i++){
           ans.push_back(prefix[i-1]*postfix[i+1]);
        }
        //no posfix for last digit so make only perfix
        for(int i: prefix){cout<<i<<" ";}
        ans.push_back(prefix[nums.size()-2]);
        return ans;
    }
};