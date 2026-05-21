class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> s;
        for(auto num:arr1){
            while(num>0){
                s.insert(num);
                num/=10;
            }
        }
        int ans=0;
        for(auto num:arr2){
            while(num>0){
                if(s.count(num)){
                    int c=log10(num);
                    ans=max(ans,c+1);
                    break;
                }
                else{
                    num/=10;
                }
            }
        }
        return ans;
    }
};