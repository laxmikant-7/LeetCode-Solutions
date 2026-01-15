class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int count1=1;
        int count2=1;
        int v_max=1;
        int h_max=1;
        for(int i=0;i<v.size()-1;i++){
            if(v[i+1]==v[i]+1){
                count1++;
            }
            else{
                count1=1;
            }
            v_max=max(v_max,count1);
        }
        for(int i=0;i<h.size()-1;i++){
            if(h[i+1]==h[i]+1){
                count2++;
            }
            else{
                count2=1;
            }
            h_max=max(h_max,count2);
        }
        int side=min(h_max,v_max)+1;
        return side*side;  
    }
};