// # Intuition
// <!-- Describe your first thoughts on how to solve this problem. -->
// -> First Thought is to find how many elements from array1 and array2 will lie at the left side of the merged array.
// -> To check that we need to perform binary search for number of elements from smaller array 
// -> that lie on the left side of the merged array.
// -> Performing binary search on smaller array will result in less number of iterations.

// # Approach
// <!-- Describe your approach to solving the problem. -->
// -> if size of first array is larger than swap the array by calling the function again.
// -> find how many elements will lie at the left side of the merged array.
// -> set low = 0 and high = size of smaller array i.e. first array.
// -> define mid1 for number of elements from first array that will lie on the left side (will come from low and high).
// -> and mid2 for second array.
// -> declare l1 = maximum element of array1 from left.
// -> declare l2 = maximum element of array2 from left. 
// -> declare r1 = minimum element of array1 from right.
// -> declare r2 = minimum element of array2 from right.
// -> The possible values of ‘mid1’ and ‘mid2’ might be 0 and n1 and n2 respectively. 
// -> So, to handle these cases, we need to store some default values for these four variables. 
// -> The default value for l1 and l2 will be INT_MIN and for r1 and r2, it will be INT_MAX.
// -> Now check l1 < r2 or not and l2 < r1 or not if these condition satisy then 
// -> check if sum of sizes of both arrays is odd then return maximum of l1 and l2.
// -> else return (max of l1,l2 + min of r1,r2)/2.
// -> typecase them in double.
// -> If l1 > r2: This implies that we have considered more elements from arr1[] than necessary. 
// -> So, we have to take less elements from arr1[] and more from arr2[]. 
// -> In such a scenario, we should try smaller values of x. To achieve this, we will eliminate the right half (high = mid1-1).
// -> and vice versa if l2 > r1 then low = mid + 1.

// # Complexity
// - Time complexity:
// O(Log(Min(N1,N2)))

// - Space complexity:
// O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2){
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int left = (n1 + n2 + 1)/2;
        int low = 0;
        int high = n1;
        int n = n1 + n2;
        while(low <= high){
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;
            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;
            if(mid1 < n1){
                r1 = nums1[mid1];
            }
            if(mid2 < n2){
                r2 = nums2[mid2];
            }
            if(mid1 - 1 >= 0){
                l1 = nums1[mid1 -1];
            }
            if(mid2 - 1 >= 0){
                l2 = nums2[mid2 - 1];
            }
            if(l1 <= r2 && l2 <= r1){
                if(n%2 == 0){
                    return (double)(max(l1, l2) + min(r1, r2))/2.0;
                }
                return max(l1, l2);
            }
            else if(l1>r2){
                high = mid1-1;
            }
            else{
                low = mid1 +1;
            }
        }
        return 0;
    }
};
