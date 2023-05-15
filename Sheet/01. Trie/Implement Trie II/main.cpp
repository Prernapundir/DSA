#include <bits/stdc++.h> 
class TrieNode{
    public:
    TrieNode* links[26];
    int wordCount=0;
    int prefixCount=0;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    void put(char ch,TrieNode* newNode){
        links[ch-'a']=newNode;
    }

    TrieNode* get(char ch){
        return links[ch-'a'];
    }

    void increaseWordCount(){
        wordCount++;
    }

    void decreaseWordCount(){
        wordCount--;
    }

    void decreasePrefixCount(){
        prefixCount--;
    }

    int getWordCount(){
        return wordCount;
    }

    int getPrefixCount(){
        return prefixCount;
    }

    void increasePrefixCount(){
        prefixCount++;
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
            if(!node->containsKey(word[i])){
                node->put(word[i],new TrieNode());
            }
            node->increasePrefixCount();
            node=node->get(word[i]);
        }
        node->increaseWordCount();
    }

    int countWordsEqualTo(string &word){
        int count=0;
        TrieNode* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->getWordCount();
    }

    int countWordsStartingWith(string &word){
        int count=0;
        TrieNode* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->getPrefixCount();
    }

    void erase(string &word){
        TrieNode* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return;
            }
            node->decreasePrefixCount();
            node=node->get(word[i]);
        }
        return node->decreaseWordCount();
    }
};
