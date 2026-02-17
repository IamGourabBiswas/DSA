class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.size() != t.size())
            return false;

        int hash[256] = {0};
        bool istCharsMapped[256] = {false};

        for (int i = 0; i < s.size(); i++) {

            if (hash[s[i]] == 0 && istCharsMapped[t[i]] == false ) {
                hash[s[i]] = t[i];
                istCharsMapped[t[i]] = true;
            }
        }

        for (int i = 0; i < s.size(); i++) {
            if (char(hash[s[i]]) != t[i]) {
                return false;
            }
        }

        return true;
    }
};