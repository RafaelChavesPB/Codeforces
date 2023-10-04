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
	
	#define bugP(V) { cout << "*** "; for( auto v:V) cout << v.first << ':' << v.second << " ";\
                      cout << '\n' << flush; }
 

	#define bugL() { cout << "----------\n"; }
#else
	#define bug(x) { ; }
	#define bug2(x,y) { ; }
	#define bugV(V) { ; }
	#define bugP(V) { ; }
	#define bugL() { ; }
#endif
 
#define all(v) v.begin(), v.end()
 
void solve(){
	ll n; 
	cin >>n;
	vector<ll> prefix(n + 1, 0);  
	vector<pair<ll, int>> arr(n+1);
	vector<bool> winner(n+1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	};
	sort(arr.begin(), arr.end());
	for(int i = 1; i <= n; i++)
		prefix[i] = prefix[i - 1] + arr[i].first;
	int count = 1;
	winner[arr[n].second] = 1;
	for(int i = n - 1; i > 0 ; i--){
		if(prefix[i] >= arr[i+1].first and winner[arr[i+1].second]){
			count++;
			winner[arr[i].second] = 1;
		}
	}
	cout << count << '\n';
	for(int i = 1; i <= n; i++){
		if(winner[i])
			cout << i << ' ';
	}
	cout << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}
