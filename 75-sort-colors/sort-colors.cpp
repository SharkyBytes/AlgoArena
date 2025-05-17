class Solution {
public:
    void sortColors(vector<int>& arr) {

        map<int,int> mp;
        for(auto it: arr){
            mp[it]++;
        }
vector<int> ans;
        for(auto it : mp){
            while(it.second>0){
                ans.push_back(it.first);
                it.second--;
            }
        }
        arr=ans;
        // return ans;
        
    }
};