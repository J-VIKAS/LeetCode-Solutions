class Solution {
public:
    
    struct Node{
        Node* links[2];
        bool containsKey(int bit){
            return links[bit] != NULL;
        }
        void put(int bit, Node* node){
            links[bit] = node;
        }
        Node* get(int bit){
            return links[bit];
        }
    };
    
    class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(int num){
            Node* node = root;
            for ( int i = 30; i>=0; i-- ){
                int bit = (num >> i) & 1;
                if ( !node->containsKey(bit) ){
                    node->put(bit,new Node());
                }
                node = node->get(bit);
            }
        }
        int MaxXOR(int num){
            int XOR = 0;
            Node* node = root;
            for ( int i = 30; i>=0; i-- ){
                int bit = (num >> i) & 1;
                if ( node->containsKey(!bit) ){
                    XOR = XOR ^ (1 << i);
                    node = node->get(!bit);
                } else {
                    node = node->get(bit);
                }
            }
            return XOR;
        }
    };
    
    int findMaximumXOR(vector<int>& nums) {
        
        Trie node;
        for ( int i = 0; i<nums.size(); i++ ){
            node.insert(nums[i]);
        }
        
        int ans = INT_MIN;
        for ( int i = 0; i<nums.size(); i++ ){
            ans = max(ans,node.MaxXOR(nums[i]));
        }
        
        return ans;
    }
};