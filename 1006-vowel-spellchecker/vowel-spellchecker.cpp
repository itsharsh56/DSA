#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <cctype>

class Solution {
    std::unordered_set<std::string> words_perfect;
    std::unordered_map<std::string, std::string> words_cap;
    std::unordered_map<std::string, std::string> words_vow;

public:
    std::vector<std::string> spellchecker(std::vector<std::string>& wordlist, std::vector<std::string>& queries) {
        for (const std::string& word : wordlist) {
            words_perfect.insert(word);

            std::string wordlow = toLower(word);
            words_cap.insert({wordlow, word});

            std::string wordlowDV = devowel(wordlow);
            words_vow.insert({wordlowDV, word});
        }

        std::vector<std::string> ans(queries.size());
        for (size_t t = 0; t < queries.size(); ++t)
            ans[t] = solve(queries[t]);
        return ans;
    }

    std::string solve(const std::string& query) {
        if (words_perfect.count(query))
            return query;

        std::string queryL = toLower(query);
        if (words_cap.count(queryL))
            return words_cap[queryL];

        std::string queryLV = devowel(queryL);
        if (words_vow.count(queryLV))
            return words_vow[queryLV];

        return "";
    }

    std::string devowel(const std::string& word) {
        std::string ans;
        for (char c : word) {
            ans += isVowel(c) ? '*' : c;
        }
        return ans;
    }

    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    std::string toLower(const std::string& str) {
        std::string lowerStr;
        for (char c : str) {
            lowerStr += std::tolower(c);
        }
        return lowerStr;
    }
};