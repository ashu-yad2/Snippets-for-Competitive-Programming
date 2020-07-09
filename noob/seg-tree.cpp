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
typedef double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
 
 
const  int MAXn= 3e5+5;
const  long long INF= 1e18;
const long long mod= 1e9+7;
 
 struct node{
	int sum,p_sum,s_sum,m_sum;
}st[MAXn];
 
 
int a[MAXn];
 
void build(int id,int l,int r){
	if(l==r){
		st[id].sum=a[l];
		st[id].p_sum=a[l];
		st[id].s_sum=a[l];
		st[id].m_sum=a[l];
		return;
	}
	int mid= (l+r)/2;
	
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	
	st[id].sum= st[id*2].sum+st[id*2+1].sum;
	st[id].p_sum= max(st[id*2].p_sum, st[id*2].sum + st[id*2+1].p_sum);
	st[id].s_sum= max(st[id*2+1].s_sum, st[id*2].s_sum + st[id*2+1].sum);
	st[id].m_sum= max({st[id].sum,max(st[id].p_sum,st[id].s_sum), max(st[id*2].m_sum,st[id*2+1].m_sum),st[id*2].s_sum+st[id*2+1].p_sum});
}
 
node query(int id,int start,int end,int l,int r){
	node result;
	result.sum=result.p_sum=result.s_sum=result.m_sum=INT_MIN;
	
	if(r<start || l> end)
		return result;
		
	if(l<=start && end<=r)
		return st[id];
		
	int mid= (start+end)/2;
	
	if(l>mid)return query(id*2+1,mid+1,end,l,r);
	else if(r<=mid) return query(id*2,start,mid,l,r);
	
	node left= query(id*2,start,mid,l,r);
	node right= query(id*2+1,mid+1,end,l,r);
	
	result.sum= left.sum+right.sum;
	result.p_sum= max(left.p_sum, left.sum+ right.p_sum);
	result.s_sum= max(right.s_sum, right.sum + left.s_sum);
	
	result.m_sum= max({result.sum,max(result.p_sum,result.s_sum),max(left.m_sum, right.m_sum),left.s_sum+right.p_sum});
	
	return result;
		
}
 
void update(int id,int start,int end,int index,int value){
	if(start==end){
		st[id].sum=value;
		st[id].p_sum=value;
		st[id].s_sum=value;
		st[id].m_sum=value;
		return;
	}
	else{ int mid= (start+end)/2;
		
		if(index<=mid) update(id*2,start,mid,index,value);
		else update(id*2+1,mid+1,end,index,value);
		
		st[id].sum= st[id*2].sum+st[id*2+1].sum;
	st[id].p_sum= max(st[id*2].p_sum, st[id*2].sum + st[id*2+1].p_sum);
	st[id].s_sum= max(st[id*2+1].s_sum, st[id*2].s_sum + st[id*2+1].sum);
	st[id].m_sum= max({st[id].sum,max(st[id].p_sum,st[id].s_sum), max(st[id*2].m_sum,st[id*2+1].m_sum),st[id*2].s_sum+st[id*2+1].p_sum});
}
}
	
 
int main(){
    int n;
    cin>>n;
    for1(i,n) cin>>a[i];
    
    build(1,1,n);
    
    int q;
    cin>>q;
    while(q--){
		int x; cin>>x;
		if(x){
		int l,r;
		cin>>l>>r;
		node ans= query(1,1,n,l,r);
		cout<<ans.m_sum<<endl;
	}
	else{
		int index,value;
		cin>>index>>value;
		update(1,1,n,index,value);
	}
}
}    
    
