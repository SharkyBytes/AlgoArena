class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
vector<string> ans;
int n=s.length();
        for(int i=0; i< n; i+=k){
            if(n-i<k){
                int len=k- (n-i);
                string p=s.substr(i);
                string q;
                for(int i=0; i< len; i++){
                    q.push_back(fill);
                }
                ans.push_back(p+q);
            }
            else{
                ans.push_back(s.substr(i,k));
            }
        }
        return ans;
    }
};