class Solution {
public:
    void find_prev_small(vector<int>& arr,vector<int>& prev_small){
        stack<pair<int,int>> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && st.top().first>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                prev_small[i]=-1;
            }
            else{
                prev_small[i]=st.top().second;
            }
            st.push({arr[i],i});
        }
    }
    void find_next_small(vector<int>& arr,vector<int>& next_small){
        stack<pair<int,int>> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && st.top().first>arr[i]){
                st.pop();
            }
            if(st.empty()){
                next_small[i]=arr.size();
            }
            else{
                next_small[i]=st.top().second;
            }
            st.push({arr[i],i});
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long sum=0;
        long long M=1e9+7;
        vector<int> prev_small(n);
        vector<int> next_small(n);
        find_prev_small(arr,prev_small);
        find_next_small(arr,next_small);
        for(int i=0;i<n;i++){
        int freq=(i-prev_small[i])*(next_small[i]-i);
        sum=(sum+(long long)freq*arr[i])%M;
        }
        return (int)sum;
    }
};