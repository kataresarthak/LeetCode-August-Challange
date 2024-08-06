class Solution {
public:
    int minimumPushes(string word) {
        vector<int> hashmap(26,0);
        int n = word.size();
        for(int i = 0; i < n; i++){
            hashmap[word[i] - 'a']++;
        }
        sort(hashmap.begin(), hashmap.end(), greater<int>());
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < 26;i++){
            if(i % 8 == 0)
                sum++;
            ans += (hashmap[i]*sum);
        }
        return ans;
    }
};