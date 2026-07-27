class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {
        int n1=s1.size();
        int n2=s2.size();
        int i=0;
        int j=0;
        vector<vector<int>> temp;
        while(i<n1 && j<n2){
            int t1=s1[i][0];
            int v1=s1[i][1];
            int t2=s2[j][0];
            int v2=s2[j][1];
            if(t1==t2){
                temp.push_back({t1,v1+v2});
                i++;
                j++;
            }
            else if(t1<t2){
                temp.push_back({t1,v1+v2});
                i++;
            }
            else{
                temp.push_back({t2,v1+v2});
                j++;
            }
        }
        while(i<n1){
            temp.push_back(s1[i]);
            i++;
        }
        while(j<n2){
            temp.push_back(s2[j]);
            j++;
        }
        return temp;
    }
};