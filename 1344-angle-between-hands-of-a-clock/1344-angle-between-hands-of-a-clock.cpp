class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hangle=(hour%12)*30+minutes*0.5;
        double mangle=6*minutes;
        double diff=abs(hangle-mangle);
        return min(diff,360.00-diff);
    }
};