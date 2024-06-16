#include "Trie.h"
Trie::Trie() {
    root = new TrieNode();
}

Trie::Trie(initializer_list<string> words) : Trie() {
    for (const auto& word : words) {
        push(word);
    }
}

Trie::Trie(string word) : Trie() {
    push(word);
}

void Trie::add(initializer_list<string> words) {

    for (string s:words) {
        push(s);
    }
}

void Trie::remove(initializer_list<string> words) {
    for (string s:words) {
        remove(s);
    }
}

string Trie::longestCommonPrefix() {
    return getLongestCommonPrefix(root);
}

void Trie::push(string word) {
    addWord(root, word, 0);
}

bool Trie::empty() {
    return root->children.empty();
}

bool Trie::exists(string word) {
    return searchWord(root, word, 0);
}

void Trie::remove(string word) {
    removeWord(root, word, 0);
}

bool Trie::existsPrefix(string prefix) {
    return searchPrefix(root, prefix, 0);
}

vector<string> Trie::wordsWithPrefix(string prefix) {
    vector<string> result;
    TrieNode* node = root;
    for (char ch : prefix) {
        if (node->children.find(ch) == node->children.end()) {
            return result;
        }
        node = node->children[ch];
    }
    getWords(node, prefix, result);
    return result;
}

bool Trie::isLeaf( string word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (node->children.find(ch) == node->children.end()) {
            return false;  
        }
        node = node->children[ch];
    }
    return node->isEndOfWord; 
}

vector<string> Trie::all() {
    vector<string> result;
    getWords(root, "", result);
    return result;
}

void Trie::removePrefix(string prefix) {
    TrieNode* node = root;
    for (char ch : prefix) {
        if (node->children.find(ch) == node->children.end()) {
            return;
        }
        node = node->children[ch];
    }
    vector<string> wordsToRemove;
    getWords(node, prefix, wordsToRemove);
    for (const string& word : wordsToRemove) {
        remove(word);
    }
}

int Trie::countWordsStartingWith(string prefix) {
    TrieNode* node = root;
    for (char ch : prefix) {
        if (node->children.find(ch) == node->children.end()) {
            return 0;
        }
        node = node->children[ch];
    }
    vector<string> result;
    getWords(node, prefix, result);
    return result.size();
}

void Trie::removeAll() {
    delete root;
    root = new TrieNode();
}

void Trie::display() {
    vector<string> result = all();
    for (const string& word : result) {
        cout << word << endl;
    }
}

void Trie::addWord(TrieNode* node, const string& word, int index) {
    if (index == word.size()) {
        node->isEndOfWord = true;
        return;
    }
    char ch = word[index];
    if (node->children.find(ch) == node->children.end()) {
        node->children[ch] = new TrieNode();
    }
    addWord(node->children[ch], word, index + 1);
}

bool Trie::searchWord(TrieNode* node, const string& word, int index) {
    if (index == word.size()) {
        return node->isEndOfWord;
    }
    char ch = word[index];
    if (node->children.find(ch) == node->children.end()) {
        return false;
    }
    return searchWord(node->children[ch], word, index + 1);
}

bool Trie::searchPrefix(TrieNode* node, const string& prefix, int index) {
    if (index == prefix.size()) {
        return true;
    }
    char ch = prefix[index];
    if (node->children.find(ch) == node->children.end()) {
        return false;
    }
    return searchPrefix(node->children[ch], prefix, index + 1);
}

void Trie::removeWord(TrieNode*& node, const string& word, int index) {
    if (!node) return;
    if (index == word.size()) {
        node->isEndOfWord = false;
        return;
    }
    char ch = word[index];
    if (node->children.find(ch) != node->children.end()) {
        removeWord(node->children[ch], word, index + 1);
        if (node->children[ch]->children.empty() && !node->children[ch]->isEndOfWord) {
            delete node->children[ch];
            node->children.erase(ch);
        }
    }
}

void Trie::getWords(TrieNode* node, string prefix, vector<string>& result) {
    if (node->isEndOfWord) {
        result.push_back(prefix);
    }
    for (auto& pair : node->children) {
        getWords(pair.second, prefix + pair.first, result);
    }
}

string Trie::getLongestCommonPrefix(TrieNode* node) {
    string prefix;
    while (node && node->children.size() == 1 && !node->isEndOfWord) {
        auto it = node->children.begin();
        prefix += it->first;
        node = it->second;
    }
    return prefix;
}