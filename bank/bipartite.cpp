// this is to check bipartite matching by two coloring and counting sets too
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
typedef pair<int,int> pii;
 
 
const  int mxN = 3e5+5;
const  long long INF= 1e18;
const long long mod= 998244353;

vi adj[mxN];
int p2[mxN];
int n, m;
int col[mxN];
int l, r;
bool check;

void dfs(int v, int c) {
	col[v] = c;
	if(c == 0) l++;
	else r++;
	for(auto x: adj[v]) {
		if(col[x] == -1) dfs(x, c^1);
		if((col[x] ^ col[v]) == 0) {
			check = true;
		}
	}
}
 	
signed main(){
	p2[0] = 1;
	for(int i = 1; i < mxN; i++) {
		p2[i] = (2 * p2[i - 1]) % mod;
	}
	
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		
		for(int i = 1; i <= n; i++) adj[i].clear();
		
		for(int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		
		ll ans = 1;
		
		for(int i = 1; i <= n; i++) col[i] = -1;
		
		
		for(int i = 1; i <= n; i++) {
			if(col[i] != -1) continue;
			check = false;
			l = r = 0;
			dfs(i, 0);
			
			if(check) break;
			
			ll temp = (p2[l] + p2[r]) % mod;
			
			ans = (ans * temp) % mod;
		}
		
		if(check) cout << 0 << endl;
		else cout << ans << endl;
	}
}
			
		
		
		
		
	
	
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
