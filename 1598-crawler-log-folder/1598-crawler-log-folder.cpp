class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        int value = 0;
        for ( int i = 0; i<logs.size(); i++ ){
            if ( logs[i] == "../" ){
                value -= 1;
                if (value < 0) value = 0;
            } else if ( logs[i] == "./" ){
                value += 0;
            } else {
                value += 1;
            }
        }
        
        return value;
    }
};