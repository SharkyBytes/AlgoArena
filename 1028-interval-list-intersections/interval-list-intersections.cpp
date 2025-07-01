class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {

        int i=0;
        int j=0;
        vector<vector<int>> ans;
        while(i<first.size() && j< second.size() ){

            int maxi=max(first[i][0], second[j][0]);
            int mini =min(first[i][1], second[j][1]);
            if(maxi<=mini){
                ans.push_back({maxi,mini});

            }
            if(first[i][1]<second[j][1]){
                i++;
            }

            else
            j++;
        }

        return ans;
        
    }
};