#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
 
#ifdef EBUG
	#define bug(x) { cout << "*** " << #x << " " << x << '\n' << flush; }
 
	#define bug2(x,y) { cout << "*** " << #x << " " << x \
                        << " " << #y << " " << y << '\n' << flush; }
 
	#define bugV(V) { cout << "*** "; for( auto v:V) cout << v << " ";\
                      cout << '\n' << flush; }
 
	#define bugL() { cout << "----------\n"; }
#else
	#define bug(x) { ; }
	#define bug2(x,y) { ; }
	#define bugV(V) { ; }
	#define bugL() { ; }
#endif
 
#define all(v) v.begin(), v.end()
 
void solve(){
	ll n, k; 
	cin >> n >> k;
	vector<ll> a(n); for(int i = 0; i < n; i++) cin >> a[i]; 
	vector<ll> b(n); for(int i = 0; i < n; i++) cin >> b[i]; 
	long long max_b = 0, ans = 0, acc = 0;
	for(int i = 0; i < min(k, n); i++){
		acc += a[i];
		max_b = max(b[i], max_b);
		ll curr = acc + (k - i - 1)*max_b;
		ans = max(ans, curr);
	}
	cout << ans << endl;

}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
