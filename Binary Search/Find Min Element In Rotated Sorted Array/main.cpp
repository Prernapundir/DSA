/*
Logic : search in the unsorted half for the minimum element
and discard the sorted part 
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        int size=nums.size();

        while(low<=high){
            int mid=low+(high-low)/2;

            int next=nums[(mid+1)%size];
            int prev=nums[(mid-1+size)%size];

            if(nums[mid]<=next and nums[mid]<=prev){
                return nums[mid];
            }else if(nums[mid]>=nums[high]){  // condition to check unsorted part
                low=mid+1;
            }else{
                high=mid-1;
            }                                      
        }

        return nums[low];
    }
};
