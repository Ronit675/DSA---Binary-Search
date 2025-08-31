// # Intuition
// <!-- Describe your first thoughts on how to solve this problem. -->
// -> First thought is that first element of pair should be at even index position and second element should be at odd index position.
// -> ORDER = odd, even;
// -> Compare the mid and trim the range accordingly.

// # Approach
// <!-- Describe your approach to solving the problem. -->
// -> if size of array is 1 then return that element
// -> if first element of array is not equal to second then return first element.
// -> if the last element of the array is not equal to the second last then return the last element.
// -> if these conditions are not met then perform binary search.
// -> Check IF mid element is eqaul to its adjacent elements or not. if not then return mid element and break the loop.
// -> ELSE, Check if mid+1 element is equal to mid or not, If equal then check:
//   -> if order is satisfied this means single element is disturbing the order after mid+1 then trim the search window by assigning low = mid+1.
//   -> else single element is disturbing the order before mid-1 then assign high = mid-1.
// -> If above case is not fulfilled then check if mid-1 element is equal to mid or not, If equal then check the same conditions mentioned above.


// # Complexity
// - Time complexity:
// O(logn)

// - Space complexity:
// O(1)
  
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n-2;
        int ans = -1;

        //if array size is 1
        if(n == 1){
            ans = nums[n-1];
            return ans;
        }

        //if first element is single
        if(nums[low] != nums[low-1]){
            ans = nums[low-1];
            return ans;
        }

        // if last element is single
        if(nums[high+1] != nums[high]){
            ans = nums[high+1];
            return ans;
        }
        while(low <= high){
            int mid = (low+high)/2;

            //if mid element is single
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                ans = nums[mid];
                break;
            }

            //if element after mid element is equal
            if(nums[mid] == nums[mid+1]){
                // order satisfied
                if(mid%2 == 0 && (mid+1)%2 == 1){
                    low = mid+1;
                }
                //order not satisfied
                else{
                    high = mid-1;
                }
            }

            // if element before mid element is equal
            if(nums[mid] == nums[mid-1]){
                // order satisfied
                if(mid%2 == 1 && (mid-1)%2 == 0){
                    low = mid+1;
                }
                //order not satisfied
                else{
                    high = mid-1;
                }
            }
        }
        return ans;
    }
};
