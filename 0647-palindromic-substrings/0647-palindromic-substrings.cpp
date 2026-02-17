class Solution {
public:
    int expandAroundIndex(string s, int i, int j) {
        int count = 0;  // ✅ Initialize count
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            count++;  // Found one palindrome
            i--;      // Expand to the left
            j++;      // Expand to the right
        }
        return count;
    }

    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            // Odd-length palindromes (center at i)
            count += expandAroundIndex(s, i, i);

            // Even-length palindromes (center between i and i+1)
            count += expandAroundIndex(s, i, i + 1);
        }
        return count;
    }
};
