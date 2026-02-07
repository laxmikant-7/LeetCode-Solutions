class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int counts=n;
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        int no_bs=0;
        int no_as=0;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                m1[i]=no_bs;
                no_bs++;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='b'){
                m2[i]=no_as;
            }
            else{
                no_as++;
            }
        }
        int j=0;
        while(s[j]=='b' && j<n){
            j++;
        }
        if(j==n){
            return 0;
        }
        for(;j<n;j++){
            if(s[j]=='b'){
                counts=min(counts,m1[j]+m2[j]);
            }
        }
        return (counts==n)?0:counts;
    }
};