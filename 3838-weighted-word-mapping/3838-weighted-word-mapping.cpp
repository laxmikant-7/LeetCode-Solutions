class Solution {
public:
    int find_sum(string &word,vector<int> &weights){
        int sum=0;
        for(auto ch:word){
            sum+=weights[ch-'a'];
        }
        return sum;
    }
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        vector<char> mapping;
        for(int i='z';i>='a';i--){
            mapping.push_back(i);
        }
        for(auto word:words){
            int sum=find_sum(word,weights);
            sum%=26;
            ans+=mapping[sum];   
        }
        return ans;
    }
};