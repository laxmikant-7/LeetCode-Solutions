class Solution {
public:
    int totalNumbers(vector<int>& d) {
        unordered_set<int> s;
        int n=d.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i==k || i==j || j==k){
                        continue;
                        }
                        int num=(d[i]*100)+(d[j]*10)+(d[k]*1);
                        if(num>=100 && num%2==0) s.insert(num);
                }
            }
        }
        int size=s.size();
        return size;
    }
};