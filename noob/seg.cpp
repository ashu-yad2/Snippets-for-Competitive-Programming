#include<bits/stdc++.h>
 
#define ar array 
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i,a,b) for(int i = a; i < b; i++)
#define deb(x) cout << #x << "=" << x << endl
#define PI 3.1415926535897932384626
#define endl '\n'
 
using namespace std;
 
typedef long long ll; 
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
 
 
const  int mxN = 2e5+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;

ll seg[4 * mxN];
ll lazy[4 * mxN];
ll arr[mxN], ans[mxN];

void push(int id, int l, int r) {
	seg[2 * id] += lazy[id];
	seg[2 * id + 1] += lazy[id];
	lazy[2 * id] += lazy[id];
	lazy[2 * id + 1] += lazy[id];
	lazy[id] = 0;
}

void build(int id, int l, int r) {
	if(l == r) {
		seg[id] = arr[l];
		return;
	}
	
	int mid = (l + r)/2;
	
	build(2 * id, l, mid);
	build(2 * id + 1, mid + 1, r);
	
	seg[id] = min(seg[2 * id] ,seg[2 * id + 1]);
}

int get(int id, int l, int r) {
	if(l == r) {
		return l;
	}
	
	push(id, l, r);
	int mid = (l + r)/2;
	
	if(seg[2 * id + 1] != 0) 
	return get(2 * id, l , mid);
	else return get(2 * id + 1, mid + 1, r);
}
	
	
void update(int id, int start, int end, int l, int r,ll val) {
	if(l > r) return ;
	
	if(start == l && end == r) {
		seg[id] += val;
		lazy[id] += val;
		return;
	}
	push(id, start, end);
	
	int mid = (start + end)/2;
	
	update(2 * id, start, mid,l, min(r, mid), val);
	update(2 * id + 1, mid + 1, end, max(mid + 1, l), r, val);
	
	seg[id] = min(seg[2 * id] , seg[2 * id + 1]);
}
	
		

void solve() {
	int  n;
	cin >> n;
	
	rep(i, 1, n + 1) cin >> arr[i];
	
	build(1, 1, n);
	
	
	
	for(int i = 1; i <= n; i++) {
		int temp = get(1, 1, n);
		ans[temp] = i;
		
		update(1, 1, n, temp + 1, n, -i);
		update(1, 1, n, temp, temp, INF);		
	}
	
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

