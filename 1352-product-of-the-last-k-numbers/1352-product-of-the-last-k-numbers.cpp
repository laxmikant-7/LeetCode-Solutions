class ProductOfNumbers {
public:
    vector<int> temp;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        temp.push_back(num);
    }
    
    int getProduct(int k) {
        int ans=1;
        int n=temp.size();
        for(int i=n-k;i<n;i++){
            ans*=(temp[i]);
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */