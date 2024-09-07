class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //n^2;
        //n
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<pair<int,int>> dp(n,{0,-1});
        int max_ans= 0;
        int max_ind = 0;
        for(int i = 0;i<n;i++){
            for(int j =i-1;j>=0;j--){
                if(nums[i]%nums[j]==0){
                    if(dp[i].first<dp[j].first+1){
                        dp[i].first=dp[j].first+1;
                        dp[i].second = j;
                    }
            }
            if(max_ans<dp[i].first){
                max_ans = dp[i].first;
                max_ind = i;
            }
        }
    }
    vector<int> ans;
    for(int i = max_ind;i!=-1;i=dp[i].second){
        ans.push_back(nums[i]);   
    }
    reverse(ans.begin(),ans.end());
    return ans;
    }
};
