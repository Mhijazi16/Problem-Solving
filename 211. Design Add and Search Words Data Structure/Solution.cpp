#include <functional>
#include <iostream>
#include <string>

using namespace std;

class WordDictionary {
public:
  bool isEnd = false;
  WordDictionary *next[26] = {nullptr};

  WordDictionary() {};

  void addWord(string word) {

    WordDictionary *curr = this;
    for (char &letter : word) {
      int index = letter - 'a';
      if (curr->next[index] == nullptr) {
        curr->next[index] = new WordDictionary();
      }
      curr = curr->next[index];
    }
    curr->isEnd = true;
  }

  // hello
  bool subsearch(string word, WordDictionary *node) {

    int len = word.length();
    for (int i = 0; i < len; i++) {

      if (word[i] == '.') {
        string subword = word.substr(i + 1, len - i);
        for (auto &subnode : node->next) {
          if (subnode && subsearch(subword, subnode))
            return true;
        }
        return false;
      }

      int index = word[i] - 'a';
      if (node->next[index] == nullptr)
        return false;

      node = node->next[index];
    }

    return node->isEnd;
  }

  bool search(string word) { return subsearch(word, this); }
};

int main() {

  auto dict = new WordDictionary();
  dict->addWord("at");
  cout << dict->search("h");

  return 0;
}
