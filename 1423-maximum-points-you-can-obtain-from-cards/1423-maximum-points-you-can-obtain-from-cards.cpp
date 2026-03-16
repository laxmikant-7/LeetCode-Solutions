class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int lsum=0;
        int rsum=0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        int idx1=k-1;
        int idx2=n-1;
        int score=lsum;
        while(idx1>=0){
            lsum-=cardPoints[idx1];
            rsum+=cardPoints[idx2];
            score=max(score,lsum+rsum);
            idx1--;
            idx2--;
        }
        return score;
    }
};