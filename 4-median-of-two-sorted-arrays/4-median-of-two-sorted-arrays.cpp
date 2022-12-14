class Solution {
public:
    
    int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k){
        if ( n > m )
            return kthElement(arr2, arr1, m, n, k);
        int low = max(0,k-m), high = min(k,n);
        while ( low <= high ){
            int cut1 = low + (high-low)/2;
            int cut2 = k - cut1;
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n ? INT_MAX : arr1[cut1];
            int r2 = cut2 == m ? INT_MAX : arr2[cut2];
            if ( l1 <= r2 && l2 <= r1 ) return max(l1,l2);
            else if ( l1 > r2 )     high = cut1 - 1;
            else    low = cut1 + 1;
        }
        return 1;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if ( (n+m)%2 == 0 ){
            return (float)(kthElement(nums1,nums2,n,m,(n+m)/2 + 1) + kthElement(nums1,nums2,n,m,(n+m)/2))/2;
        } else {
            return kthElement(nums1,nums2,n,m,(n+m)/2 + 1);
        }
        
    }
};