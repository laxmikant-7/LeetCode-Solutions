class NumArray {
public:
    int n;
    vector<int> segTree;
    void buildST(int i,int l,int r,vector<int>& nums){
        if(l==r){
            segTree[i]=nums[l];
            return;
        }
        int mid=l+(r-l)/2;
        buildST(2*i+1,l,mid,nums);
        buildST(2*i+2,mid+1,r,nums);
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
        return;
    }

    void updateST(int idx,int val,int i,int l,int r){
        if(l==r){
            segTree[i]=val;
            return;
        }
        int mid=l+(r-l)/2;
        if(idx<=mid){
            updateST(idx,val,2*i+1,l,mid);
        }
        else{
            updateST(idx,val,2*i+2,mid+1,r);
        }
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
        return;
    }

    int findrangesum(int left,int right,int l,int r,int i){
        if(r<left || l>right) return 0;
        if(left<=l && right>=r) return segTree[i];
        int mid=l+(r-l)/2;
        return findrangesum(left,right,l,mid,2*i+1)+findrangesum(left,right,mid+1,r,2*i+2);
    }

    NumArray(vector<int>& nums) {
        n=nums.size();
        segTree.resize(4*n,0);
        buildST(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        updateST(index,val,0,0,n-1);
    }
    
    int sumRange(int left, int right) {
        return findrangesum(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */