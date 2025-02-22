class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1, mid =0;
        while(left <=right){

            mid = (int)(left+right)/2; 
            
            if( target > nums[mid]){
                left = mid +1; 
            }
            else if (target < nums[mid]){
                right = mid -1;
            }
            else{
                return mid;
            }

        }
         return -1;
        
    }
};