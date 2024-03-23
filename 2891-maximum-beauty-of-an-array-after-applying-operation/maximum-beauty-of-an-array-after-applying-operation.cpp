class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        int n = nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[ nums[i]-k ]++;
            m[ nums[i]+k+1 ]--;
        }

        int sz = m.size();
        vector<int> pre(sz);
        int p = 0 ;
        for(auto it:m)
        {
            if(p==0) pre[0] = it.second;
            else pre[p] = pre[p-1] + it.second;
            p++;
        }
        return *max_element(pre.begin(),pre.end());
    }
};