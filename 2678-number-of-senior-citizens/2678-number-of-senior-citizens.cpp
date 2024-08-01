class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for (string detail: details) {
            string age = { detail[11], detail[12] };
            if (age > "60") {
                count++;
            }
        }
        return count;
    }
};