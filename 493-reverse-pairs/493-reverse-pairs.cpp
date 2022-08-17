class Solution {
public:
    
    int ans = 0;

    int merge( vector<int> &a, int si, int mid, int ei ){
        
        int count = 0, j = mid+1;
        for ( int i = si; i<=mid; i++ ){
            while ( j <= ei && a[i] > (long)2*a[j] ){
                j++;
            }
            count += (j-(mid+1));
        }

        vector<int> m(ei-si+1);
        int x = 0, s1 = si, s2 = mid+1;
        while ( s1 <= mid && s2 <= ei ){
            if ( a[s1] < a[s2] ){
                m[x++] = a[s1++];
            } else {
                m[x++] = a[s2++];
            }   
        }

        while ( s1 <= mid ){
            m[x++] = a[s1++];
        }   

        while ( s2 <= ei ){
            m[x++] = a[s2++];
        }

        int i = 0;
        for ( int j = si; j<=ei; j++ ){
            a[j] = m[i];
            i += 1;
        }
        
        return count;
    }

    int divide( vector<int> &a, int si, int ei ){

        if ( si >= ei ){
            return 0;
        }

        int mid = si + (ei - si)/2;
        int count = divide(a, si, mid);
        count += divide(a, mid+1, ei);
        count += merge(a, si, mid, ei);
        
        return count;

    }
    
    int reversePairs(vector<int>& nums) {
        return divide(nums,0,nums.size()-1);
    }
};