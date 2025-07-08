class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& p) {
        map<int,int> mp;
        sort(arr.begin(), arr.end());
        for(auto it :arr){
            mp[it[0]]++;
            mp[it[1]]--;

        }
        mp[p[0]]++;
        mp[p[1]]--;
        int cnt=0;
        vector<vector<int>> ans;
        // ans.push_back({arr[0][0], arr[0][1]});
        int st=0;

        for(auto& [time, val] : mp){
            if(cnt==0){
                st=time;
            }
            cnt+=val;
            if(cnt==0){
                ans.push_back({st,time});
            }

        }
return ans;
        
    }
};