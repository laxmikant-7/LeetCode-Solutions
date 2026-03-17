class Solution {
public:
    int countCommas(int n) {
        if(n<1000) return 0;
        int total=0;
        for(int i=1000;i<=n;i++){
        int no_digits=(int)log10(i)+1;
        if(no_digits%3==0){
            total+=(no_digits/3)-1;
        }
        else{
            total+=no_digits/3;
        }
        }
        return total;
    }
};