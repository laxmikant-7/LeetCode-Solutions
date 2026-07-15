class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddsum=0;
        int evensum=0;
        for(int i=0;i<n;i++){
            oddsum+=2*i+1;
            evensum+=2*i+2;
        }
        return gcd(oddsum,evensum);
    }
};