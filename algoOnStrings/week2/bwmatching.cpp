#include <bits/stdc++.h>

// #define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define lld long double
#define f(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(), v.end()
#define mod 1000000007
using namespace std;

const double PI = 2*acos(0.0);

int betterBWMatching(unordered_map<char,int> firstOccurence, string &bwt, vector<map<char,int>> &count, string &pat)
{
    int top = 0, bottom = bwt.size()-1;
    int ind = pat.size()-1;
    while(top <= bottom) {
        if(ind >= 0) {
            char ch = pat[ind];
            ind--;
            if( (count[bottom+1][ch] - count[top][ch]) > 0 ) {
                top = firstOccurence[ch] + count[top][ch];
                bottom = firstOccurence[ch] + count[bottom+1][ch] - 1;
            }
            else
                return 0;
        }
        else
            return bottom-top+1;
    }
    return -1; // might not reach !
}

void solve()
{
    string bwt, f, pattern;
    cin>>bwt;

    f = bwt;
    sort(all(f));
    int n = bwt.size();
    unordered_map<char,int> firstOccurence;

    vector<map<char,int>> count(n+1);
    count[0] = {};
    for(int i=0;i<n;i++) {
        count[i+1] = count[i];
        count[i+1][bwt[i]]++;

        if(firstOccurence.find(f[i]) == firstOccurence.end())
            firstOccurence[f[i]] = i;
    }

    int pc;
    cin>>pc;
    while(pc--) {
        cin>>pattern;
        int c = betterBWMatching(firstOccurence, bwt, count, pattern);
        cout<< c << " ";
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