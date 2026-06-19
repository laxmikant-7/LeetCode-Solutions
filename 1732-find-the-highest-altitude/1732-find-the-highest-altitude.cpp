class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest=0;
        int pre=0;
        int n=gain.size();
        for(int i=0;i<n;i++){
            int g=gain[i]+pre;
            highest=max(highest,g);
            pre=g;
        }
        return highest;
    }
};