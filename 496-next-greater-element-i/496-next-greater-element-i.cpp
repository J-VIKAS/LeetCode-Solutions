class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        map<int,int> ind;
        for ( int i = 0; i<nums2.size(); i++ ){
            ind[ nums2[i] ] = i;
        }
        for ( int i = 0; i<nums1.size(); i++ ){
            int k = -1;
            for ( int j = ind[ nums1[i] ] + 1; j<nums2.size(); j++ ){
                if ( nums2[j] > nums1[i] ){
                    k = nums2[j];
                    break;
                }
            }
            ans.push_back(k);
        }
        return ans;
    }
};