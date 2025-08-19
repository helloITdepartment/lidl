#include <set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++) {
            set<char> chars;
            int currentLen = 0;
            for (int j = i; j < s.length(); j++) {
                if (chars.contains(s[j])) {
                    maxLen = max(maxLen, currentLen);
                    break;
                } else {
                    chars.insert(s[j]);
                    currentLen++;
                }
                maxLen = max(maxLen, currentLen);
            }
        }
        return maxLen;
    }
};
