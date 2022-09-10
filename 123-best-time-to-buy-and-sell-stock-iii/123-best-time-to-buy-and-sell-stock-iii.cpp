class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> max_profit_left(n,0), max_profit_right(n,0);
        int Min = prices[0], Max = prices[n-1];
        
        for ( int i = 1; i<n; i++ ){
            Min = min(Min,prices[i]);
            max_profit_left[i] = max(prices[i]-Min,max_profit_left[i-1]);
        }
        
        for ( int i = n-2; i>=0; i-- ){
            Max = max(Max,prices[i]);
            max_profit_right[i] = max(Max-prices[i],max_profit_right[i+1]);
        }
        
        // for ( int i = 0; i<n; i++ ){
        //     cout << "i : " << i << " = ";
        //     cout << max_profit_left[i] << ",";
        //     cout << max_profit_right[i] << " \n";
        // }
        
        int ans = 0;
        for ( int i = 0; i<n; i++ ){
            if ( max_profit_left[i] + max_profit_right[i] > ans ){
                ans = max_profit_left[i] + max_profit_right[i];
            }
        }
        
        return ans;
    }
};