class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>t;
        for(auto i:strs){
            string key = i;
            sort(key.begin(),key.end());
            t[key].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto i:t){
            ans.push_back(i.second);
        }

        return ans;
    }
};