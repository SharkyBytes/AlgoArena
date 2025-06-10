class Solution {
public:
    int maxDifference(string s) {

        int n=s.length();
        vector<int> arr(26,0);
        for(int i=0; i< n; i++){
            arr[s[i]-'a']++;
        }

        int odd=INT_MIN;
        int eve=INT_MAX;

        for(auto it: arr){
            if(it!=0){
            if(it%2==0){
                eve=min(eve,it);

            }
            else{
                odd=max(odd, it);
            }
            }
        }

        return odd-eve;

    }
};