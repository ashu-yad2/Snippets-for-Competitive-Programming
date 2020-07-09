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
 
 
const  int mxN = 1e6+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;

int seg[4 * mxN];

void upd(int node, int low, int high, int i, int val) {
	if(low == high) {
		seg[node] += val;
		return;
	}
	
	int mid = (low + high)/2;
	
	if(i <= mid) {
		upd(2 * node, low, mid, i, val);}
		else upd(2 * node + 1, mid + 1, high, i , val);
		
		seg[node] = seg[2 * node] + seg[2 * node + 1];
	}
	
int query(int node, int low, int high, int rank) {
	if(low == high) return low;
	
	int mid = (low + high)/2;
	
	if(seg[2 * node] >= rank) {
		return query(2 * node, low, mid , rank);
	}
	else return query(2 * node + 1, mid + 1, high, rank - seg[2 * node]);
}	


 	
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		upd(1, 1, n, x, 1);
	}	
	
	while(q--) {
		int x;
		cin >> x;
		if(x > 0) upd(1, 1, n, x, 1);
		else {
		int i = query(1, 1, n, -x);
		upd(1, 1, n, i, -1);
		}
	}
	
	if(seg[1] == 0) {
		cout << 0;
	}
	else cout << query(1, 1, n, 1) ;	
}
		
		
	
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
