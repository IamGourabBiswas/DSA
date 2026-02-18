class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1 || numRows >= s.size())
            return s;

        vector<string> zigzag(numRows);

        int row = 0;
        bool goingDown = true;

        for(int i = 0; i < s.size(); i++){

            zigzag[row].push_back(s[i]);

            if(row == 0)
                goingDown = true;
            else if(row == numRows - 1)
                goingDown = false;

            if(goingDown)
                row++;
            else
                row--;
        }

        string ans = "";

        for(int i = 0; i < numRows; i++){
            ans += zigzag[i];
        }

        return ans;
    }
};
