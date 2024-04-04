class Solution {
public:
    int maxDepth(string s) {
        int n = s.size(), depth = 0, count = 0;
        for(auto it : s){
            if(it == '(')
                count++;
            else if(it == ')'){
                depth = max(depth, count);
                count--;
            }
        }
        return depth;
    }
};