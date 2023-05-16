/* Approach 
1. While inserting into the trie , just count for the substrings 
*/

class TrieNode{
    public:
    TrieNode* links[26];

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch,TrieNode* newNode){
        links[ch-'a']=newNode;
    }

    TrieNode* get(char ch){
        return links[ch-'a'];
    }
};

class Trie{
    private:
    TrieNode* root;
    public:

    Trie(){
        root=new TrieNode();
    }

    int insert(string &word){
        int count=0;
        TrieNode* node=root;

        for(int i=0;i<word.length();i++){
            node=root;
            for(int j=i;j<word.length();j++){
                if (!node->containsKey(word[j])) {
                    count++;
                    node->put(word[j], new TrieNode());
                }
                node = node->get(word[j]);
            }
        }
        return count+1;
    }
};

int countDistinctSubstrings(string &s) {
    Trie* t=new Trie();
    return t->insert(s);
}
