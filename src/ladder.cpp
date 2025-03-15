
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

bool edit_distance_within(const string &str1, const string &str2, int d) {
  int n = str1.size();
  int m = str2.size();
  if (abs(n - m) > d) {
    return false;
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = i;
  }
  for (int j = 0; j <= m; j++) {
    dp[0][j] = j;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
      }
    }
  }
  return dp[n][m] <= d;
}

bool is_adjacent(const string &word1, const string &word2) {
  return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string &begin_word,
                                  const string &end_word,
                                  const set<string> &word_list) {
  if (begin_word == end_word) {
    error(begin_word, end_word, "Words must be different");
  }
  if (word_list.find(end_word) == word_list.end()) {
    error(begin_word, end_word, "End word not found in word list");
  }
  
  queue<vector<string>> q;
  q.push({begin_word});
  set<string> visited;
  visited.insert(begin_word);
  
  
  map<int, vector<string>> words_by_length;
  for (const string &word : word_list) {
    words_by_length[word.length()].push_back(word);
  }
  
  while (!q.empty()) {
    vector<string> path = q.front();
    q.pop();
    string last_word = path.back();
    
    if (last_word == end_word) {
      return path;
    }
    
    int len = last_word.length();
    
    for (int l = max(1, len - 1); l <= len + 1; l++) {
      for (const string &word : words_by_length[l]) {
        if (visited.find(word) == visited.end() && is_adjacent(last_word, word)) {
          visited.insert(word);
          vector<string> new_path = path;
          new_path.push_back(word);
          q.push(new_path);
        }
      }
    }
  }
  
  return {};
}

void print_word_ladder(const vector<string> &ladder) {
  if (ladder.empty()) {
    cout << "No word ladder found." << endl;
  } else {
    cout << "Word ladder found: ";
    for (const string &word : ladder) {
      cout << word << " ";
    }
    cout << endl;
  }
}

#define my_assert(e)                                                           \
  {                                                                            \
    cout << #e << ((e) ? " passed" : " failed") << endl;                       \
  }

void verify_word_ladder() {
  set<string> word_list;
  load_words(word_list, "src/words.txt");
  my_assert(generate_word_ladder("hit", "cog", word_list).size() == 4);
  my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
  my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
  my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
  my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
  my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}

