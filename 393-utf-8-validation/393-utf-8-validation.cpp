class Solution {
public:

    bool validUtf8(vector<int>& data) {
        
        int total = 0;
        for ( int i = 0; i<data.size(); i++ ){
            if ( data[i] >> 3 == 31  ) return false;
            else if ( data[i] >> 4 == 15 ) total += 3;
            else if ( data[i] >> 5 == 7 ) total += 2;
            else if ( data[i] >> 6 == 3 ) total += 1;
            else if ( data[i] >> 7 == 1 ) total -= 1;
        }
        return total == 0;
            
    }
};