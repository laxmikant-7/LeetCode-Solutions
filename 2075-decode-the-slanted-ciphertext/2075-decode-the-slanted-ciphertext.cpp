class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        if(n == 0) return "";

        int col = n / rows;
        string ans;
        for(int start = 0; start < col; start++){
            int i = 0, j = start;

            while(i < rows && j < col){
                ans.push_back(encodedText[i * col + j]);
                i++;
                j++;
            }
        }
        while(!ans.empty() && ans.back() == ' '){
            ans.pop_back();
        }

        return ans;
    }
};