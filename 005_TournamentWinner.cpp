// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Array

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// Sol-1.0 T=O(n), S=O(k)
// where n is the number of copetitions, k is the number of teams
string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  unordered_map<string, int> rank_board;

  for (int i = 0; i < results.size(); i++) {
    string winner{competitions[i][!results[i]]};
    if (rank_board.find(winner) == rank_board.end()) {
      rank_board.insert({winner, 3});
    } else {
      rank_board[winner] += 3;
    }
  }

  string first_winner{};
  int highest_score = 0;
  for (auto& log: rank_board) {
    int score = log.second;
    if (score > highest_score) {
      highest_score = score;
      first_winner = log.first;
    }
  }

  return first_winner;
}
