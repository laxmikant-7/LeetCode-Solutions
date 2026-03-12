class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    vector<int> hash(256, -1);
    int left = 0, right = 0;
    int maxLen = 0, currLen = 0;
    while (right < s.length()) {

        if (hash[s[right]] != -1) {
            if (hash[s[right]] >= left) {
                left = hash[s[right]] + 1;
            }
        }
        currLen = right - left + 1;
        maxLen = max(maxLen, currLen);

        hash[s[right]] = right;
        right++;
    }
    return maxLen;
}
};
