class Solution {
public:
    
    void check(int start, vector<int> nums, long long int val, int n, int a, int b, vector<vector<int>> &ans){
        vector<int> num;
        for ( int i = start; i<n; i++ ){
            num.push_back(nums[i]);
        }
        sort(num.begin(),num.end());
        
        int m = num.size();
        int i = 0, j = m-1;
        while ( i < j ){
            if ( num[i]+num[j] == val ){
                vector<int> arr = {a,b,num[i],num[j]};
                if ( arr.size() == 4 ){
                    sort(arr.begin(),arr.end());
                    bool check = false;
                    for ( int k = 0; k<ans.size(); k++ ){
                        if ( ans[k] == arr ){
                            check = true;
                            break;
                        }
                    }
            
                    if ( !check ){
                        ans.push_back(arr);
                    }
                }
                j--;
            } else if ( num[i]+num[j] > val ){
                j--;
            } else {
                i++;
            }
        }
        
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        long long total = target;
        long long int sum = 0;
        int n = nums.size();
        vector<vector<int>> ans;
        for ( int i = 0; i<n-3; i++ ){
            for ( int j = i+1; j<n-2; j++ ){
                long long int val = total - nums[i] - nums[j];
                check(j+1,nums,val,n,nums[i],nums[j],ans);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
