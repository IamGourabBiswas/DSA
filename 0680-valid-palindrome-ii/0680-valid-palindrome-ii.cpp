// class Solution {
// public:
//     bool checkPlaindrom(string s, int i ,int j ){
//         while(i <= j){
//           if(s[i] != s[j]){
//             return false;
//           }
//           i++;
//           j--;
                
//         }
//         return true ;
//     }
//     bool validPalindrome(string s) {
//         int i = 0;
//         int j = s.length()-1 ;
//          while (i<=j){
//             if(s[i] != s[j]){
//                 return checkPlaindrom(s,i+1,j) || checkPlaindrom(s,i,j-1);

//             }
//             else{
//                 i++;
//                 j--;


//             }
//          } 

//         return true ; 
        
//     }
// };
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                // try skipping either s[i] or s[j]
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            }
            i++;
            j--;
        }
        return true;
    }

private:
    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }
};
