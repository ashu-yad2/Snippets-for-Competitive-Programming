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
 
 
const  int mxN = 1e5+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;

vector<pair<ll, ll> > adj[mxN];
ll n;
vector<ll> par(mxN, -1), vis(mxN, 0), d(mxN, INF);

	

void dijkstra() {
	
	
	d[1] = 0;
	
	priority_queue<pair<ll,ll>,vector<pair<ll,ll> >, greater<pair<ll,ll> > > q;
	
	q.push({0, 1});
	
	while(!q.empty()) {
		int u = q.top().se;
		q.pop();
		
		if(vis[u]) continue;
		
		vis[u] = true;
		for(auto p: adj[u]) {
			if(d[p.fi] > d[u] + p.se) {
				d[p.fi] = d[u] + p.se;
				par[p.fi] = u;
				q.push({d[p.fi], p.fi});
			}
		}
	}
	
	//for(int i = 1; i <= n; i++) {
		//cout << d[i] << " ";
	//}
	
}
	
	
	

void solve() {
	ll m;
	cin >> n >> m;
	
	
	rep(i, 0, m) {
		ll a, b, c;
		cin >> a >> b >> c;
		adj[a].pb({b,c});
		adj[b].pb({a, c});
	}
	
	
	dijkstra();
	
	if(par[n] == -1) {
		cout << -1 ;
		return;
	}
	
	vll ans;
	int x = n;
	
	while(x != -1) {
		ans.pb(x);
		x = par[x];
	}
	
	reverse(all(ans));
	
	for(auto u: ans) {
		cout << u << " " ;
	}
	cout << endl;
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
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
