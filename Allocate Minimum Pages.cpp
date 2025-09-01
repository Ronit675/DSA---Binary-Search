// # Intuition
// <!-- Describe your first thoughts on how to solve this problem. -->
// -> First thought was to find that number which is smallest possible maximum.
// -> The Range in which this number can lie is between the max of array and sum of array.

// # Approach
// <!-- Describe your approach to solving the problem. -->
// -> To solve this using binary search we need to define the low and high.
// -> the lowest possible number of pages can be maximum of array and highest can be the sum of array.
// -> now create a function which will check how many students are required to take mid number of pages.
// -> If the number of students is greater than the given k then move low = mid+1.
// -> which means low is too less number for the number of pages to be assigned.
// -> If the number of students is less or equal to k then move high = mid-1.
// -> which means there are chances of another less number that may fall between low and mid-1.

// # Complexity
// - Time complexity:
// O(logn)

// - Space complexity:
// O(1)

class Solution {
  public:
    int check(vector<int> &arr, int n, int no){
        int student = 1;
        int sum = 0;
        for(int i = 0; i<n; i++){

            // add to the sum if less than no
            if(sum + arr[i] <= no){
                sum += arr[i];
            }

            // else assign new number to sum from which the count of pages will start and increase student count 
            else{
                student++;
                sum = arr[i];
            }
        }
        return student;
    }
    int findPages(vector<int> &arr, int k) {
        int n = arr.size();

        //if number of books is less than k
        if(n<k){
            return -1;
        }

        // find sum and maximum and set them low and high
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
            
            // check for the number of students who can accomodate this number of pages
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
