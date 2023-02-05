#include <bits/stdc++.h>

// #define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define lld long double
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
using namespace std;

const double PI = 2*acos(0.0);

class TrieNode {
public:
    bool endOfWord;
    map<char,TrieNode*> children;

    TrieNode() {
        this->endOfWord = false;
        children['A'] = children['C'] = children['G'] = children['T'] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode;
    }

    void insert(string &s) {
        TrieNode* r = root;
        for(char ch : s) {
            if(r->children[ch] == NULL) 
                r->children[ch] = new TrieNode();
            r = r->children[ch];
        }
        r->endOfWord = true;
    }

    void search(string &s, int start) {
        TrieNode* r = root;
        for(int i = start; i < s.size() ; i++) {
            char ch = s[i];
            if(r->children[ch] == NULL) 
                return;
            r = r->children[ch];

            if(r->endOfWord) {
                cout<< start << " ";
                return;
            }
        }
    }
};

void solve()
{
    Trie* t = new Trie();
    string text;
    cin>>text;
    int n;
    cin>>n;
    string pattern;
    for(int i=0;i<n;i++) {
        cin>>pattern;
        t->insert(pattern);
    }

    for(int i=0;i<text.size();i++) {
        t->search(text, i);
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
	//cin>>t;
	int t1=t;
	while(t--)
	{
	    //cout<<"Case #"<<t1-t<<": ";
		solve();
		// cout<<endl;
	}
	return 0;
}