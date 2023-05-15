#include <bits/stdc++.h> 
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

    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
    TrieNode* root;
    public:

    Trie(){
        root=new TrieNode();
    }

    void insert(string &word){
        TrieNode* node=root;
        for(int i=0;i<word.length();i++){
          if (!node->containsKey(word[i])) {
            node->put(word[i], new TrieNode());
          }
          node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string &word){
        TrieNode* node=root;
        for(int i=0;i<word.length();i++){
          if (!node->containsKey(word[i])) {
            return false;
          }
          node = node->get(word[i]);
        }
        node->isEnd();
    }

    bool checkAllPrefixExists(string &word){
        TrieNode* node=root;
        for(int i=0;i<word.length();i++){
          if(node->containsKey(word[i])) {
            node=node->get(word[i]);
            if(node->isEnd()==false) return false;
          }else return false;
        }
        return node->isEnd();
    }
};

string completeString(int n, vector<string> &a) {
    Trie* t=new Trie();
    for(auto s:a){
       t->insert(s);
    }
    string ans;
    for(auto s:a){
        if(t->checkAllPrefixExists(s)){
            if(s.length()==ans.length() and ans>s){
                ans=s;
            }else if(ans.length()<s.length()){
                ans=s;
            }
        }
    }
      
    return ans.length()==0?"None":ans;
}
