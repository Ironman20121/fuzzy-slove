class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> count;
        vector<int> ans;
        for(auto i :nums){
            count[i]++;
        }
        vector<vector<int>>bucket(nums.size()+1);
        for(auto i:count){
            bucket[i.second].push_back(i.first);
        }
        for(int i=bucket.size()-1;i>0;i--){
            for(auto j:bucket[i]){
                ans.push_back(j);
                if (ans.size()==k){return ans;}
            }
        }
        return ans;
    }
};