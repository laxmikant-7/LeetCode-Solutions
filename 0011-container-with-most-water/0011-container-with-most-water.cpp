class Solution {
public:
    int maxArea(vector<int>& h) {
        int lf=0,rt=h.size()-1;
        int max_water=INT_MIN;
        while(lf<rt){
            int width=rt-lf;
            int ht=min(h[lf],h[rt]);
            int area=width*ht;
            max_water=max(max_water,area);
            if(h[lf]<=h[rt]){
                lf++;
            }
            else{
                rt--;
            }
        }
        return max_water;
    }
};