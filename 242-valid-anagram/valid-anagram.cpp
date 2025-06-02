class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;

        unordered_map<char,int>mp;
        unordered_map<char,int>cp;

        for(auto it: s){
            mp[it]++;
        }

        for(auto it: t){
            cp[it]++;
        }

        if(mp!=cp) return false;
        return true;

    }
};