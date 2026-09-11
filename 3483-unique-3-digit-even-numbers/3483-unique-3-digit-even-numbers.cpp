class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans=0;
        int n=digits.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && i!=k){
                        int num=digits[i]*100 + digits[j]*10 + digits[k];
                        if(num%2==0 && num>99 && s.find(num)==s.end()){
                            s.insert(num);
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};