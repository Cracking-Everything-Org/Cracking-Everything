class Solution {
public:
    string defangIPaddr(string address) {
        string defangedIP = "";
        for (int i = 0; i < address.length(); i++) {
            if (address[i] == '.')
                defangedIP += "[.]";
            else 
                defangedIP += address[i];
        }
        return defangedIP;
    }
};


/*
class Solution {
public:
    string defangIPaddr(string address) {
        string defangedIP = "";
        for (int i = 0; i < address.length(); i++) {
            defangedIP += address[i] == '.' ? "[.]" : address[i];
        }
        return defangedIP;
    }
};
*/