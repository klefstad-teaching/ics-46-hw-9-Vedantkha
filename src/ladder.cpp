
#include "ladder.h"

void error(string word1, string word2, string msg) {
  cout << "Error: " << word1 << " " << word2 << " " << msg << endl;
  exit(1);
}

void load_words(set<string> &word_list, const string &file_name) {
  ifstream file(file_name);
  if (!file) {
    error("load_words", file_name, "File not found");
  }
  string word;
  while (file >> word) {
    word_list.insert(word);
  }
}