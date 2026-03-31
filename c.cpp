
// ॐ गं गणपतये नमः
// जय श्री राम
// ॐ नमः शिवाय
#include <bits/stdc++.h>
using namespace std;

// Typedefs for convenience
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef set<int> si;
typedef set<ll> sll;

// Constants
const ll MOD = 1e9 + 7;
const int M = 998244353;
const int N = 3e5 + 10;
const int N_sieve = 1000000;
const ll INF = LLONG_MAX;
const ld PI = acos(-1.0);
const ld EPS = 1e-9;

// Utility Macros
#define pb push_back
#define F first
#define S second
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define bob cout << "Bob\n"
#define alice cout << "Alice\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fast_io                                                                \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORR(i, a, b) for (int i = (a); i >= (b); --i)
#define TESTS                                                                  \
  int t;                                                                       \
  cin >> t;                                                                    \
  while (t--)                                                                  \
    solve();
#define mem(x, v) memset(x, v, sizeof(x))

// Sieve of Eratosthenes and Smallest Prime Factor (SPF)
vector<ll> sieve(N_sieve, 1);
vector<ll> spf(N_sieve + 1, 1e9);
void sieveoe() {
  for (ll i = 0; i < spf.size(); i++) {
    spf[i] = i;
  }
  sieve[0] = 0;
  sieve[1] = 0;
  for (ll i = 2; i * i <= N_sieve; i++) {
    if (sieve[i]) {
      spf[i] = min(spf[i], i);
      for (ll j = i * i; j <= N_sieve; j += i) {
        sieve[j] = 0;
        spf[j] = min(spf[j], i);
      }
    }
  }
}

// Factorial and Modular Factorial
ll factorial(ll n) {
  ll ans = 1;
  for (ll i = 1; i <= n; i++) {
    ans *= i;
  }
  return ans;
}

ll mul_mod(ll a, ll b, ll modulo) {
  return ((a % modulo) * (b % modulo)) % modulo;
}

ll factorial_with_mod(ll n, ll modulo) {
  ll ans = 1;
  for (ll i = 1; i <= n; i++) {
    ans = mul_mod(ans, i, modulo);
  }
  return ans % modulo;
}

// GCD, LCM, and Modular Inverse
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

ll lcm(ll a, ll b) { return (a * b) / gcd(a, b); }

ll mod_inverse(ll a, ll mod = MOD) {
  ll res = 1, b = mod - 2;
  while (b) {
    if (b & 1)
      res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

// Power of 2 Check
bool powerof2(ll x) { return !(x & (x - 1)); }

// MSB and One's Complement
ll msb(ll n) {
  ll ans = 0;
  n = (n >> 1);
  while (n) {
    n = (n >> 1);
    ans++;
  }
  return ans;
}

int onesComplement(int n) {
  int number_of_bits = floor(log2(n)) + 1;
  return ((1 << number_of_bits) - 1) ^ n;
}

// nCr Function (Combinatorial)
int nCr(int n, int r) {
  if (r > n)
    return 0;
  if (r == 0 || r == n)
    return 1;
  return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

// String Utility Functions
string to_upper(string s) {
  transform(all(s), s.begin(), ::toupper);
  return s;
}

string to_lower(string s) {
  transform(all(s), s.begin(), ::tolower);
  return s;
}

bool is_palindrome(const string &s) {
  return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
}

// Comparator Function for Sorting Pairs by Sum
static bool compsum(pii a, pii b) {
  return (a.first + a.second < b.first + b.second);
}

struct Node{
  Node *links[26];
  bool flag1,flag2;
  Node(){
    FOR(i,0,26)links[i]=NULL;
    flag1=false;
    flag2=false;
  }
  bool containsKey(char c){ 
    return (links[c-'a']!=NULL); 
  }
  void put(char c,Node *node){ 
    links[c-'a']=node; 
  }
  Node *get(char c){ 
    return links[c - 'a']; 
  }
  void setEnd(){
    flag1=true;
    flag2=false;
  }
  bool check(){ 
    return flag1; 
  }
  void setEnd2(){ 
    flag2=true; 
  }
  bool checkEnd2(){ 
    return flag2; 
  }
};

class Trie{
public:
  Node *root;

  Trie(){ 
    root=new Node();
  }
  void insert(string s){
    Node *node=root;
    for(auto &it:s){
      if(!node->containsKey(it)){
        node->put(it,new Node());
      }
      node=node->get(it);
    }
    node->setEnd();
  }
  bool search(string s){
    Node *node=root;
    for(auto &it:s){
      if(!node->containsKey(it)){
        return false;
      }
      node=node->get(it);
    }
    return node->check()&&(!node->checkEnd2());
  }
  void remove(string s){
    Node *node=root;
    for(auto &it:s){
      if(!node->containsKey(it)){
        return;
      }
      node=node->get(it);
    }
    node->setEnd2();
  }
  void dfs(Node *node,string &s,vector<string> &v){
    if(!node->checkEnd2()&&node->check()){
      v.pb(s);
    }
    FOR(i,0,26){
      if(node->links[i]!=NULL){
        auto it=i+'a';
        s.pb(it);
        dfs(node->links[i],s,v);
        s.pop_back();
      }
    }
  }
  vector<string>find(string s){
    Node *node=root;
    for(auto &it:s){
      if(!node->containsKey(it)){
        return {};
      }
      node=node->get(it);
    }
    vector<string>v;
    string ss=s;
    dfs(node,ss,v);
    return v;
  }
};

void solve() {
  Trie t;
  vector<string>v={"pranjal","pranju","pranjalayyaaaa","pranjjjuuuu","bisen"};
  for (auto &it:v)t.insert(it);

  cout<<t.search("pranju")<<endl;
  vector<string>temp=t.find("pra");

  auto solve=[&](vector<string>v){
    for (auto &it:v)cout<<it<<" ";
    cout<<endl;
  };
  solve(temp);
  t.remove("pranju");
  temp=t.find("pra");
  solve(temp);
  cout<<t.search("pranju")<<endl;
}

int main() {
  fast_io;
  // TESTS;
  solve();
  return 0;
}