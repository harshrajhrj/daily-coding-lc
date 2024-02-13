class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto w : words)
            if (checkPali(w))
                return w;
        return "";
    }

    bool checkPali(string w) {
        int n = w.size();
        for (int i = 0; i < n / 2; i++)
            if (w[i] != w[n - i - 1])
                return false;
        return true;
    }
};