class NumArray {
public:
    int n;
    vector<int> bit;
    vector<int> num;
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        num = nums;
        bit = vector<int>(n+1,0);
        for ( int i = 0; i<n; i++ ){
            int index = i+1;
            while ( index <= n ){
                bit[index] += nums[i];
                index += index & (-index);
            }
        }
    }
    
    void update(int index, int val){
        int prev = num[index];
        num[index] = val;
        index += 1;
        while ( index <= n ){
            bit[index] += (val-prev);
            index += index & (-index);
        }
    }
    
    int sumRange(int left, int right) {
        right += 1;
        int sumr = 0, suml = 0;
        while ( right > 0 ){
            sumr += bit[right];
            right -= right & (-right);
        }
        while ( left > 0 ){
            suml += bit[left];
            left -= left & (-left);
        }
        return sumr - suml;
    }
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */