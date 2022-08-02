class MapSum {
public:
    
    struct Node{
        Node* links[26];
        int sum = 0;
        bool flag = false;
        bool containsKey(char ch){
            return links[ch-'a'] != NULL;
        }
        void put(char ch, Node* node){
            links[ch-'a'] = node;
        }
        Node* get(char ch){
            return links[ch-'a'];
        }
        void add(int value){
            sum += value;
        }
        int getsum(){
            return sum;
        }
        void setsum(int val){
            sum = val;
        }
        void setflag(){
            flag = true;
        }
        bool getflag(){
            return flag;
        }
    };
    
    class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(string word, int val){
            Node* node = root;
            for ( int i = 0; i<word.size(); i++ ){
                if ( !node->containsKey(word[i]) ){
                    node->put(word[i],new Node());
                }
                node = node->get(word[i]);
                node->add(val);
            }
            node->setflag();
        }
        bool check(string word){
            Node* node = root;
            for ( int i = 0; i<word.size(); i++ ){
                if ( !node->containsKey(word[i]) ){
                    return false;
                }
                node = node->get(word[i]);
            }
            return node->getflag();
        }
        int sum(string word){
            Node* node = root;
            for ( int i = 0; i<word.size(); i++ ){
                if ( !node->containsKey(word[i]) ){
                    node->put(word[i],new Node());
                }
                node = node->get(word[i]);
            }
            return node->getsum();
        }   
    };
    
    Trie node;
    map<string,int> get_value;
    
    MapSum() {
    }
    
    void insert(string key, int val) {
        int prev_val = get_value[key];
        get_value[key] = val;
        if ( node.check(key) ){
            val = val - prev_val;
        }
        
        node.insert(key,val);
    }
    
    int sum(string prefix) {
        return node.sum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */