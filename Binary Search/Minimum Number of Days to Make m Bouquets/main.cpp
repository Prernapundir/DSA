https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/



class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=INT_MAX,high=0;

        for(auto el:bloomDay){
            low=min(low,el);
            high=max(high,el);
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;

            int bouquets=0,count=0;
            for(auto el:bloomDay){
                if(el>mid){
                   count=0;
                   continue;
                }
                count++;
                if(count==k){
                    bouquets++;
                    count=0;
                }
            }
            
            if(bouquets>=m){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        
        return ans;
    }
};
