#include<bits/stdc++.h>
 
#define ar array 
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz(v) int((v).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for(int i = a; i < b; i++)
#define deb(x) cout << #x << "=" << x << endl
#define PI 3.1415926535897932384626
#define endl '\n'
 
using namespace std;
 
typedef long long ll; 
typedef long double ld; 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
 
const  int mxN = 1e5+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;


struct segtree{

  int n;
  vector<ll> data;
  vector<ll> lazy;

  void init(int _n) {
    data.resize(4 * _n + 1);
    lazy.resize(4 * _n + 1);
    n = _n;
  }


  void single(ll &x, int val) {
    x += val;
  }

  ll neutral_element = 0;

  ll merge(ll a, ll b) {
    return a + b;
  }

  void pushup(int cur) {
    data[cur] = merge(data[2 * cur],data[2 * cur + 1]);
  }

  void update(ll &a , ll b) {
    a += b;
  }

  void pushdown(int cur) {
    update(data[2 * cur], lazy[cur]);
    update(data[2 * cur + 1], lazy[cur]);
    update(lazy[2 * cur], lazy[cur]);
    update(lazy[2 * cur + 1], lazy[cur]);
    lazy[cur] = 0;
  }

  void build(vector<ll> &a, int cur, int l, int r) {
    if(r - l == 1) single(data[cur], a[l]);
    else {
      build(a, 2 * cur, l, (l + r) >> 1);
      build(a, 2 * cur + 1, (l + r) >> 1, r);
      pushup(cur);
    }
  }

  void build(vector<ll> &a) {
    build(a, 1, 0, n);
  }

  void modify(int cur, int l, int r, int L, int R, ll val) {
    if(l >= R || r <= L) return;
    if(L <= l && r <= R) {
      single(data[cur], val);
      single(lazy[cur], val);
    }
    else {
      pushdown(cur);
      modify(2 * cur, l, (l + r) >> 1, L, R, val);
      modify(2 * cur + 1, (l + r) >> 1, r, L, R, val);
      pushup(cur);
    }
  }

  ll query(int cur, int l, int r, int L, int R) {
    if(l >= R || r <= L) return neutral_element;
    if(L <= l && r <= R) return data[cur];

    pushdown(cur);
    return merge(query(2 * cur, l, (l + r) >> 1, L, R) ,
    query(2 * cur + 1, (l + r) >> 1, r, L, R));
  }

  void modify(int l, int r, int val) {
    modify(1, 0, n, l, r + 1, val);
  }

  void modify(int p, int val) {
    modify(p, p, val);
  }

  ll query(int l, int r) {
    return query(1, 0, n, l, r + 1);
  }

  ll query(int p) {
    return query(p, p);
  }

};

void solve() {
  int n, m;
  cin >> n >> m;

  segtree st;
  st.init(n);

  while(m--) {
    int type;
    cin >> type;
    if(type == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      st.modify(l, r - 1, v);
    }
    else {
      int i;
      cin >> i;
      cout << st.query(i) << endl;
    }
  }

}

int main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int t = 1;
while(t--) {
solve();
}
}

