class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr1;
        vector<int> arr2;
        vector<int> res;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            int last_arr1=arr1[arr1.size()-1];
            int last_arr2=arr2[arr2.size()-1];
            if(last_arr1>last_arr2){
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }
        int idx=0;
        while(idx<arr1.size()){
            res.push_back(arr1[idx]);
            idx++;
        }
        idx=0;
        while(idx<arr2.size()){
            res.push_back(arr2[idx]);
            idx++;
        }
        return res;
    }
};