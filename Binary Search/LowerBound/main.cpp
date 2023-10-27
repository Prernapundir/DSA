int lowerBound(vector<int> arr, int n, int x) {
	 	int low=0;
        int high=n-1;
        int lower_bound=n;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=x){
                lower_bound=mid;
                high=mid-1;
            }else low=mid+1;
        }

        return lower_bound;
}
