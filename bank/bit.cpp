#include<bits/stdc++.h>
 
#define ar array 
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for(int i = a; i < b; i++)
 
using namespace std;
 
typedef long long ll; 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
 
 
const  int mxN = 3e5+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;

struct fenwick {
    vector<int> bit;  // binary indexed tree
    int sz;

    fenwick(int _n) {
        this->sz = _n + 1;
        bit.assign(_n + 1, 0);
    }

    fenwick(vector<int> a)
        : fenwick(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (++idx; idx < sz; idx += idx & -idx)
            bit[idx] += delta;
    }
};

int n;
int a[mxN];
int next_sm[mxN], prev_gr[mxN];


ll get() {
	stack<pair<int, int> > st;
	
	for(int i = 0; i < n; i++) {
		if(st.empty()) {
			st.push({a[i], i});
			continue;
		}
		
		while(!st.empty() && st.top().fi > a[i]) {
			next_sm[st.top().se] = i;
			st.pop();
		}
		st.push({a[i], i});
	}
	while(!st.empty()) {
		next_sm[st.top().se] = n;
		st.pop();
	}
	
	
	
	
	for(int i = n - 1; i >= 0; i--) {
		if(st.empty()) {
			st.push({a[i], i});
			continue;
		}
		
		while(!st.empty() && st.top().fi < a[i]) {
			prev_gr[st.top().se] = i;
			st.pop();
		}
		st.push({a[i], i});
	}
	while(!st.empty()) {
		prev_gr[st.top().se] = -1;
		st.pop();
	}
	
	//rep(i, 0, n) cout << next_sm[i] << " ";
	//cout << endl;
	//rep(i, 0, n) cout << prev_gr[i] << " ";
	
	
	fenwick fen(n);
	
	vector<pii> prev;
	
	for(int i = 0; i < n; i++) {
		prev.pb({prev_gr[i], i});
	}
	sort(all(prev));
	
	ll ret = 0;
	
	int j = 0;
	for(int i = 0; i < n; i++) {
		while(j < n && prev[j].fi < i) {
			fen.add(prev[j].se, 1);
			j++;
		}
		ret += fen.sum(i, next_sm[i] - 1);
	}
	return ret;
}

void solve() {
	ll ans = 0;
	ans += get();
	reverse(a, a + n);
	ans += get();
	
	int cnt = 1;
	for(int i = 1; i < n; i++) {
		if(a[i] == a[i - 1]) cnt++;
		else {
			ans -= (cnt * 1LL * (cnt + 1))/2;
			cnt = 1;
		}
	}
	
	ans -= (cnt * 1LL * (cnt + 1))/2;
	
	cout << ans << endl;
}
	
	


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		rep(i, 0, n) cin >> a[i];
		solve();
	}
		
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
