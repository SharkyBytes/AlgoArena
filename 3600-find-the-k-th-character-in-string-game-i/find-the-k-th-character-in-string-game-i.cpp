class Solution {
public:

string next(string s){
    string temp="";
    for(auto it : s){
        if(it=='z'){
            temp+='a';
        }
        else{
        temp+= (it+1);
        }
    }

    return temp;
}
    char kthCharacter(int k) {

        string s="a";

        
        while(k>s.length()){
            string ans=next(s);
            s+=ans;           
        }

        return s[k-1];

        
    }
};