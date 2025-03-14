
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

  cout << "edit_distance_within(" << first_word << ", " << second_word
       << ", 1) : ";

  (edit_distance_within(first_word, second_word, 1)) ? cout << "true"
                                                     : cout << "false";
  cout << endl;

  cout << "edit_distance_within(" << first_word << ", " << second_word
       << ", 3) : ";

  (edit_distance_within(first_word, second_word, 3)) ? cout << "true"
                                                     : cout << "false";
  cout << endl;

  vector<string> ladder =
      generate_word_ladder(first_word, second_word, word_list);
  print_word_ladder(ladder);

  // set<string> word_list_full;
  // load_words(word_list_full, "src/words.txt");
  // vector<string> ladder2 = generate_word_ladder("hit", "cog",
  // word_list_full); print_word_ladder(ladder2);
  verify_word_ladder();

  return 0;
}
