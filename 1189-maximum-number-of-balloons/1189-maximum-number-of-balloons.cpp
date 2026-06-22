class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m;
        m['b']=0;
        m['a']=0;
        m['l']=0;
        m['o']=0;
        m['n']=0;
        for(auto ch:text){
            m[ch]++;
        }
        if(m['l']%2==1) m['l']--;
        if(m['o']%2==1) m['o']--;
        m['l']=m['l']/2;
        m['o']=m['o']/2;
        int min1=min(m['b'],m['a']);
        int min2=min(m['l'],m['o']);
        int min3=min(min1,m['n']);
        return min(min2,min3);
    }
};