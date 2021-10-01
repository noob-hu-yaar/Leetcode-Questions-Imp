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

void solve() {

	string s; cin>>s;
	int n = s.length();
	int mod = 1000000007;
	bool dp[n][n];
	memset(dp, false, sizeof(dp));

	for (int i=0; i<n ; i++)
		dp[i][i] = true;
	// for substring of length 2
	for (int i=1; i<n; i++)
		dp[i-1][i] = s[i-1]==s[i];
	// for 2+ length substring
	for (int k=3; k<=n; k++)
	for (int i=0; i<n-k+1 ; i++) {
		int j = i+k-1;
		if (s[i]==s[j] and dp[i+1][j-1])
			dp[i][j] = true;
	}

	u_s<string> st;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (dp[i][j]==false) {
				string rev = s.substr(i,j-i+1);
				reverse(rev.begin(), rev.end());
				string sub = s.substr(0,i) + rev + s.substr(j+1);
				// if (j<n-1) sub += s.substr(j+1);
				st.insert(sub);
			}
		}
	}
	cout << st.size()+1 << el;

	cout << "Strings: ";
	for (auto i=st.begin(); i!=st.end(); i++) {
		cout << *i << " ";
	}
	cout << el;

	// int palindromes = 0;
	// for (int i=0; i<n; i++) {
	// 	for (int j=i; j<n; j++) {
	// 		if (dp[i][j]==true) {
	// 			palindromes++;
	// 		}
	// 	}
	// }

	// int ans = (n*(n+1))/2 - palindromes + 1;
	// cout << palindromes << el;
}

// ================ MAIN FUNCTION ===============
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; cin>>t;
	while (t--) {
		solve();
	}
}