class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int col=encodedText.size() / rows;
        vector<vector<char>> grid(rows,vector<char>(col,' '));
        int idx = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < col; j++){
                grid[i][j] = encodedText[idx++];
            }
        }
        string ans;
        for(int start = 0; start < col; start++){
            int i = 0, j = start;

            while(i < rows && j < col){
                ans.push_back(grid[i][j]);
                i++;
                j++;
            }
        }
        int last=ans.size()-1;
        while(!ans.empty() && ans.back() == ' '){
            ans.pop_back();
        }
        return ans;
    }
};