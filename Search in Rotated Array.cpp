// # Intuition
// <!-- Describe your first thoughts on how to solve this problem. -->
// -> First thought is to find the range in which the target element may lie.

// # Approach
// <!-- Describe your approach to solving the problem. -->
// -> To find the range we first compare if leftmost element is smaller or equal to the middle element or not. 
//   -> if smaller then check if target is smaller than low and greater than mid because that is the only sorted range in this case then 
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

            // left range is sorted
            if(nums[low] <= nums[mid]){
                // target is between low and mid element i.e. left range
                if(nums[low] <= target && nums[mid] >= target){
                    high = mid-1;
                }

                // target is between mid and high
                else{
                    low = mid+1;
                }
            }

            //right range is sorted
            else{
                // target is between mid and high elemnt i.e. right range
                if(nums[mid] <= target && nums[high] >= target){
                    low = mid+1;
                }
                // target is between low and mid.
                else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};
