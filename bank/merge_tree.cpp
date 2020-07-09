#include<bits/stdc++.h>
 
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i,n) for(int i = 0; i < n; i++)
#define for1(i,n) for(int i = 1; i <= n; i++)
#define ford(i,n) for(int i = n-1; i >= 0; i--)
#define fore(i,a,b) for(int i = a; i <= b; i++)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
 
 
const  int MAXn= 1e5+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;
 
vector<int> a[MAXn];
vector<int> st[4 * MAXn];

void build(int id, int l, int r) {
	if(r == l) {
		st[id] = a[l];
		return;
	}
	int mid = (l + r)/2;
	
	build(2 * id, l, mid) ;
	build(2 * id + 1, mid + 1, r);
	merge(st[2 * id].begin(), st[2 * id].end(), st[2 * id + 1].begin(), st[2 * id + 1].end(), back_inserter(st[id]));
}

int query(int id, int start, int end, int l, int r,int x, int y) {
	if(start > end || start > r || end < l) return 0;
	if( start >= l && end <= r) {
		auto  ans1 = lower_bound(st[id].begin(), st[id].end(), x);
		auto ans2 = upper_bound(st[id].begin(), st[id].end(), y) ;
		return ans2 - ans1;
	}
	int mid = (start + end) / 2;
	return query(2 * id, start, mid, l, r, x, y) + query(2 * id + 1, mid + 1, end, l, r, x, y);
} 
	
 
int main(){
	int n;
	cin >> n;
	forn(i, n) {
		int l, r;
		cin >> l >> r;
		a[l].pb(r);
	}
	
	for(int i = 0; i < MAXn; i++) {
		sort(all(a[i]));
	}
	build(1, 0, 100000);
	int q;
	cin >> q;
	while(q--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		int ans = query(1,0, 100000, l1, r1, l2, r2); 
		cout << ans << '\n';
	}
}
