https://leetcode.com/problems/split-array-largest-sum/description/

/* 
solved using template 2
similar like capacity to ship in n days problem
*/

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int low=0,high=0;
        
        for(auto el:nums){
            low=max(low,el);
            high+=el;
        }

        while(low<high){
            int mid=low+(high-low)/2;

            int subarrays=1,sum=0;
            for(auto el:nums){
               sum+=el;
               if(sum>mid){
                   subarrays++;
                   sum=el;
               }
            }

            if(subarrays<=k){
                high=mid;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
