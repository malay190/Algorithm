// Online C++ compiler to run C++ program online
#include <btis/stdc++.h>
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode *> children;
    bool isEndOfWord;

    TreeNode()
    {
        isEndOfWord = false;
    }
}

class Trie
{

    TrieNode *root;

public:
    trie()
    {
        root = new TrieNode();
    }

    // insertion in Trie
    void insertNode(const string &word)
    {
        TrieNode *current = root;

        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
            {
                current->children[ch] = new TrieNode();
                ;
            }
            current = current->children[ch];
        }
        current->isEndOfWord = true;
    }

    // searching in Trie
    void searchNode(const string &word)
    {
        TrieNode *current = root;

        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
            {
                return false;
            }
            currrent = current->childre[ch];
        }
        return current->isEndOfWord;
    }
    // pre fix serach
    bool startsWith(const string &prefix)
    {
        TrieNode *currentNode = root;
        for (char ch : prefix)
        {
            if (currentNode->children.find(ch) == currentNode->children.end())
            {
                return false; // Prefix not found
            }
            currentNode = currentNode->children[ch];
        }
        return true; // Prefix found
    }
}
