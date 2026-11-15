class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int M=(1e9)+7;
        int n=arr.size();
        long long ans=0;
        int odd_cnt=0;
        int even_cnt=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            ans+=(sum%2==0) ? odd_cnt:even_cnt;
            ans%=M;
            if(sum%2==0){
                even_cnt++;
            }
            else{
                odd_cnt++;
            }
        }
        return ans;
    }
};