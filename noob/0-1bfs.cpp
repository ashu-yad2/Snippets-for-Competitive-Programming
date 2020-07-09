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

int n, m;
vector<string> v;
int vis[2005][2005];
int dis[2005][2005];

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {-1, 0, 1, 0};
const int w[4] = {1, 0, 0, 0}; 

bool c(int x, int y) {
	if(x < 0 || x >= n || y < 0 || y >= m) return false;
	if(v[x][y] == '*' || vis[x][y]) return false;
	else return true;
}

int main() {
	cin >> n >> m;
	int _x, _y;
	cin >> _x >> _y;
	_x--; _y--;
	
	int a, b;
	cin >> a >> b;
	v.clear();
	v.resize(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			dis[i][j] = 1e9;
		}
	}
	dis[_x][_y] = 0;
	deque<pii> q;
	
	q.push_back({_x, _y});
		
	int ans = 0;
	
	
	while(!q.empty()) {
		auto p = q.front();
		q.pop_front();
		
		int x = p.fi;
		int y = p.se;
		if(vis[x][y]) continue;
		vis[x][y] = 1;
		
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int cost = w[i];
			
			if(!c(nx, ny)) continue;
			
			if(dis[nx][ny] > dis[x][y] + cost) {
				dis[nx][ny] = dis[x][y] + cost;
				if(cost) q.push_back({nx, ny});
				else q.push_front({nx, ny});
			}
		}
	}
	
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int left = dis[i][j];
			if(left == 1e9) continue;
			int right = left + j - _y;
			if(left <= a && right <= b) ans++;
		}
	}	
	cout << ans;
}
		
		
	
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
