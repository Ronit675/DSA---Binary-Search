// # Intuition
// <!-- Describe your first thoughts on how to solve this problem. -->
// -> First thought is to find the range in which the target element may lie.

// # Approach
// <!-- Describe your approach to solving the problem. -->
// -> To find the range we first compare if leftmost element is smaller or equal to the middle element or not. 
//   -> if smaller then compare if target is smaller than low and greater than mid because that is the only sorted range in this case then 
//     the target lies in left range.
//   -> else target element lies in right range.
// -> else if the leftmost element is bigger then mid than compare
//   -> if the target is greater then mid and lower then high because that is the only sorted range in this case.
//   -> else the target lies in left range.

// # Complexity
// - Time complexity:
// O(logn)

// - Space complexity:
// O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && nums[mid] >= target){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if(nums[mid] <= target && nums[high] >= target){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};
