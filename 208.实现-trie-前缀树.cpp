/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
class Trie {
private:
    vector<Trie *> children;
    bool isEnd;

    Trie *searchPrefix(string &word) {
        Trie *node = this;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                return nullptr;
            }
            node = node->children[index];
        }
        return node;
    }
public:
    Trie() : children(26), isEnd(false) {

    }
    
    void insert(string word) {
        Trie *node = this;
        for (char ch : word) {
            int index = ch - 'a';
            if (!node->children[index]) {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie *node = this->searchPrefix(word);
        return node && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

