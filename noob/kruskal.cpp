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

int par[mxN];

vi k[mxN];
int _k;
bool flag = false;

int find(int a) {
	if(a == par[a]) return a;
	 return par[a] = find(par[a]);
 }


void join(int a, int b) {
	a = find(a);
	b = find(b);
	if(k[b].size() > k[a].size()) swap(a, b);
	for(auto x: k[b]) {
		k[a].pb(x);
	}
	par[b] = a;
	if((int)k[a].size() == _k) {
		flag = true;
	}
}

bool check(int a, int b){ return find(a) == find(b); }


 	
signed main(){
	int n, _m;
	cin >> n >> _m >> _k;
	
	rep(i, 1, n + 1) par[i] = i;
	
	
	rep(i, 0, _k) {
		int x;
		cin >> x;
		k[x].pb(i);
	}
	
	map<pii, int> m;
	
	rep(i, 0, _m) {
		int a, b, c;
		cin >> a >> b >> c;
		if(a > b) swap(a, b);
		if(a == b) continue;
		
		if(m.count({a, b})) {
			m[{a, b}] = min(m[{a, b}], c);
		}
		else m[{a, b}] = c;
	}
	
	priority_queue< pair<int , pii> > q;
	
	for(auto x: m) {
		q.push({-x.se, x.fi});
	}
	
	int ans;
	
	while(1) {
		auto x = q.top();
		q.pop();
		if(!check(x.se.fi, x.se.se)) {
			join(x.se.fi, x.se.se);
			
			if(flag) {
				ans = -x.fi;
				break;
			}
			
		}
	}
	rep(i, 0, _k)
	cout << ans << " ";
}
		
		
	
	
		
		
	
	
 
 
	 
		
		
	
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
