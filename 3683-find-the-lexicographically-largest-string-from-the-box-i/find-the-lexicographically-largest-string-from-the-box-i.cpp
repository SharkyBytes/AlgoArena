class Solution {
public:
    string answerString(string words, int maxlen) {

        int j=0;
        int i=0;
        if(maxlen==1){
            return words;
        }
        int n=words.length();
        char ch='a';
        for(auto it: words){
            if(it>ch){
                ch=it;
            }

        }
        int len= n-maxlen+1;
        vector<int> pos;
        for(int i=0; i< n; i++){
            char it=words[i];
            if(it==ch){
                pos.push_back(i);
            }
        }
        string p="a";
        for(int i=0; i<pos.size(); i++){
            int st=pos[i];
           if(words.substr(st,len)>p){
            p=words.substr(st,len);
           }
        }

        return p;
        
    }
};