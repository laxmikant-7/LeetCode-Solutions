class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int ansChar=letters[0];
        for(int i=1;i<letters.size();i++){
            if(letters[i]>target){
                ansChar=letters[i];
                break;
            }
        }
        return ansChar;
    }
};