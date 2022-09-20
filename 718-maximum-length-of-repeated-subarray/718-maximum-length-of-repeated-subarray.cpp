class Solution {
public:
    
    vector<int> slice( vector<int> &a, int s, int l ){
        vector<int> temp;
        for ( int i = s; i<s+l; i++ )  temp.push_back(a[i]);
        return temp;
    }
    
    bool check( int length, vector<int> &nums1, vector<int> &nums2, int n, int m ){
        map<vector<int>,bool> p;
        for ( int i = 0; i<n-length+1; i++ )    p[ slice(nums1,i,length) ] = true;
        for ( int i = 0; i<m-length+1; i++ )    if ( p[ slice(nums2,i,length) ] ) return true;
        return false;
    }
  
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size(), m = nums2.size();
        int l = 0, h = min(n,m)+1, ans = 0;
        while ( l < h ){
            int mid = l + (h-l)/2;
            if ( check(mid,nums1,nums2,n,m) ){
                ans = mid;
                l = mid + 1;
            }
            else h = mid;
        }
        return ans;
    }
};