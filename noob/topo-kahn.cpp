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
string a[50];
string ans;			

int main() {
	int t;
	cin >> t;
	for(int l = 1; l <= t; l++) {
		cout << "Case #"<<l<<": ";
		
		int n, m;
		cin >> n >> m;
		
		
		for(int i = 0; i < 26; i++) adj[i].clear();
		ans = "";
		
		set<char> s;
		vi indeg(26, 0);
		
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			for(auto x: a[i]) s.insert(x);
			
			if(i) {
				for(int j = 0; j < m; j++) {
					if(a[i - 1][j] != a[i][j]) {
					adj[a[i][j] - 'A'].pb(a[i - 1][j] - 'A');
					indeg[a[i - 1][j] - 'A']++;
				}
					
				}
			}
		}
		
		queue<int> q;
		int cnt = 0;
		
		for(auto x: s) {
			if(indeg[x - 'A'] == 0) q.push(x - 'A');
		}
		
		
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			cnt++;
			ans += char(u + 'A');
			for(auto x: adj[u]) {
				indeg[x]--;
				if(indeg[x] == 0) q.push(x);
			}
		}
		if(cnt != (int)s.size()) cout << -1 << endl;
		else cout << ans << endl;
	}
}
		
		
		
		
		
	
		
	
		
	
	
	
	
	
	
