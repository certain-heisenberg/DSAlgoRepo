#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

unsigned mod_pow(unsigned a, unsigned b, unsigned mod) {
    unsigned result = 1;

    while (b > 0) {
        if (b & 1)
            result = unsigned(uint64_t(result) * a % mod);

        a = unsigned(uint64_t(a) * a % mod);
        b >>= 1;
    }

    return result;
}

bool miller_rabin(unsigned n) {
    if (n < 2)
        return false;

    // Check small primes.
    for (unsigned p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29})
        if (n % p == 0)
            return n == p;

    int r = __builtin_ctz(n - 1);
    unsigned d = (n - 1) >> r;

    // https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Testing_against_small_sets_of_bases
    for (unsigned a : {2, 7, 61}) {
        unsigned x = mod_pow(a % n, d, n);

        if (x <= 1 || x == n - 1)
            continue;

        for (int i = 0; i < r - 1 && x != n - 1; i++)
            x = unsigned(uint64_t(x) * x % n);

        if (x != n - 1)
            return false;
    }

    return true;
}

int find_prime(int n) {
    while (!miller_rabin(n))
        n++;

    return n;
}

void run_case(int test_case) {
    int64_t Z;
    cin >> Z;
    int low = 0, high = 1.1e9;

    auto evaluate = [&](int64_t x) -> int64_t {
        int64_t p = find_prime(x);
        int64_t q = find_prime(p + 1);
        return p * q;
    };

    while (low < high) {
        int mid = low + (high - low + 1) / 2;

        if (evaluate(mid) <= Z)
            low = mid;
        else
            high = mid - 1;
    }

    cout << "Case #" << test_case << ": " << evaluate(low) << '\n';
}

int main() {
    int tests;
    cin >> tests;

    for (int tc = 1; tc <= tests; tc++) {
        run_case(tc);
        cout << flush;
    }
}
