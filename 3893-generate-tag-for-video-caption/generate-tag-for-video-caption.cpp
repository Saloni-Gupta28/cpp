class Solution {
public:
    string generateTag(string caption) {
         vector<string> words;
    stringstream ss(caption);
    string word;
        while (ss >> word) {
        words.push_back(word);
    }

    string result = "#";
    for (size_t i = 0; i < words.size(); ++i) {
        if (words[i].empty()) continue;
       string temp;
        temp += (i == 0) ? tolower(words[i][0]) : toupper(words[i][0]);
        for (size_t j = 1; j < words[i].size(); ++j) {
            temp += tolower(words[i][j]);
        }
        result += temp;
    }

    return result.substr(0, 100);
    }
};