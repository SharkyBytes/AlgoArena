class Solution {
public:
    int findPairs(vector<int>& arr, int k) {

        int n=arr.size();
        map<int,int> mp;
        for(int i=0; i< arr.size(); i++){
            mp[arr[i]]=i;
        }


        set<pair<int,int>> st;

        for(int i=0; i< n; i++){
            int x= k+arr[i];
            if(mp.find(x)!=mp.end() && mp[x]!=i && st.find({arr[i],x})==st.end()){
             
                st.insert({arr[i],x});
            }
        }

        return st.size();
        
    }
};