class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set <string> st ( wordList.begin(), wordList.end());

        queue<pair<string, int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string word= q.front().first;
            int lev=q.front().second;
            if(word==endWord){
                return lev;
            }
            q.pop();
            for(int i=0; i<word.length(); i++){
                char ch=word[i];
                for(int j=0; j<26; j++){
                    word[i]=j+'a';
                    if(st.find(word)!=st.end()){
                        q.push({word, lev+1});
                        st.erase(word);
                    }
                    
                }
                word[i]=ch;
            }
        }

        return 0;
    }
};