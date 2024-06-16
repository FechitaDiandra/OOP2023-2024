#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <initializer_list>
// CECILIA MUSTEATA
using namespace std;

class Trie {
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEndOfWord;
        TrieNode() : isEndOfWord(false) {}
    };

    TrieNode* root;

    void addWord(TrieNode* node, const string& word, int index);
    bool searchWord(TrieNode* node, const string& word, int index);
    bool searchPrefix(TrieNode* node, const string& prefix, int index);
    void removeWord(TrieNode*& node, const string& word, int index);
    void getWords(TrieNode* node, string prefix, vector<string>& result);
    string getLongestCommonPrefix(TrieNode* node);

public:
    Trie();
    Trie(initializer_list<string> words);
    Trie(string word);
    void add(initializer_list<string> words);
    void remove(string s);
    string longestCommonPrefix();
    void push(string word);
    bool empty();
    bool exists(string word);
    void remove(initializer_list<string> words);
    bool existsPrefix(string prefix);
    vector<string> wordsWithPrefix(string prefix);
    bool isLeaf(string word);
    vector<string> all();
    void removePrefix(string prefix);
    int countWordsStartingWith(string prefix);
    void removeAll();
    void display();
};


