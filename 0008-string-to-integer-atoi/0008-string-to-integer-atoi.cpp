class Solution {
public:
    int myAtoi(string s) {
        int num = 0, i = 0, sign = 1;

        // Skip leading spaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Handle sign
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '+') ? 1 : -1;
            i++;   // FIX: move past sign
        }

        // Convert digits
        while (i < s.size() && isdigit(s[i])) {

            // Check overflow
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && s[i] > '7')) {
                return (sign == -1) ? INT_MIN : INT_MAX;
            }

            num = num * 10 + (s[i] - '0');
            i++;
        }

        return num * sign;
    }
};