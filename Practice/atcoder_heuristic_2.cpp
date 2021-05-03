/**
 *    author:  tourist
 *    created: 25.04.2021 12:46:23       
**/
#undef _GLIBCXX_DEBUG
 
#include <bits/stdc++.h>
#include <sys/time.h>
 
using namespace std;
 
const double TL = 1.95;
 
double start_time_ = -1;
bool first_time = true;
 
double get_time() {
  timeval tv; 
  gettimeofday(&tv, 0); 
  auto ret = tv.tv_sec + tv.tv_usec * 1e-6;
  if (first_time) {
    start_time_ = ret;
    first_time = false;
  }
  return ret - start_time_;
}
 
const int CNT = 16384;
double logs[CNT];
 
struct rand_gen {
  static const int MAX = 2147483647;
  static constexpr double Q_MAX = 1.0 / MAX;
 
  int x = 8753, y = 239017, z = 1000000123;
 
  inline int next_int() {
    int t = x ^ (x << 11);
    x = y;
    y = z;
    z ^= (z >> 19) ^ t ^ (t >> 8);
    return z;
  }
 
  double next_double() {
    return next_int() * Q_MAX;
  }
} rng;
 
template<typename T>
void shuffle(vector<T>& a) {
  int n = (int) a.size();
  for (int i = 1; i < n; i++) {
    swap(a[i], a[rng.next_int() % (i + 1)]);
  }
}
 
template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
const int di[4] = {-1, 0, 1, 0};
const int dj[4] = {0, -1, 0, 1};
const string let = "ULDR";
 
const int n = 50;
 
int tile[n * n];
int ben[n * n];
int nei[n * n][4];
 
int main() {
  int si, sj;
  cin >> si >> sj;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> tile[i * n + j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> ben[i * n + j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int dir = 0; dir < 4; dir++) {
        int ni = i + di[dir];
        int nj = j + dj[dir];
        if (ni >= 0 && nj >= 0 && ni < n && nj < n) {
          nei[i * n + j][dir] = ni * n + nj;
        } else {
          nei[i * n + j][dir] = -1;
        }
      }
    }
  }
  int best_score = 0;
  string best_ans = "";
  vector<int> order(4);
  iota(order.begin(), order.end(), 0);
  vector<pair<int, string>> cand;
  double limit = 0;
  do {
    vector<bool> used(n * n, false);
    string ans = "";
    int cur_best_score = 0;
    string cur_best_ans = "";
    int score = 0;
    function<void(int)> Dfs = [&](int v) {
      score += ben[v];
      if (score > cur_best_score) {
        cur_best_score = score;
        cur_best_ans = ans;
      }
      used[tile[v]] = true;
      if (get_time() < limit) {
        for (int j : order) {
          int u = nei[v][j];
          if (u != -1 && !used[tile[u]]) {
            ans += let[j];
            Dfs(u);
            ans.pop_back();
          }
        }
      }
      used[tile[v]] = false;
      score -= ben[v];
    };
    limit += TL / 10 / 24;
    Dfs(si * n + sj);
    if (cur_best_score > best_score) {
      best_score = cur_best_score;
      best_ans = cur_best_ans;
    }
    cand.emplace_back(cur_best_score, cur_best_ans);
  } while (next_permutation(order.begin(), order.end()));
  sort(cand.rbegin(), cand.rend());
  const int OUTER = 5;
  for (int outer = 0; outer < OUTER; outer++) {
    int score = cand[outer].first;
    string ans = cand[outer].second;
    vector<int> seq(1, si * n + sj);
    for (char c : ans) {
      int dir = (int) let.find(c);
      seq.push_back(nei[seq.back()][dir]);
    }
    vector<bool> used(n * n, false);
    for (int x : seq) {
      used[tile[x]] = true;
    }
    limit = TL / 10 + (TL / 10) * (outer + 1) / OUTER;
    const int MAX_DIFF = 30;
    const int MAX_DEPTH = 40;
    bool changed = true;
    while (changed) {
      changed = false;
      for (int diff = 1; diff <= MAX_DIFF; diff++) {
        for (int i = 0; i < (int) seq.size() - 1; i++) {
          if (get_time() > limit) {
            break;
          }
          int j = i + diff;
          if (j >= (int) seq.size()) {
            break;
          }
          int sub = 0;
          for (int k = i; k < j; k++) {
            used[tile[seq[k]]] = false;
            sub += ben[seq[k]];
          }
          int best_profit = sub;
          int profit = 0;
          string best_moves = ""; 
          string moves = "";
          auto start = get_time();
          function<void(int, int)> Dfs = [&](int v, int depth) {
            double T = get_time();
            if (T > limit || T - start > 0.02 * TL) {
              return;
            }
            if (tile[v] == tile[seq[j]]) {
              return;
            }
            if (depth + abs(v / n - seq[j] / n) + abs(v % n - seq[j] % n) - 1 > MAX_DEPTH) {
              return;
            }
            profit += ben[v];
            used[tile[v]] = true;
            for (int jj : order) {
              int u = nei[v][jj];
              if (u == seq[j]) {
                if (profit > best_profit) {
                  best_profit = profit;
                  best_moves = moves + let[jj];
                }
              }
              if (u != -1 && !used[tile[u]]) {
                moves += let[jj];
                Dfs(u, depth + 1);
                moves.pop_back();
              }
            }
            used[tile[v]] = false;
            profit -= ben[v];
          };
          Dfs(seq[i], 0);
          if (best_profit > sub) {
//            debug(i, j, sub, best_profit, best_moves);
            ans.erase(ans.begin() + i, ans.begin() + j);
            ans.insert(ans.begin() + i, best_moves.begin(), best_moves.end());
            score += best_profit - sub;
            seq.erase(seq.begin() + i + 1, seq.begin() + j + 1);
            int ptr = i + 1;
            used[tile[seq[i]]] = true;
            for (char c : best_moves) {
              int nxt = nei[seq[ptr - 1]][let.find(c)];
              seq.insert(seq.begin() + ptr, nxt);
              used[tile[nxt]] = true;
              ptr += 1;
            }
            changed = true;
          } else {
            for (int k = i; k < j; k++) {
              used[tile[seq[k]]] = true;
            }
          }
        }
      }
    }
//    debug(cand[outer].first, score, get_time());
    if (score > best_score) {
      best_score = score;
      best_ans = ans;
    }
  }
//  debug("before SA", best_score);
  int score = best_score;
  string ans = best_ans;
  double ST = get_time();
  double init_temp = 1000;
  double final_temp = 10;
  while (get_time() < TL) {
    vector<int> seq(1, si * n + sj);
    for (char c : ans) {
      int dir = (int) let.find(c);
      seq.push_back(nei[seq.back()][dir]);
    }
    vector<bool> used(n * n, false);
    for (int x : seq) {
      used[tile[x]] = true;
    }
    limit = TL;
    const int MAX_DIFF = 15;
    const int MAX_DEPTH = 23;
    double temp = init_temp * pow(final_temp / init_temp, (get_time() - ST) / (limit - ST));
//    debug(temp, score);
    for (int diff = 1; diff <= MAX_DIFF; diff++) {
      for (int i = 0; i < (int) seq.size() - 1; i++) {
        if (get_time() > limit) {
          break;
        }
        double temp = init_temp * pow(final_temp / init_temp, (get_time() - ST) / (limit - ST));
        int j = i + diff;
        if (j >= (int) seq.size()) {
          break;
        }
        int sub = 0;
        for (int k = i; k < j; k++) {
          used[tile[seq[k]]] = false;
          sub += ben[seq[k]];
        }
        int best_profit = -(int) 1e9;
        int profit = 0;
        string best_moves = ""; 
        string moves = "";
        auto start = get_time();
        shuffle(order);
        function<void(int, int)> Dfs = [&](int v, int depth) {
          double T = get_time();
          if (T > limit || T - start > 0.04 * TL) {
            return;
          }
          if (tile[v] == tile[seq[j]]) {
            return;
          }
          if (depth + abs(v / n - seq[j] / n) + abs(v % n - seq[j] % n) - 1 > MAX_DEPTH) {
            return;
          }
          profit += ben[v];
          used[tile[v]] = true;
          for (int jj : order) {
            int u = nei[v][jj];
            if (u == seq[j]) {
              if (profit > best_profit + rng.next_int() % max(1, (int) temp)) {
                best_profit = profit;
                best_moves = moves + let[jj];
              }
            }
            if (u != -1 && !used[tile[u]]) {
              moves += let[jj];
              Dfs(u, depth + 1);
              moves.pop_back();
            }
          }
          used[tile[v]] = false;
          profit -= ben[v];
        };
        Dfs(seq[i], 0);
        if (best_profit != sub && (best_profit > sub || rng.next_double() < exp((best_profit - sub) / temp))) {
//            debug(i, j, sub, best_profit, best_moves);
          ans.erase(ans.begin() + i, ans.begin() + j);
          ans.insert(ans.begin() + i, best_moves.begin(), best_moves.end());
          score += best_profit - sub;
          if (score > best_score) {
            best_score = score;
            best_ans = ans;
          }
          seq.erase(seq.begin() + i + 1, seq.begin() + j + 1);
          int ptr = i + 1;
          used[tile[seq[i]]] = true;
          for (char c : best_moves) {
            int nxt = nei[seq[ptr - 1]][let.find(c)];
            seq.insert(seq.begin() + ptr, nxt);
            used[tile[nxt]] = true;
            ptr += 1;
          }
        } else {
          for (int k = i; k < j; k++) {
            used[tile[seq[k]]] = true;
          }
        }
      }
    }
//    debug(cand[outer].first, score, get_time());
  }
  cout << best_ans << '\n';
  cerr << "Time = " << get_time() << ", Score = " << best_score << '\n';
}
