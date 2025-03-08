class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left =0;
        int w_count =0;
        int min_c;
        for(int right=0;right<blocks.size();right++){
            if(blocks[right]=='W'){w_count++;}
            if(right-left+1==k){
                 min_c = min(min_c,w_count);
                if(blocks[left]=='W')w_count--;
                left++;
        }
        }
        return min_c;
       
    }
};