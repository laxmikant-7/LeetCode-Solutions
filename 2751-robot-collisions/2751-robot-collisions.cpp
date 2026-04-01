class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& h, string dir) {
        int n = pos.size();
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({pos[i], i});
        }
        sort(temp.begin(), temp.end());
        stack<int> st; 
        for(auto &p : temp){
            int i = p.second;
            while(!st.empty() && dir[st.top()] == 'R' && dir[i] == 'L'){    
                if(h[st.top()] < h[i]){
                    h[i]--;
                    h[st.top()] = 0;
                    st.pop();
                }
                else if(h[st.top()] > h[i]){
                    h[st.top()]--;
                    h[i] = 0;
                    break;
                }
                else{
                    h[st.top()] = 0;
                    h[i] = 0;
                    st.pop();
                    break;
                }
            }
            if(h[i] > 0){
                st.push(i);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(h[i] > 0){
                ans.push_back(h[i]);
            }
        }
        return ans;
    }
};