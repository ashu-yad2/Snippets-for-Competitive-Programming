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
 
 
const  int mxN = 505;
const  long long INF= 1e18;
const long long mod= 1e9+7;
 
bool adj[mxN][mxN];
int n, k;
bool vis[mxN];
int assign[mxN];

bool dfs(int u) {
	for(int v = 1; v <= n; v++) {
		if(!vis[v] && adj[u][v]) {
			vis[v] = 1;
			
			if(assign[v] < 0 || dfs(assign[v])) {
				assign[v] = u;
				return true;
			}
		}
	}
return false;
}
			

 
int main(){
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		memset(adj, 1, sizeof(adj)); 
		
		memset(assign, -1, sizeof(assign));
	//	for1(i, n) cout << assign[i]<<" ";
		for1(i, n) adj[i][i] = 0;
		
		while(k--) {
			vi a(n);
			forn(i, n) cin >> a[i];
			
			for(int i = n - 1; i >= 1; i--) {
				for(int j = i - 1; j >= 0; j--) {
					adj[a[j]][a[i]] = 0;
				}
			}
		}
		
		int ans = 0;
		
		for(int i = 1; i <= n; i++) {
			memset(vis, 0, sizeof(vis));
			
			ans += dfs(i);
		}
		
		ans = n - ans;
		cout << ans << endl;
		for(int i = 1; i <= n; i++) {
			if(assign[i] == -1) assign[i]++;
			cout << assign[i] << " ";
		}
		cout << endl;
	}
}
			
			
		
		
			
			
		
		
