// # Intuition
// <!-- Describe your first thoughts on how to solve this problem. -->
// -> First thought is a mountain always have a peek and two bottom ends.
// -> So if the mid lies between any bottom end and the peek then we can trim the range.
// # Approach
// <!-- Describe your approach to solving the problem. -->
// -> There are three variables low, mid and high.
// -> low points at the 0th index and the high at (n-1) index.
// -> if the value mid+1 index is greater than the mid then put low = mid+1.
// -> else if the value mid-1 index is greater than the mid then put high = mid-1.
// -> if both the cases are not true then mid points at the peek of the mountain.
// # Complexity
// - Time complexity:
// O(logn)

// - Space complexity:
// O(1)


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans = -1;
        int n = arr.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(arr[mid] < arr[mid+1]){
                low = mid+1;
            }

            // this statement means arr[mid] > arr[mid+1]
            // so we check for the mid-1 else, mid is the ans.
            else{
                if(arr[mid-1] > arr[mid]){
                    high = mid - 1;
                }
                else{
                    ans = mid;
                    break;
                }
            }
        }
        return ans;
    }
};
