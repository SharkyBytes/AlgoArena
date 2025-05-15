class Solution {
public:


    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& arr) {

        int n=arr.size();
        bool flag=false;
        int first=arr[0];

        vector<int> ans;
        for(int i=0; i< n; i++){
            if(flag==0 && arr[i]==first){
                ans.push_back(i);
                flag=1;
            }
            else if (flag==1 && arr[i]!=first){
                ans.push_back(i);
                flag=0;
            }

        }

        vector<string>final;
        for(auto it : ans){
            final.push_back(words[it]);
        }

        return final;
        
    }
};