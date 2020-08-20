class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1Hash = 0;
        int s1Size = s1.size();
        int s2Size = s2.length();
        unordered_map<char,int> s1HM;
        for (int i = 0; i < s1Size; i++) {
            s1Size += s1[i] - 'a';
            if (s1HM.find(s1[i]) != s1HM.end()) s1HM[s1[i]]++;
            else s1HM[s1[i]] = 1;
        }

        int s2Hash = 0;
        int startWindow = 0;

        for (int endWindow = 0; endWindow < s2Size; endWindow++) {
            s2Hash +=  s2[endWindow] - 'a';
            if (endWindow - startWindow + 1 >= s1Size) {
                if (s1Hash == s2Hash && validPermutation(startWindow, endWindow, s2, s1HM)) {
                    return true;
                } else {
                    s2Hash -= s2[startWindow] - 'a';
                    startWindow++;
                }
            }
        }

        return false;
    }

    bool validPermutation(int startWindow, int endWindow, string s2, unordered_map<char,int> s1HM) {
        for (int i = startWindow; i <= endWindow; i++) {
            if (s1HM.find(s2[i]) != s1HM.end() && s1HM[s2[i]] > 0) {
                s1HM[s2[i]]--;
            } else return false;
        }
        return true;
    }
  }
