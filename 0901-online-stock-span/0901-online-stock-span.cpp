class StockSpanner {
public:
    vector<int> temp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        temp.push_back(price);
        int ans=0;
        int i=temp.size()-1;
        while(i>=0 && temp[i]<=price){
            ans++;
            i--;
        }
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */