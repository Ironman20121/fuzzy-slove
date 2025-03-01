class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        for(int i=0,j=i+1;i<nums.size()-1;i++,j++){
            if(nums[i] == nums[j]){
                nums[i] = nums[i]*2;
                nums[j] = nums[j]*0;
            }
        }
      
      for(int i=0;i<nums.size() -1;i++){
        int j =i+1;
        if (nums[i]==0){
            while(  (j<nums.size()) && nums[j]==0 ){j++;}

        if(nums[i]==0 && j==nums.size()){return nums;}
        //if it did not find any ele non -zero after i
        else{
        nums[i] = nums[j];
        nums[j] = 0;
        }
      }

      }
     
       return nums;  
    }
};