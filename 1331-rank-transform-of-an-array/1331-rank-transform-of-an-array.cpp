class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> m;
        int idx=1;
        for(int i=0;i<n;i++){
            if(m.find(temp[i])==m.end()){
                m[temp[i]]=idx;
                idx++;
            }
        }
        for(int i=0;i<n;i++){
            arr[i]=m[arr[i]];
        }
        return arr;
    }
};