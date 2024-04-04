class Solution {
public:
    int minimumLevels(vector<int>&a) {
        int n=a.size();
       int total=0;
        for(auto &i:a){
            if(i==0)total--;
            else total++;
        }
       int now=0,ans=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){total++;now--;}
            else {now++;total--;}
            ans++;
            if(now>total)break;
        }
        if(ans==a.size())return -1;
        return ans;
    }
};