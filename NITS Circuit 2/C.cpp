#include<bits/stdc++.h>
#include<iostream>
#define el "\n"
#define ll long long
#define pb push_back
#define u_m unordered_map
#define u_s unordered_set
#define p_q priority_queue
#define ff first
#define ss second
#define mp make_pair
using namespace std;


int cal(int a[], int n) {

	int mod = 1000000007;
	int dp[n];

	if (a[n-1]%2==0) {
		dp[n-1] = 1;
	}
	else {
		dp[n-1] = 0;
	}

	for (int i=n-2; i>=0; i--) {
		if (a[i]%2 != 0) {
			dp[i] = dp[i+1]*2;
		}
		else {
			dp[i] = (2*dp[i+1])%mod + 1;
		}
		dp[i] %= mod;
	}

	return dp[0];
}

// ================ MAIN FUNCTION ===============
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll t; cin>>t;
	while (t--) {
		int n; cin>>n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin>>a[i];
		}
		cout << cal(a,n) << el;
	}
}