public class Solution {
    public static int upperBound(int []arr, int x, int n){
        int low=0;
        int high=n-1;
        int upper_bound=n;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>x){
                upper_bound=mid;
                high=mid-1;
            }else low=mid+1;
        }

        return upper_bound;
    }
}
