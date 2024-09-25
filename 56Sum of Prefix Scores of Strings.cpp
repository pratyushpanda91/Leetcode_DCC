#include <string>
#include <vector>

class Solution {
    class Trie {
        class node {
            public:
                int ew, cp;
                node* next[26];
                node() {
                    ew = 0;
                    cp = 0;
                    for (int i = 0; i < 26; i++) {
                        next[i] = nullptr;
                    }
                }
        };

        node *trie;

        public:
            Trie() {
                trie = new node();
            }

            void insert(const string& word) {
                node *it = trie;
                for (char ch : word) {
                    if (it->next[ch - 'a'] == nullptr) {
                        it->next[ch - 'a'] = new node();
                    }
                    it = it->next[ch - 'a'];
                    it->cp++;
                }
                it->ew++;
            }

            int getPrefCount(const string& word) {
                node *it = trie;
                int cnt = 0;
                for (char ch : word) {
                    if (it->next[ch - 'a'] == nullptr) {
                        return 0;
                    }
                    it = it->next[ch - 'a'];
                    cnt += it->cp;
                }
                return cnt;
            }
    };

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie t;
        for (const auto& word : words) {
            t.insert(word);
        }
        vector<int> ans(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            ans[i] = t.getPrefCount(words[i]);
        }
        return ans;
    }
};
