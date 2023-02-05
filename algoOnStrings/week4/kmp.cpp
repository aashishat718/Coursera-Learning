#include <bits/stdc++.h>

// #define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define lld long double
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
using namespace std;

const double PI = 2*acos(0.0);

void computeLps(string &pat, int* lps)
{
    int n = pat.size();
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while(i < n) {
        if(pat[i] == pat[len])
            lps[i++] = ++len;
        else {
            if(len != 0)
                len = lps[len-1];
            else
                lps[i++] = 0;
        }
    }
}

void solve()
{
    string pat, text;
    cin>>pat>>text;

    string s = pat + "$" + text;
    int n = s.size();
    int lps[n];
    computeLps(s, lps);

    for(int i=0;i<n;i++) {
        if(lps[i] == pat.size())
            cout<< i - 2*pat.size() << " ";
    }
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