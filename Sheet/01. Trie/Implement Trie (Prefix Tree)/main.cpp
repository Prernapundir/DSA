class TrieNode{
    public:
    TrieNode* links[26];
    bool flag=false;

    bool containsKey(char ch){
       return links[ch-'a']!=NULL;
    }

    void put(char ch,TrieNode* newNode){
        links[ch-'a']=newNode;
    }

    TrieNode* get(char ch){
        return links[ch-'a'];
    }

    bool isEnd(){
        return flag;
    }

    void setEnd(){
        flag=true;
    }

};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new TrieNode());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};
