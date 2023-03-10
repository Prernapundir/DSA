https://leetcode.com/problems/search-in-rotated-sorted-array/

/*
Using template 1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]==target) return mid;

            if(nums[mid]<=nums[high]){  //condition to check left half is sorted
                if(target>=nums[mid] and target<=nums[high]){  // condition to check if target is it in the range      
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }else{
                if(target>=nums[low] and target<=nums[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
        }

        return -1;
    }
};
