class Solution {
public:
    long long calculateScore(vector<string>& s, vector<int>& arr) {

        int n=arr.size();
       
        vector<int> visit(n, 0);

        long long ans=0;
        int i=0;

        while(i>=0 && i< n && visit[i]==0){
            if(s[i]=="jump"){
                visit[i]=1;

                i= i+arr[i];
            }
            else if(s[i]=="add"){
                visit[i]=1;
                ans+=arr[i];
                i++;
            }
        }

        return ans;

        
    }
};