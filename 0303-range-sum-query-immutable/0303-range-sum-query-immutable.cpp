class NumArray {
public:
    int n;
    vector<int> segtree;
    void buildst(int i,int l,int r,vector<int> &segtree,vector<int> &nums){
        if(l==r){
            segtree[i]=nums[l];
            return;
        }
        int mid=l+(r-l)/2;
        buildst(2*i+1,l,mid,segtree,nums);
        buildst(2*i+2,mid+1,r,segtree,nums);
        segtree[i]=segtree[2*i+1]+segtree[2*i+2];
        return;
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        segtree.resize(nums.size()*4);
        buildst(0,0,n-1,segtree,nums);
    }
    int qsum(int i,int ql,int qr,int nl,int nr,vector<int> & segtree){
        if(qr<nl || ql>nr) return 0;
        if(ql<=nl && nr<=qr) return segtree[i];
        int mid=nl+(nr-nl)/2;
        return qsum(2*i+1,ql,qr,nl,mid,segtree)+qsum(2*i+2,ql,qr,mid+1,nr,segtree);
    }
    int sumRange(int left, int right) {
        return qsum(0,left,right,0,n-1,segtree);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */