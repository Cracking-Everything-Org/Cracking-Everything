class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int indexName = 0;
        int indexTyped = 0;
        while(indexName < name.length() && indexTyped < typed.length()){
            char nameI = name[indexName];
            char typedI = typed[indexTyped];
            int typedCount=0;
            int nameCount =0;
            if(typed[indexTyped] > name[indexName]) return false;
            if(typed[indexTyped] < name[indexName]) return false;
            char toSkip = typed[indexTyped];
            while(typed[indexTyped] == toSkip
                  && indexTyped < typed.length()){
                indexTyped++;
                typedCount++;
            }
            while(name[indexName] == toSkip
                  && indexName < name.length()){
                indexName++;
                nameCount++;
            }
            if(nameCount > typedCount) return false;
        }
        if(indexTyped < typed.length() || indexName < name.length()) return false;
        return true;
    }
};
