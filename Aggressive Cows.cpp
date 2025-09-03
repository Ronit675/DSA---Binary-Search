// # Intuition
// <!-- Describe your first thoughts on how to solve this problem. -->
// -> First thought is to put the cows at a certain number of distance 
// -> between minimum distance to maximum distance possible and iterate is such a way so that all cows fit 
// -> at the minimum possible maximum distance

// # Approach
// <!-- Describe your approach to solving the problem. -->
// -> Sort the positions and find the maximum distance between positions.
// -> set low = 0 and high = maximum distance and peroform binary search.
// -> check if the k number of cows can accomodate in the positions array at a distance of mid or not.
// -> Is possible then move low to mid+1 in order to find maximum possible distance else put high = mid-1;

// # Complexity
// - Time complexity:
// O(nlogn) + O(log2(arr[n-1] - arr[0]) * O(n))

// - Space complexity:
// O(1)

class Solution {
  public:
    bool can_we_place(vector<int> &stalls, int mid, int k){
        int n = stalls.size();
        int cnt = 1;
        int last = stalls[0];
        for(int i = 1; i<n; i++){
            if(stalls[i] - last >= mid){
                last = stalls[i];
                cnt++;
            }
            if(cnt >= k){
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int low = 0;
        int high = stalls[n-1] - stalls[0];
        while(low <= high){
            int mid = (low + high)/2;
            if(can_we_place(stalls, mid, k) == true){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
};
