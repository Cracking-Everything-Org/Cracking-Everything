class Solution {
public:
    string toGoatLatin(string S) {
        stringstream ss(S); // necesito un stringstrem para leer
        string word;
        string result;
        int index = 1; // agrego 1 'a' por cada index de palabra

        while(getline(ss, word, ' ')) { // agarro cada palabra
            if (isVowel(word[0])) {
                word += "ma";
            } else {
                word += word[0];
                word += "ma";
                word = word.substr(1);
            }

            string temp(index, 'a');
            index++;
            word += temp;

            result += word + " ";
        }

        result.pop_back(); // borro el ultimo espacio

        return result;
    }

    bool isVowel(char ch) {
        /* Deberia hacer algo como esto para ser mas clean y tener espacio constante
        vector<bool> vowels(26);
        vowles['a' - 'a'] = true;
        vowles['e' - 'a'] = true;
        vowles['i' - 'a'] = true;
        vowles['o' - 'a'] = true;
        vowles['u' - 'a'] = true;

        bool isVowel(char ch) {
            ch = tolower(ch);
            return vowels[ch - 'a'];
        }
        */

        ch = tolower(ch);
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }




};
