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

int arr[mxN];
int lazy[4 * mxN]; 

struct node {
	int cnt0, cnt1, cnt2;
	
	void add() {
		int temp = cnt0;
		cnt0 = cnt2;
		cnt2 = cnt1;
		cnt1 = temp;
	}
	
	void merge(node left, node right) {
		cnt0 = left.cnt0 + right.cnt0;
		cnt1 = left.cnt1 + right.cnt1;
		cnt2 = left.cnt2 + right.cnt2;
	}
	
} seg[4 * mxN];


void build(int low, int high, int id) {
	if(low > high) return;
	
	if(low == high) {
		seg[id].cnt0 = 1;
		seg[id].cnt1 = 0;
		seg[id].cnt2 = 0;
		return;
	}
	
	int mid = (low + high) >> 1;
	
	build(low, mid , 2 * id);
	build(mid + 1, high, 2 * id + 1);
	
	seg[id].merge(seg[2 * id] , seg[2 * id + 1]);
}

void update(int low, int high, int lq, int hq, int id) {
	
	if(lazy[id] % 3 == 1) {
		seg[id].add();
		if(low != high) {
			lazy[2 * id] += lazy[id] % 3;
			lazy[2 * id + 1] += lazy[id] % 3;
		}
	}
	
	else if(lazy[id] % 3 == 2) {
		seg[id].add();
		seg[id].add();
		if(low != high) {
			lazy[2 * id] += lazy[id] % 3;
			lazy[2 * id + 1] += lazy[id] % 3;
		}
	}
	
	else if(lazy[id] && lazy[id] % 3 == 0) { // removing the case when lazy is empty
		if(low != high) {
			lazy[2 * id] += lazy[id] % 3;
			lazy[2 * id + 1] += lazy[id] % 3;
		}
	}
	lazy[id] = 0;
	
	if(low > high || low > hq || high < lq) return;
	
	if(lq <= low && high <= hq) {
		seg[id].add();
	
		if(low != high) {
			lazy[2 * id] += 1;
			lazy[2 * id + 1] += 1;
		}
		return ;
	}
	
	int mid = (low + high) >> 1;
	
	update(low, mid, lq, hq, 2 * id);
	update(mid + 1, high, lq, hq, 2 * id + 1);
	seg[id].merge(seg[2 * id] , seg[2 * id + 1]);
}


node query(int low, int high, int lq, int hq, int id) {
	
	node ans;
	ans.cnt0 = 0;
	ans.cnt1 = 0;
	ans.cnt2 = 0;
	
	if(lazy[id] % 3 == 1) {
		seg[id].add();
		if(low != high) {
			lazy[2 * id] += lazy[id] % 3;
			lazy[2 * id + 1] += lazy[id] % 3;
		}
	}
	
	else if(lazy[id] % 3 == 2) {
		seg[id].add();
		seg[id].add();
		if(low != high) {
			lazy[2 * id] += lazy[id] % 3;
			lazy[2 * id + 1] += lazy[id] % 3;
		}
	}
	
	else if(lazy[id] && lazy[id] % 3 == 0) {
		if(low != high) {
			lazy[2 * id] += lazy[id] % 3;
			lazy[2 * id + 1] += lazy[id] % 3;
		}
	}
	lazy[id] = 0;
	
	if(low > high || low > hq || high < lq) return ans;
	
	if(lq <= low && high <= hq) {
		return seg[id];
	}
	
	int mid = (low + high) >> 1;
	
	node left = query(low, mid , lq, hq, 2 * id);
	node right = query(mid + 1, high, lq, hq, 2 * id + 1);
	
	ans.merge(left, right);
	return ans;
}
		
 	
signed main(){
	
	int n, q;
	scanf("%d %d", &n, &q);
	
	int type, l, r;
	
	build(1, n, 1);
	
	while(q--) {
		scanf("%d %d %d", &type, &l, &r);
		l++, r++;
		
		if(type) {
			printf("%d\n", query(1, n, l, r, 1).cnt0);
		}
		else update(1, n, l, r, 1);
	}
}
	
		
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
