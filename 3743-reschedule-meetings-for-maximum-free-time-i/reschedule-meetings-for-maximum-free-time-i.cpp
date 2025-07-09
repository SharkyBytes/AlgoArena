class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& s, vector<int>& e) {

        int n=s.size();
        vector<int>  gap(n+1,0);

        sort(s.begin(), s.end());
        sort(e.begin(), e.end());


        gap[0]=s[0];
        for(int i=1; i< n; i++){
            gap[i]=s[i]-e[i-1];
        }
        gap[n]=eventTime-e[n-1];
        
        int i=0; int j=0;
        int maxi=0;
        int sum=0;
        while(j<=k && j<=n){
            sum+=gap[j];
            j++;
        }
        maxi=max(maxi, sum);
        cout<<maxi<<endl;
        j=k;

        while(j<n){
            sum-=gap[i];
            i++;
            j++;
            sum+=gap[j];
            maxi=max(maxi, sum);
        
        }

        return maxi;
    }
};