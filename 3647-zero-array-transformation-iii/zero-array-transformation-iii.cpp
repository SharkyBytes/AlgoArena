class Solution {
public:
    int maxRemoval(vector<int>& arr, vector<vector<int>>& q) {

        int n=arr.size();
        int cnt=0;
        priority_queue<int, vector<int> , greater<int> > used;
        priority_queue<int> avail;
        sort(q.begin(), q.end());
        int st=0;

        for(int i=0; i< n; i++){
            while(st<q.size() && q[st][0]==i){
                avail.push(q[st][1]);
                st++;
            }

          
                arr[i]-=used.size();
           

            while(avail.size()>0 && arr[i]>0 && avail.top()>=i){
                used.push(avail.top());
                avail.pop();
                arr[i]-=1;
                cnt+=1;
            }

            if(arr[i]>0){
             return -1;
            }

            while(used.size()>0 && used.top()==i){
                used.pop();
            }


        }

        return q.size()-cnt;



        
    }
};