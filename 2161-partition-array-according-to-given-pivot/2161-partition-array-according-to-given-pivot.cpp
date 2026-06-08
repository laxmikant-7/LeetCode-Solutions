class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        int pc=0;
        vector<int> temp;
        for(auto num:nums){
            if(num<pivot){
                temp.push_back(num);
            }
            else if(pivot==num) pc++;
        }
        for(int i=0;i<pc;i++){
            temp.push_back(pivot);
        }
        for(auto num:nums){
            if(num>pivot) temp.push_back(num);
        }
        return temp;
    }
};