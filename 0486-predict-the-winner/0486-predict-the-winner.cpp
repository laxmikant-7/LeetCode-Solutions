class Solution {
public:
    int find(vector<int>& nums,int i,int j){
        if(i==j) return nums[i];
        if(i>j) return 0;
        int take_i=nums[i]+min(find(nums,i+2,j),find(nums,i+1,j-1));
        int take_j=nums[j]+min(find(nums,i+1,j-1),find(nums,i,j-2));
        return max(take_i,take_j);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int total_score=0;
        for(auto num:nums) total_score+=num;
        int player1=find(nums,0,n-1);
        int player2=total_score-player1;
        return player1>=player2;
    }
};