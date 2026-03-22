class Solution {
public:
    // bool isthere1(vector<int> &nums,int i){
    //     int n=nums.size();
    //     for(int j=0;j<n;j++){
    //         if(j==i) continue;
    //         if(abs((nums[i]-nums[j]))%2==0) return true;
    //     }
    //     return false;
    // }
    // bool isthere2(vector<int> &nums,int i){
    //     int n=nums.size();
    //     for(int j=0;j<n;j++){
    //         if(j==i) continue;
    //         if(abs((nums[i]-nums[j]))%2==1) return true;
    //     }
    //     return false;
    // }
    bool uniformArray(vector<int>& nums1) {
        // int n=nums1.size();
        // bool even=true;
        // bool odd=true;
        // for(int i=0;i<n;i++){
        //     if(nums1[i]%2==0) continue;
        //     else{
        //         if(isthere1(nums1,i)) continue;
        //         else{
        //             even=false;
        //             break;
        //         }
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     if(nums1[i]%2==1) continue;
        //     else{
        //         if(isthere2(nums1,i)) continue;
        //         else{
        //             odd=false;
        //             break;
        //         }
        //     }
        // }
        
        // return (even || odd);
        return true;
    }
};