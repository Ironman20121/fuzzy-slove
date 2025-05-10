class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>t;
        for (auto s:strs){
            vector<int>count(26,0);
            for(char c:s){
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for(int i=1;i<26;i++){
                key+=","+to_string(count[i]);
            }
            t[key].push_back(s);  
        }
        vector<vector<string>>ans;
        for(auto i:t){
            ans.push_back(i.second);
        }
        return ans;
    }
};