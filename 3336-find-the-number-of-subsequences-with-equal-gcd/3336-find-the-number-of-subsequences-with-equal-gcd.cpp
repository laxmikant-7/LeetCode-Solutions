class Solution {
public:
    int M=1e9+7;
    // long long solve(int i,int seq1,int seq2,vector<int>& nums){
    //     if(i==nums.size()){
    //         return (seq1!=0 && seq2!=0 && seq1==seq2)?1:0;
    //     }
    //     if(dp[i][seq1][seq2]!=-1) return dp[i][seq1][seq2];

    //     long long skip=solve(i+1,seq1,seq2,nums);
    //     long long take1=(seq1==0)?solve(i+1,nums[i],seq2,nums):solve(i+1,gcd(seq1,nums[i]),seq2,nums);
    //     long long take2=(seq2==0)?solve(i+1,seq1,nums[i],nums):solve(i+1,seq1,gcd(seq2,nums[i]),nums);

    //     return dp[i][seq1][seq2]=(skip+take1+take2)%M;

    // }
    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<vector<int>> prev(maxi+1,vector<int>(maxi+1,0));
        for(int seq1=0;seq1<=maxi;seq1++){
            for(int seq2=0;seq2<=maxi;seq2++){
                prev[seq1][seq2]=(seq1!=0 && seq2!=0 && seq1==seq2)?1:0;
            }
        }
        for(int i=n-1;i>=0;i--){
            vector<vector<int>> curr(maxi+1,vector<int>(maxi+1,0));
            for(int seq1=0;seq1<=maxi;seq1++){
                for(int seq2=0;seq2<=maxi;seq2++){
                    int skip=prev[seq1][seq2];
                    int take1=prev[gcd(seq1,nums[i])][seq2];
                    int take2=prev[seq1][gcd(seq2,nums[i])];
                    curr[seq1][seq2]=(0LL+skip+take1+take2)%M;
                }

            }
            swap(prev,curr);

        }
        return prev[0][0];
    }
};