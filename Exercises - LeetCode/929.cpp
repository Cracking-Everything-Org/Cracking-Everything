class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        if(emails.size()==0) return 0;
        unordered_set<string> hs;
        for(auto e : emails){
            for(int i=0; i< e.length(); i++){
                string res;
                while((e[i]!='+' && e[i]!='@') && i<e.length()) {
                    if(e[i]!='.') res+=e[i];
                    i++;
                }
                while(e[i]!='@' && i<e.length()) i++;
                res+= e.substr(i, e.length()-1);
                if(hs.find(res) == hs.end()){
                    hs.insert(res);
                }break;
            }
        }
        return hs.size();
    }
};
