class Solution {
public:
    int countTriples(int n) {
        int count=0;
        set<int> s;
        for(int i=1;i<=n;i++){
            s.insert(i*i);
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(s.find((i*i)+(j*j))!=s.end()) count++;
            }
        }
        return count*2;
    }
};