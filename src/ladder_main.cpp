
#include "ladder.h"
#include <iostream>
#include <set>

using namespace std;

int main() {
  cout << "Enter the first word: ";
  string first_word = "cod";
  cout << endl << first_word << endl;
  // cin >> first_word;
  cout << "Enter the second word: ";
  string second_word = "datat";
  // cin >> second_word;
  cout << endl << second_word << endl;
  string file_name = "src/small_words.txt";
  set<string> word_list;
  load_words(word_list, file_name);
  // for (const string &word : word_list) {
  //   cout << word << " ";
  // }
  // cout << endl;
}