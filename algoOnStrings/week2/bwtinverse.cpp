#include <bits/stdc++.h>

// #define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define lld long double
#define f(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(), v.end()
#define mod 1000000007
using namespace std;

const double PI = 2*acos(0.0);

void solve()
{
    string bwt, f;
    cin>>bwt;

    int n = bwt.size();
    f = bwt;
    sort(f.begin(), f.end());

    map<char, vector<int>> mpBwt, mpF;
    for(int i=0;i<n;i++) {
        mpBwt[bwt[i]].push_back(i);
        mpF[f[i]].push_back(i);
    }

    string ans = "";
    int currInd = mpBwt['$'][0];
    char ch = f[currInd];
    while(ch != '$') {
        ans.push_back(ch);

        int order = lower_bound(all(mpF[ch]), currInd) - mpF[ch].begin();

        currInd = mpBwt[ch][order];
        ch = f[currInd];
    }
    ans.push_back('$');

    cout<< ans << endl;
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
		//cout<<endl;
	}
	return 0;
}