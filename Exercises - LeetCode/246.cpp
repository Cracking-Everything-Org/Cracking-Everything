class Solution {
public:
    bool isStrobogrammatic(string num){
        unordered_map<int, int> ht;
        ht[0] = 0;
        ht[1] = 1;
        ht[6] = 9;
        ht[8] = 8;
        ht[9] = 6;

        for (int i = 0; i <= num.length() / 2 ; i++) {
            if (ht.find(num[i] - '0') == ht.end()) {
                return false;
            }
            int a = ht[num[i] - '0'];
            int b = (num[num.length() - 1 - i]) - '0';
            if (ht[num[i] - '0'] != (num[num.length() - 1 - i]) - '0') {
                return false;
            }
        }
        return true;
    }
};

#include<iostream>

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int left = 0;
        int right = num.size() - 1;
        unordered_map<char, char> hm;
        hm['0'] = '0';
        hm['1'] = '1';
        hm['6'] = '9';
        hm['9'] = '6';
        hm['8'] = '8';
        while (left <= right) {
            if (hm[num[left]] != num[right]) return false;
            left++; 
            right--;
        }
        return true;
    }
};