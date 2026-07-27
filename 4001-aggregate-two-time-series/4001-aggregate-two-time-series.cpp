class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        int n1=s1.size();
        int n2=s2.size();
        int i=0;
        int j=0;
        unordered_map<int,int> m;
        while(i<n1 && j<n2){
            int t1=s1[i][0];
            int v1=s1[i][1];
            int t2=s2[j][0];
            int v2=s2[j][1];
            if(t1==t2){
                m[t1]+=(v1+v2);
                i++;
                j++;
            }
            else if(t1<t2){
                m[t1]+=(v1+v2);
                i++;
            }
            else{
                m[t2]+=(v1+v2);
                j++;
            }
        }
        while(i<n1){
            m[s1[i][0]]+=s1[i][1];
            i++;
        }
        while(j<n2){
            m[s2[j][0]]+=s2[j][1];
            j++;
        }
        vector<vector<int>> temp;
        for(auto &it:m){
            int time=it.first;
            int val=it.second;
            temp.push_back({time,val});
        }
        sort(temp.begin(),temp.end());
        return temp;
    }
};