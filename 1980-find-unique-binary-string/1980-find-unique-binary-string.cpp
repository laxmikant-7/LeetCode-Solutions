class Solution {
public:
    string find_ans(int n,int l){
        string ans(l,'0');
        int idx=l-1;
        while(n>0){
            char rem=(n&1)?'1':'0';
            n=n>>1;
            ans[idx]=rem;
            idx--;
        }
        return ans;
    }
    int find(string &s){
        int num=0;
        int p=1;
        for(int i=s.size()-1;i>=0;i--){
            num+=((s[i]-'0')*p);
            p=p<<1;
        }
        return num;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        vector<int> temp;
        for(auto num:nums){
            int dec=find(num);
            temp.push_back(dec);
        }
        sort(temp.begin(),temp.end());
        int missing=n;
        for(int i=0;i<n;i++){
            if(i!=temp[i]){
                missing=i;
                break;
            }
        }
        string ans=find_ans(missing,n);
        return ans;
    }
};