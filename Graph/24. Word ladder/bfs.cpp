/* Approach 
1. Start withe the begin word and check for all the alphabets for changing only one word at a time , and then check for that word in map 
2. if present , push it in the queue and so on
3. So simple bfs will work 
*/


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int count=1;
        queue<string> q;
        q.push(beginWord);

        unordered_map<string,bool> m;
    
        for(auto word:wordList){
            m[word]=true;
        }

        while(!q.empty()){
            int size=q.size();

            while(size--){
                string f=q.front();
                q.pop();
     
                // change all the alphabets of the worrd one by one
                for(int i=0;i<f.length();i++){
                    string temp=f;

                    for(char ch='a';ch<='z';ch++){
                        temp[i]=ch;
                        if(m.find(temp)!=m.end() and m[temp]){
                            if(temp==endWord){
                                return ++count;
                            }
                            q.push(temp);
                            m[temp]=false;
                        }
                    }  
                }
            }
            count++;
        }

        return 0;
    }
};
                        
