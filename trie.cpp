#include "trie.h"
#include <iostream>
#include <map>

std::string Trie::charsToInts(std::string key){
    std::string s = "";
    for(char c : key){
        s += mapping[c];
    }
    return s;
}

Trie *Trie::createNode()
{
    Trie* trie = new Trie;
    isLeaf = false;
    for(int i = 0; i < n; i++){
        children[i] = nullptr;
    }
    return trie;
}


void Trie::insert(std::string key, Trie* root){
    Trie* current = root;
    std::string word = key;
    key = charsToInts(key);

    for(size_t i = 0; i < key.length(); i++){
        int index = key[i] - '0';

        if(!current->children[index]){
            current->children[index] = this->createNode();
        }
        current = current->children[index];
    }
    current->words.push_back(word);
    current->isLeaf = true;
}

std::vector<std::string> Trie::search(std::string key, Trie* root){
    Trie* current = root;

    for(size_t i = 0; i < key.length(); i++){
        int index = key[i] - '0';
        if(!current->children[index]){
            std::cout << key << " -" << std::endl;
            return {};
        }
        current = current->children[index];
    }

    if(current->isLeaf){
        std::cout << "Possible words: ";
        for(size_t i = 0; i < current->words.size(); i++){
            std::cout << current->words.at(i) << " ";
        }
        std::cout << "\n";
        return current->words;
    }
    else{
        std::cout << key << " -" << std::endl;
        return {};
    }
}
