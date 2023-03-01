/*
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
*/
#include<bits/stdc++.h>
using namespace std;
 
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
*/
 
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
#define PQ(type) priority_queue<type>
#define PQD(type) priority_queue<type,vector<type>,greater<type> >
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define endl '\n'
 
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set; // use less_equal for multiset
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)
 
typedef long long ll; 
typedef long double ld; 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
 
const  int mxN = 1e5+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;

mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define SHUF(v) shuffle(all(v), RNG);
// Use mt19937_64 for 64 bit random numbers.

struct upd {
  ll setval;
  ll increment;
  upd() {
    setval = -1;
    increment = 0;
  }
  upd(ll setval, ll increment) {
    this->setval = setval;
    this->increment = increment;
  }
  bool operator==(const upd&other) const {
    return setval == other.setval && increment == other.increment;
  }
};

// segment tres with data in range [tl, tr) with 1 based segment tree for (0, n) array
template<class T, class U>
struct segtree{

  ll n;
  vector<T> data;
  vector<U> lazy;
  T identityElement;
  U identityUpdate;

  segtree(ll n, T identityElement, U identityUpdate) {
    this->n = n;
    this->identityElement = identityElement;
    this->identityUpdate = identityUpdate;
    data.assign(4 * n + 1, identityElement);
    lazy.assign(4 * n + 1, identityUpdate);
  }


  T merge(T a, T b) {
    T ans = a + b;
    return ans;
  }

  U mergeUpdate(U oldUpd, U newUpd, ll tl, ll tr) {
    U ans;
    if(newUpd.setval == -1) {
      ans = oldUpd;
      ans.increment += newUpd.increment;
    }
    else ans = newUpd;
    return ans;
  }

  T apply(T cur, U up, ll tl, ll tr) {
    T ans;
    ans = cur;
    if(up.setval != -1) {
      ans = (tr - tl) * (up.setval + up.increment); 
    }
    else ans += (tr - tl) * up.increment;
    return ans;
    //increment range ans = cur + (tr - tl) * upd;
  }


  void pushdown(ll cur, ll tl, ll tr) {

    if(lazy[cur] == identityUpdate) return;
    data[cur] = apply(data[cur], lazy[cur], tl, tr);
    if(2 * cur <= 4 * n + 1) {
      ll tm = (tl + tr) >> 1;
      lazy[2 * cur] = mergeUpdate(lazy[2 * cur], lazy[cur], tl, tm);
      lazy[2 * cur + 1] = mergeUpdate(lazy[2 * cur + 1], lazy[cur], tm, tr);
    }
    lazy[cur].setval = -1;
    lazy[cur].increment = 0;
  }


  void buildUtil(vector<T> &a, ll cur, ll tl, ll tr) {
    if(tr - tl == 1LL) data[cur] = a[tl];
    else {
      ll tm = (tl + tr) >> 1;
      buildUtil(a, 2 * cur, tl, tm);
      buildUtil(a, 2 * cur + 1, tm, tr);
      data[cur] = merge(data[2 * cur], data[2 * cur + 1]);
    }
  }


  void updateUtil(ll cur, ll tl, ll tr, ll l, ll r, U val) {
    pushdown(cur, tl, tr);
    if(tl >= r || tr <= l) return;
    if(l <= tl && tr <= r) {
      lazy[cur] = mergeUpdate(lazy[cur], val, tl, tr);
      pushdown(cur, tl, tr);
    }
    else {
      ll tm = (tl + tr) >> 1;
      updateUtil(2 * cur, tl, tm, l, r, val);
      updateUtil(2 * cur + 1, tm, tr, l, r, val);
      data[cur] = merge(data[2 * cur], data[2 * cur + 1]);
    }
  }

  T queryUtil(ll cur, ll tl, ll tr, ll l, ll r) {
    pushdown(cur, tl, tr);
    if(tl >= r || tr <= l) return identityElement;
    if(l <= tl && tr <= r) return data[cur];

    ll tm = (tl + tr) >> 1;
    return merge(queryUtil(2 * cur, tl, tm, l, r),
    queryUtil(2 * cur + 1, tm, tr, l, r));
  }

  void build(vector<ll> &a) {
    assert(sz(a) == n);
    buildUtil(a, 1LL, 0LL, n);
  }

  void update(ll l, ll r, U val) {
    updateUtil(1LL, 0LL, n, l , r + 1, val);
  }

  T query(ll l, ll r) {
    return queryUtil(1LL, 0LL, n, l , r + 1);
  }

};

void solve() {
   int n, q;
   cin >> n >> q;
   vll v(n);
   rep(i, 0, n) cin >> v[i];

   upd up(-1, 0);
   segtree<ll, upd> a(n, 0, up);

   a.build(v);



   while(q--) {
    ll type, l, r;
    cin >> type >> l >> r;
    l--; r--;
    if(type == 1) {
      ll val; cin >> val;
      upd temp(-1, val);
      a.update(l, r, temp);
     // cout << a.query(l, r) << " here " << endl;
    }
    else if(type == 2) {
      ll val; cin >> val;
      upd temp(val, 0);
      a.update(l, r, temp);
   //   cout << a.query(l, r) << " here " << endl;
    }
    else cout << a.query(l, r) << endl;
   }
   

}

int main() {
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

int t = 1;
//cin >> t;
while(t--) {
solve();
}
}

