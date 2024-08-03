class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> elementCounts(1001, 0);
        int uniqueCount = 0;
        for (int i = 0; i < target.size(); i++) {
            if (elementCounts[target[i]]++ == 0)
                uniqueCount++;
            if (elementCounts[arr[i]]-- == 1)
                uniqueCount--;
        }
        return uniqueCount == 0;
    }
};