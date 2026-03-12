class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();

        vector<pair<double, pair<int,int>>> ans;

        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                ans.push_back({(double)arr[i] / arr[j], {arr[i], arr[j]}});
            }
        }

        sort(ans.begin(), ans.end());

        return {ans[k-1].second.first, ans[k-1].second.second};
    }
};