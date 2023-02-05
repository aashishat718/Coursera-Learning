#include <bits/stdc++.h>

// #define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define lld long double
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
using namespace std;

const double PI = 2*acos(0.0);

void solve()
{
    string s;
    cin>>s;
    int n = s.size();

    vector<pair<string,int>> suffixes;
    string suffix = "";
    for(int i=n-1;i>=0;i--) {
        suffix.insert(suffix.begin(),s[i]);
        suffixes.push_back({suffix,i});
    }

    sort(suffixes.begin(),suffixes.end());
    for(pair<string,int> p : suffixes)
        cout<< p.second << " ";
}

int main()
{
	// boost;
	
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	// #endif // ONLINE_JUDGE

	int t=1;
	// cin>>t;
	int t1=t;
	while(t--)
	{
	    //cout<<"Case #"<<t1-t<<": ";
		solve();
		cout<<endl;
	}
	return 0;
}