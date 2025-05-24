class Solution {
public:
    vector<int> findWordsContaining(vector<string>& s, char x) {
int n=s.size();
        vector<vector<int>> arr(n,  vector<int> (26,0));
vector<int> ans;
       for(int i=0; i< n ; i++){
        for(auto it: s[i]){
            arr[i][it-'a']++;
        }
        if(arr[i][x-'a']>0){
            ans.push_back(i);
            


        }
       }

       return ans;
    }
};