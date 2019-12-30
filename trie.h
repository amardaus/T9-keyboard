#ifndef TRIE_H
#define TRIE_H
#include <vector>
#include <map>
#include <string>

constexpr int n = 10;

class Trie{
public:
    Trie* createNode();
    std::string charsToInts(std::string key);
    void insert(std::string key, Trie* root);
    std::vector<std::string> search(std::string key, Trie* root);
    bool testsearch(std::string key, Trie* root);

    Trie* children[n];
    std::vector<std::string> words;
    bool isLeaf;
};


#endif // TRIE_H
