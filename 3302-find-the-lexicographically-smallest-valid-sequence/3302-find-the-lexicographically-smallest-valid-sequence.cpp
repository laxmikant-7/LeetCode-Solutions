class Solution {
public:
    vector<int> validSequence(string w1, string w2) {
        int n1=w1.size();
        int n2=w2.size();
        vector<int> temp(n2,-1);
        int j=n2-1;
        for(int i=n1-1;i>=0;i--){
            if(j>=0 && w1[i]==w2[j]){
                temp[j]=i;
                j--;
            }
        }
        vector<int> ans;
        j=0;
        int skip=0;
        for(int i=0;i<n1;i++){
            if(j>=n2) break;
            if(w1[i]==w2[j] || (skip==0 && (j==n2-1 || i<temp[j+1]))){
                ans.push_back(i);
                skip+=(w1[i]!=w2[j])?1:0;
                j++;
            }
        }
        return (j<n2)?vector<int>():ans;
    }
};