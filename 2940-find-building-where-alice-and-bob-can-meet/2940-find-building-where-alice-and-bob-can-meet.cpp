class Solution {
public:
    void buildsegtree(int i,int l,int r,vector<int>& h,vector<int>& segtree){
        if(l==r){
            segtree[i]=l;
            return;
        }
        int mid=l+(r-l)/2;
        buildsegtree(2*i+1,l,mid,h,segtree);
        buildsegtree(2*i+2,mid+1,r,h,segtree);
        int a=segtree[2*i+1];
        int b=segtree[2*i+2];
        if(h[a]>=h[b]) segtree[i]=a;
        else segtree[i]=b;
        return;
    }
    int find(int i,int ql,int qr,int nl,int nr,vector<int> &segtree,const vector<int>& h){
        if(nr<ql || nl>qr) return -1;
        if(nl>= ql && nr<=qr) return segtree[i];
        int mid=nl+(nr-nl)/2;
        int left=find(2*i+1,ql,qr,nl,mid,segtree,h);
        int right=find(2*i+2,ql,qr,mid+1,nr,segtree,h);
        if(left==-1 && right==-1) return -1;
        else if(left==-1) return right;
        else if(right==-1) return left;
        return (h[left]>h[right])?left:right;
    }
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        int n=h.size();
        vector<int> segtree(4*n,-1);
        buildsegtree(0,0,n-1,h,segtree);
        vector<int> ans;
        for(auto &it:q){
            int curridx=INT_MAX;
            sort(it.begin(),it.end());
            if(it[0]==it[1]){
                ans.push_back(it[0]);
                continue;
            }
            if(h[it[1]]>h[it[0]]){
                ans.push_back(it[1]);
                continue;
            }
            int l=it[1]+1;
            int r=n-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                int maxidx=find(0,l,mid,0,n-1,segtree,h);
                if(h[maxidx]>h[it[0]] && h[maxidx]>h[it[1]]){
                    curridx=min(curridx,maxidx);
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            if(curridx==INT_MAX) ans.push_back(-1);
            else ans.push_back(curridx);
        }

        return ans;
    }
};