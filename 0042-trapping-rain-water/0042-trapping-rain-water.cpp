class Solution {
public:

    int trap(vector<int>& height) {
        int n=height.size();
        int total=0;
        vector<int> preMax(n);
        vector<int> suffMax(n);
        preMax[0]=height[0];
        suffMax[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            preMax[i]=max(height[i],preMax[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suffMax[i]=max(height[i],suffMax[i+1]);
        }

        for(int i=0;i<n;i++){
            total+=min(preMax[i],suffMax[i])-height[i];
        }
        return total;
    }
};