class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') 
                str += s[i] + 32;
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
                str += s[i];
        }
        int l = 0, r = str.size() - 1;
        cout << str << endl;
        while (l < r) {
            cout << str[l] << " " << str[r] << endl;
            if (str[l] != str[r]) 
                return false;
            else {
                l++;
                r--;
            }
        }
        return true;
    }
};
