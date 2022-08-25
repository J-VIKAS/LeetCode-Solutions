class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        map<char,int> freq1,freq2;
        for (int i = 0; i<ransomNote.size(); i++ ) freq1[ ransomNote[i] ]++;
        for (int i = 0; i<magazine.size(); i++ ) freq2[ magazine[i] ]++;
        for (char i = 'a'; i<='z'; i++ ){
            if ( freq1[i] > 0 && freq1[i] > freq2[i] ){
                return false;
            }
        }
        return true;
    }
};