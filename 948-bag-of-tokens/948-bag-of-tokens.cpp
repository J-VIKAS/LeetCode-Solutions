class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n = tokens.size(), score = 0, ans = 0;
        sort(tokens.begin(),tokens.end());
        int i = 0, j = n-1;
        while ( i <= j ){
            if ( power >= tokens[i] ){
                power -= tokens[i];
                score += 1;
                i++;
            } else if ( score >= 1 ) {
                power += tokens[j];
                score -= 1;
                j--;
            } else {
                break;
            }
            ans = max(ans,score);
        }
        return ans;
    }
};