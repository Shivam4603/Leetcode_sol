class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
        }
        
        long long int ans=0;
        unordered_map<int,int>mp;
        int i=0,j=0;
        mp[mx]=0;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp[mx]==k){
                while(mp[mx]==k){
                    ans=ans+nums.size()-1-j+1;// (n-1)-j for extra and +1 for that subarray
                    if(nums[i]==mx){
                        mp[mx]--;
                    }
                    // cout<<i<<" ";
                    i++;
                }
                j++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};