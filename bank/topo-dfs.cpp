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
 
 
const  int mxN = 1e5+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;

vi adj[26];
bool vis[26];
bool instack[26];
string a[50];
string ans;
bool check;

void dfs(int u) {
	vis[u] = 1;
	instack[u] = 1;
	for(auto x: adj[u]) {
		if(instack[x]) { // cylcle in DAG
			check = true; 
		}
		else {
			if(!vis[x]) {
				dfs(x);
			}
		}
	}
	
	instack[u] = 0;
	ans += char(u + 'A'); // order of topo sort
}


			



int main() {
	int t;
	cin >> t;
	for(int l = 1; l <= t; l++) {
		cout << "Case #"<<l<<": ";
		for(int i = 0; i < 26; i++) {
			adj[i].clear();
			vis[i] = instack[i] = 0;
		}
		
		
		ans = "";
		check = false;
		
		
		int n, m;
		cin >> n >> m;
		
		set<char> s;
		
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			for(auto x: a[i]) s.insert(x);
			
			if(i) {
				for(int j = 0; j < m; j++) {
					if(a[i - 1][j] != a[i][j])
					adj[a[i][j] - 'A'].pb(a[i - 1][j] - 'A');
				}
			}
		}
		
		for(auto x: s) {
			if(!vis[x - 'A'])
			dfs(x - 'A');
		}
		reverse(all(ans));
		if(check) cout << -1 << endl;
		else cout << ans << endl;
		
	}	
			
			
		
		
}
		
		
		
		
		
	
		
	
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
