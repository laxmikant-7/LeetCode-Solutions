class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int total=0;
        int c1=-1;
        int c2=-1;
        int c3=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='a') c1=i;
            else if(s[i]=='b') c2=i;
            else c3=i;

            if((c1!=-1 && c2!=-1) && (c2!=-1 && c3!=-1)){
                int minIdx=min(c1,min(c2,c3));
                total+=minIdx+1;
            }
        }
        return total;
    }
};