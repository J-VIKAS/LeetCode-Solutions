class Solution {
public:
    
    string convert_to_binary( int data ){
        string ans = "";
        stack<char> st;
        while ( data ){
            if ( data%2 == 0 )  st.push('0');
            else    st.push('1');
            data /= 2;
        }
        
        int k = 8-st.size();
        while ( k-- ){
            st.push('0');
        }
        
        while ( !st.empty() ){
            ans += st.top();
            st.pop();
        }
        return ans;       
    }
    
    int ones( string &s ){
        int count = 0;
        for ( int i = 0; i<s.size(); i++ ){
            if ( s[i] == '0' ){
                break;
            }
            count += 1;
        }
        // cout << "s,count = " << s << "," << count << "\n";
        return count;
    }

    bool validUtf8(vector<int>& data) {
        
        int n = data.size(), req = 0;
        for ( int i = 0; i<n; i++ ){
            string bin = convert_to_binary(data[i]);
            int total_ones = ones(bin);
            // cout << "req, total_ones : " << req << "," << total_ones << "\n";
            if ( total_ones > 4 ) return false;
            else if ( req == 0 && total_ones == 1 ){
                return false;
            } else if ( req == 0 && total_ones > 0 ){
                req = total_ones-1;
            } else if ( req > 0 && total_ones != 1 ){
                return false;
            } else if ( req > 0 && total_ones == 1 ) {
                req -= 1;
            }
        }
        
        if ( req == 0 ) return true; 
        return false;
    
    }
};