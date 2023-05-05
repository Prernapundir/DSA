
/* Approach
1. Plain level wise bfs , here we have to store sequences in the queueu for all the levels and one by one take the sequence and pop the last word from the sequenec 
taked out and f=generate the words and push into the queue until didn't reach to the endWord
2. But it will give the TLE on leetcode , can be submitted on GFG
*/

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        vector<vector<string>> ans;
        q.push({beginWord});

        while(!q.empty()){
            int size=q.size();

            while(size--){
                auto f=q.front();
                q.pop();
                
                //erasing all the words that has been used in the previous levels
                for(auto x:f){
                    st.erase(x);
                }
                
                // take the last word of the sequenec
                string word=f.back();

                
                if(word==endWord){
                  //first time reached the end
                    if(ans.size()==0){
                        ans.push_back(f);
                    }else if(ans[0].size()==f.size()){
                        ans.push_back(f);
                    }
                }
                
              // iterate over all the changed words
                for(int i=0;i<word.length();i++){
                    string temp=word;
                    for(char ch='a';ch<='z';ch++){
                       temp[i]=ch;
                       if(st.count(temp)){
                           f.push_back(temp);  // put the word into the sequence
                           q.push(f);   // put into the queue
                           f.pop_back(); // pop the word from the sequence
                       }
                    }
                }
            }
        }

        return ans;
    }
};
