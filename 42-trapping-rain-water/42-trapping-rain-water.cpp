class Solution {
public:
    int trap(vector<int>& height) {
        
        int l = INT_MIN, r = INT_MIN, n = height.size();
        vector<int> left(n,0), right(n,0);
        
        for ( int i = 0; i<n; i++ ){
            l = max(l,height[i]);
            left[i] = l;
            r = max(r,height[n-i-1]);
            right[n-i-1] = r;
        }
        
        int ans = 0;
        for ( int i = 0; i<n; i++ ){
            if ( left[i] > height[i] && right[i] > height[i] ){
                int less = min(left[i],right[i]);
                ans += abs(less-height[i]);                
            }
        }
        
        return ans;       
    }
};