class Solution {
  public:
    int check(vector<int> &arr, int n, int no){
        int student = 1;
        int sum = 0;
        for(int i = 0; i<n; i++){
            if(sum + arr[i] <= no){
                sum += arr[i];
            }
            else{
                student++;
                sum = arr[i];
            }
        }
        return student;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        if(n<k){
            return -1;
        }
        int sum = 0;
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            sum+=arr[i];
            maxi = max(arr[i], maxi);
        }
        int low = maxi;
        int high = sum;
        while(low<=high){
            int mid = (low+high)/2;
            int num = check(arr, n, mid);
            if(num > k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
    }
};
