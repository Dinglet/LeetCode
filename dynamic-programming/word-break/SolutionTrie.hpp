// https://leetcode.com/problems/word-break/
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    bool is_word;
    TrieNode *next(char c)
    {
        if (!children.contains(c))
            return nullptr;
        return children[c];
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie() = delete;
    Trie(const Trie &) = delete;
    Trie &operator=(const Trie &) = delete;

    Trie(const vector<string> &words)
    {
        root = new TrieNode();
        for (const auto &word : words)
        {
            TrieNode *node = root;
            for (char c : word)
            {
                if (!node->children.contains(c))
                    node->children[c] = new TrieNode();
                node = node->children[c];
            }
            node->is_word = true;
        }
    }

    ~Trie()
    {
        stack<TrieNode *> nodes;
        if (root != nullptr)
            nodes.push(root);
        while (!nodes.empty())
        {
            TrieNode *node = nodes.top();
            nodes.pop();
            for (const auto &[_, child] : node->children)
                nodes.push(child);
            delete node;
        }
    }
};

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<bool> dp(s.size() + 1);
        Trie trie(wordDict);
        dp.front() = 1;
        for (int i = 0; i < dp.size(); ++i)
        {
            if (!dp[i])
                continue;
            TrieNode *node = trie.root;
            for (int j = 0; i + j < s.size() && node != nullptr; ++j)
            {
                node = node->next(s[i + j]);
                if (node != nullptr && node->is_word)
                    dp[i + j + 1] = true;
            }
        }

        return dp.back();
    }
};
