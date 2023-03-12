https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

/*
using template 2
Binary Search on a range
*/

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end()),high=0;

        for(auto el:weights) high+=el;

        while(low<high){
            int mid=low+(high-low)/2;
            int total_days=0,capacity=0;

            for(auto el:weights){
                capacity+=el;
                if(capacity>mid){
                    total_days++;
                    capacity=el;
                }
            }
            if(capacity<=mid) total_days++;

            if(total_days<=days){
                high=mid;
            }else{
                low=mid+1;
            }
        }

        return low;
    }
};
