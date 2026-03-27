class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> temp=mat;
        for(int K=0;K<k;K++){
            for(int i=0;i<n;i++){
                if(i%2==0){
                    int first=temp[i][0];
                    temp[i].erase(temp[i].begin());
                    temp[i].push_back(first);
                }
                else{
                    int last=temp[i][m-1];
                    temp[i].pop_back();
                    temp[i].insert(temp[i].begin(),last);
                }
            }
        }
        return temp==mat;
    }
};