class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> v;
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        while ( i < n && j < m ){
            if ( nums1[i] <= nums2[j] ){
                v.push_back(nums1[i++]);
            } else {
                v.push_back(nums2[j++]);
            }
        }
        while ( i < n ){
            v.push_back(nums1[i++]);
        }
        while ( j < m ){
            v.push_back(nums2[j++]);
        }
        
        if ( (n+m)%2 == 0 ){
            return (float)( v[ (n+m)/2 ] + v[ (n+m)/2 - 1 ] )/2;
        } else {
            return v[ (n+m)/2 ];
        }
        
    }
};