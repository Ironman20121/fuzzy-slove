class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>hashset(nums.begin(),nums.end());
        int count = 0;
        int max_count =0;
        for(int ele:hashset){
            if( hashset.find(ele -1) == hashset.end() ){
                count =1;
                while( hashset.find(ele+count) != hashset.end() ){
                    count++;
                }
                max_count = max(max_count,count);
            }
        }
        return max_count;
    }
};