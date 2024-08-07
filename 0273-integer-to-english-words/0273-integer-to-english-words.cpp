class Solution {
public:
    unordered_map<int, string> un = {
        {1, "One"},        {2, "Two"},       {3, "Three"},     {4, "Four"},
        {5, "Five"},       {6, "Six"},       {7, "Seven"},     {8, "Eight"},
        {9, "Nine"},       {10, "Ten"},      {11, "Eleven"},   {12, "Twelve"},
        {13, "Thirteen"},  {14, "Fourteen"}, {15, "Fifteen"},  {16, "Sixteen"},
        {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}, {20, "Twenty"},
        {30, "Thirty"},    {40, "Forty"},    {50, "Fifty"},    {60, "Sixty"},
        {70, "Seventy"},   {80, "Eighty"},   {90, "Ninety"}};
    string numberToWords(int num) {
        if (!num)
            return "Zero";
        vector<string> v = {"", "Thousand", "Million", "Billion"};
        string ans = "";
        int count = 0;
        while (num) {
            if (num % 1000)
                ans = v[count] + " " + ans;
            count++;
            if (num % 100 > 19) {
                if (num % 10)
                    ans = un[num % 10] + " " + ans;
                num /= 10;
                num *= 10;
                ans = un[num % 100] + " " + ans;
            }
            else {
                if (num % 100)
                    ans = un[num % 100] + " " + ans;
            }
            num /= 100;
            if (num % 10) {
                ans = un[num % 10] + " Hundred " + ans;
            }
            num /= 10;
        }
        while (ans.size() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};