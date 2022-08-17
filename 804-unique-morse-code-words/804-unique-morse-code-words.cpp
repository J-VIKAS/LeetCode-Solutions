class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> p = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> ans;
        for ( int i = 0; i<words.size(); i++ ){
            string a = "";
            for ( int j = 0; j<words[i].size(); j++ ){
                a += p[ words[i][j] - 'a' ];
            }
            ans.insert(a);
        }
        
        return ans.size();
    }
};