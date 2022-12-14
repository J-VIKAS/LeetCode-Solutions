class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int i = 0, j = n-1;
        while ( i <= j ){
            int mid = (i+j)/2;
            if ( nums[mid] == target ){
                return mid;
            } else if ( nums[mid] >= nums[0] && target >= nums[0] && target < nums[mid] ){
                j = mid - 1;
            } else if ( nums[mid] >= nums[0] ){
                i = mid + 1;
            } else if ( nums[mid] <= nums[n-1] && target > nums[mid] && target <= nums[n-1] ){
                i = mid + 1; 
            } else {
                j = mid - 1;
            }
        }
        return -1;
    }
};