#include <functional>
#include <string>

using namespace std;

class Trie {

public:
  bool isEnd = false;
  Trie *next[26];

  Trie() {
    for (auto &node : next) {
      node = nullptr;
    }
  };

  void insert(string word) {

    Trie *node = this;
    for (int i = 0; i < word.length(); i++) {
      int letter = word[i] - 'a';
      if (node->next[letter] == nullptr) {
        node->next[letter] = new Trie();
      }
      node = node->next[letter];
    }

    node->isEnd = true;
  }

  bool search(string word) {
    auto node = this;
    for (char &x : word) {
      int letter = x - 'a';
      if (node->next[letter] == nullptr)
        return false;
      node = node->next[letter];
    }

    return node->isEnd;
  }

  bool startsWith(string prefix) {

    auto node = this;
    for (char &x : prefix) {
      int letter = x - 'a';
      if (node->next[letter] == nullptr)
        return false;
      node = node->next[letter];
    }

    return true;
  }
};
