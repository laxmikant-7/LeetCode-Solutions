class Solution {
public:

    bool isprime(int n){
        if(n <= 1) return false;

        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }

        return true;
    }

    int minJumps(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int, vector<int>> divisible;
        int mx = *max_element(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){

            for(int d = 1; d * d <= nums[i]; d++){

                if(nums[i] % d == 0){
                    divisible[d].push_back(i);
                    if(d != nums[i] / d){
                        divisible[nums[i] / d].push_back(i);
                    }
                }
            }
        }

        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int steps = 0;
        unordered_set<int> usedPrime;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int idx = q.front();
                q.pop();
                if(idx == n - 1) return steps;
                if(idx - 1 >= 0 && !vis[idx - 1]){
                    vis[idx - 1] = 1;
                    q.push(idx - 1);
                }
                if(idx + 1 < n && !vis[idx + 1]){
                    vis[idx + 1] = 1;
                    q.push(idx + 1);
                }

                int val = nums[idx];
                if(isprime(val) && !usedPrime.count(val)){

                    usedPrime.insert(val);

                    for(int nextIdx : divisible[val]){

                        if(!vis[nextIdx]){
                            vis[nextIdx] = 1;
                            q.push(nextIdx);
                        }
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};