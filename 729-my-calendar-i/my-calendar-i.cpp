class MyCalendar {
public:
    vector<pair<int,int>> ans;

    MyCalendar() {

    }
    
    bool book(int startTime, int endTime) {

        for(auto it : ans){
            int st=it.first;
            int en=it.second;
            if(max(st,startTime)<min(endTime, en))return false;
            
        }
        ans.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */