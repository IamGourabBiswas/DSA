class Solution {
public:
    string reorganizeString(string s) {
        int hash[26] = {0};

        // Count frequency
        for(int i = 0; i < s.size(); i++){
            hash[s[i] - 'a']++;
        }

        // Find max frequency character
        char max_freq_char;
        int max_freq = INT_MIN;

        for(int i = 0; i < 26; i++){
            if(hash[i] > max_freq){
                max_freq = hash[i];
                max_freq_char = i + 'a';
            }
        }

        int index = 0;

        // Place max frequency char at even indices
        while(max_freq > 0 && index < s.size()){
            s[index] = max_freq_char;
            max_freq--;
            index += 2;
        }

        // If still left → not possible
        if(max_freq != 0){
            return "";
        }

        hash[max_freq_char - 'a'] = 0;

        // Fill remaining characters
        for(int i = 0; i < 26; i++){
            while(hash[i] > 0){
                if(index >= s.size()){
                    index = 1;
                }
                s[index] = i + 'a';
                index += 2;
                hash[i]--;   // IMPORTANT
            }
        }

        return s;   // IMPORTANT
    }
};