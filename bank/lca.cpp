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
 
 
const  int mxN = 2e5+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;

vi adj[mxN];
int d[mxN], par[mxN], anc[mxN][19];
int val[mxN];

void dfs(int v, int p) {
	par[v] = p;
	anc[v][0] = p;
	for(int i = 1; i < 19; i++) {
		anc[v][i] = anc[anc[v][i - 1]][i - 1];
	}
	for(auto x: adj[v]) {
		if(x != p) {
			d[x] = d[v] + 1;
			dfs(x, v);
		}
	}
}

int lca2(int u, int v) {
	if(d[u] < d[v])
		swap(u, v);	
	for(int i=18; i >= 0; --i)
		if(d[u]- (1<<i) >= d[v])
			u = anc[u][i];
						
	if(u == v)
		return u;
		
	for(int i= 18; i >= 0; --i) {
		if(anc[u][i] != anc[v][i]) {
			u = anc[u][i];
			v = anc[v][i];
		}
	}
	return anc[u][0];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, q;
		cin >> n >> q;
		
		for(int i = 1; i <= n; i++) adj[i].clear();
		
		rep(i, 1, n + 1) cin >> val[i];
			
		rep(i, 0, n - 1) {
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		
		dfs(1, 1);
		
		
		while(q--) {
			int x, y;
			cin >> x >> y;
			int l = lca2(x, y);
			
			if(d[x] < d[y]) swap(x, y);
			
			if((d[x] - d[y]) > 105) {
				cout << 0 << endl;
				continue;
			}
			
			vi temp;
			temp.pb(val[x]);
			x = par[x];
			
			int ans = 1e9;
			
			while(x != l && x != y) {
				temp.pb(val[x]);
				x = par[x];
			}
			
			temp.pb(val[y]);
			
			if(x == l && x != y) {
				y = par[y];
				temp.pb(val[x]);
				while(y != l) {
					temp.pb(val[y]);
					y = par[y];
				}
			}
			
			sort(all(temp));
			//for(auto x: temp) cout << x << " ";
			//cout << endl;
			
			for(int i = 1; i < temp.size(); i++) {
				ans = min(ans, temp[i] - temp[i - 1]);
			}
			cout << ans << "\n";
		}
	}
}
			
			
			
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
