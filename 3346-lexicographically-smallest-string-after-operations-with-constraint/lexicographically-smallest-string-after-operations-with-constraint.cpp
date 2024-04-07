class Solution {
public:
    string getSmallestString(string s, int k) {
       int n = s.size();

        for (int i = 0; i < n; i++) {
            // Calculate the distance to 'a' from the current character
            int distance_forward = s[i] - 'a';
            // Calculate the distance to 'a' from the opposite end
            int distance_backward = ('z' - s[i]) + 1;
            // Choose the minimum of the two distances
            int min_distance = min(distance_forward, distance_backward);

            // If the minimum distance is less than or equal to remaining k
            if (min_distance <= k) {
                // Reduce k by the chosen distance
                k -= min_distance;
                // Set the current character to 'a'
                s[i] = 'a';
            } else {
                // If the minimum distance is greater than remaining k
                // Subtract k from the current character to make it the smallest possible character
                s[i] = s[i] - k;
                // Reset k to 0 as no more changes needed
                k = 0;
            }
        }
        return s;
    }
};