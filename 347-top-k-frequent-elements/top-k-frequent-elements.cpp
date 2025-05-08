class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> count;
        vector<int> ans;
        for(auto i :nums){
            count[i]++;
        }
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
          
        for(auto i:count){
            minHeap.push({i.second,i.first});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        for(int i=0;i<k;i++){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
    }
};