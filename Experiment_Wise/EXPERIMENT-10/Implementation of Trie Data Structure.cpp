#include <iostream>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word into Trie
    void insert(string word) {
        TrieNode* current = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';

            if (current->children[index] == NULL)
                current->children[index] = new TrieNode();

            current = current->children[index];
        }

        current->isEndOfWord = true;
    }

    // Search full word
    bool search(string word) {
        TrieNode* current = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';

            if (current->children[index] == NULL)
                return false;

            current = current->children[index];
        }

        return current->isEndOfWord;
    }

    // Check prefix
    bool startsWith(string prefix) {
        TrieNode* current = root;

        for (int i = 0; i < prefix.length(); i++) {
            int index = prefix[i] - 'a';

            if (current->children[index] == NULL)
                return false;

            current = current->children[index];
        }

        return true;
    }
};
