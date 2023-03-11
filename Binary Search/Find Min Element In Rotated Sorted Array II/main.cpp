https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

/*
Logic: 
Here due to duplicates we have to check this condition : nums[low]==nums[mid]==nums[high], round down the high by 1
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,n=nums.size();
        int high=nums.size()-1;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(nums[mid]>nums[high]){  // condition for right unsorted half
                low=mid+1;
            }else if(nums[mid]<nums[high]){  // condition for left unsorted half ( here nums[mid]>nums[low] can also work )
                high=mid;
            }else{
                high--;   // condition : nums[low]==nums[mid]==nums[high]
            }
        }
        return nums[low];
                         
    }
};
