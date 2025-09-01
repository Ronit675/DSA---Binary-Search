// Solve Allocate minimum Pages first then try this problem.
// The Intuition and Approach of this question is same as the Allocate minimum Pages.

class Solution {
  public:
    int check(int n, vector<int> &arr, int no){
        int sum = 0;
        int painter = 1;
        for(int i = 0; i<n; i++){
            if(sum + arr[i] <= no){
                sum += arr[i];
            }
            else{
                sum = arr[i];
                painter++;
            }
        }
        return painter;
    }
    int minTime(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int sum = 0;
        int maxi = INT_MIN;
        for(int i = 0; i<n; i++){
            sum += arr[i];
            maxi = max(arr[i], maxi);
        }
        int low = maxi;
        int high = sum;
        while(low <= high){
            int mid = (low+high)/2;
            int num = check(n, arr, mid);
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
