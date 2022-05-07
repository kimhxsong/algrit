// Copyright 2022 by @kimhxsong
// Difficulty: #Easy
// Category: #Array
#include "solved.h"

#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

#ifdef BEST

// Sol-1.1 T=O(n), S=O(k)
// where n is the number of copetitions, k is the number of teams
static const int kHomeTeamWon = 1;

static void updateMatchScores(unordered_map<string, int>& matchScores,
                              const string& winningTeam,
                              int victoryPoints) {
  if (matchScores.find(winningTeam) == matchScores.end()) {
    matchScores[winningTeam] = 0;  // <=> matchScores.insert({winningTeam, 0});
  }

  matchScores[winningTeam] += victoryPoints;
}

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  unordered_map<string, int> matchScores;
  string topTeam{""};

  for (size_t i = 0; i < results.size(); i++) {
    const vector<string>& competition = competitions[i];
    const string& homeTeam = competition[0];
    const string& awayTeam = competition[1];
    int result = results[i];
    const string& winningTeam = (result == kHomeTeamWon) ? homeTeam : awayTeam;

    updateMatchScores(matchScores, winningTeam, 3);

    if (matchScores[winningTeam] > matchScores[topTeam]) {
      topTeam = winningTeam;
    }
  }

  return topTeam;
}

#else
// Sol-1.0 T=O(n), S=O(k)
// where n is the number of copetitions, k is the number of teams
string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  unordered_map<string, int> rank_board;

  for (size_t i = 0; i < results.size(); i++) {
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

#endif  // BEST
