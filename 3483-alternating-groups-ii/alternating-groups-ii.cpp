class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int s = colors.size();
        int left = 0,res = 0;
        for(int right=1;right<s+k-1;right++){
            if(colors[right %s]==colors[(right -1)%s]){left=right;}
            if(right-left + 1 >k){left++;}
            if(right-left + 1 ==k){res++;}
        }
        return res;
    }
};