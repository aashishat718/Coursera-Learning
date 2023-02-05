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
    int startInd;
    int len;
    vector<TrieNode*> children;

    TrieNode(int startInd, int len) {
        this->startInd = startInd;
        this->len = len;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode(-1, -1);
    }

    void insert(string &s, int start) {
        TrieNode* r = root;
        int n = s.size();
        for(int i=start ; i<n ; i++) {
            bool isPrefixAvailable = false;
            for(TrieNode* child : r->children) {
                int j = child->startInd, k = i;
                bool found = false;
                bool finished = false;
                while(s[k] == s[j]) {
                    isPrefixAvailable = true;
                    k++,j++;
                    found = true;
                    if(j - child->startInd == child->len) {
                        finished = true;
                        break;
                    }
                }

                if(finished) {
                    r = child;
                    i = k-1;
                    break;
                }

                if(found) { 
                    // this means that some prefix is common in trienode and current substring 
                    TrieNode* ch1 = new TrieNode(j, (child->startInd+child->len)-j);
                    TrieNode* ch2 = new TrieNode(k, n-k);
                    child->len = j - child->startInd;

                    if(!child->children.empty()) {
                        ch1->children = child->children;
                        child->children.clear();
                    }
                    child->children.push_back(ch1);
                    child->children.push_back(ch2);

                    return;
                }
            }

            if(r->children.size() == 0 || !isPrefixAvailable) {
                TrieNode* ch = new TrieNode(i, n-i);
                r->children.push_back(ch);
                break;
            }

        }
    }

    void printTrie(string &s) {
        printTrieHelper(s, root);
    }

    void printTrieHelper(string &s, TrieNode* node) {
        for(TrieNode* child : node->children) {
            printTrieHelper(s, child);
        }

        if(node->startInd != -1)
            cout<< s.substr(node->startInd, node->len) << endl;
    }
};

void solve()
{
    Trie* t = new Trie();
    string text;
    cin>>text;

    for(int i=text.size()-1;i>=0;i--) {
        t->insert(text, i);
    }

    t->printTrie(text);
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


/*
    These are few test cases which helped in stress testing:

    AAATAAA$
    AAACAC$
    ACACAA$
    ATAAATG$
    ACA$
    A$
    GCTGTTACGGCACGGCGAGGCCTAGGCTCGCCAATCGCCGAGCAGGAACCCGTTCATATATCCGAAGAACTACTGTGCGGAGGGCGTATGGCATGTGGGCTGAGGTCGGACTCTTTCACCATTCCCATGATAGCGGAAACTCGTCTAGGAGGTGGTCATTACAAGATGGACTGGATCCAGCCGCTTGGAGTACACACTATATTACATCTCCGCGATTGTCCGCTGCATCTGCCCCACGGCCCAGCTCTTCGCGAAAGGGTTACGTCGCCAGGCCGATCTTTCGTCCAGGTCTGGTCAGGTGGTGTGCCAGACTTGTATACCTGTCCATGGGTCTACACTGCGTTCAATGTACTAAGCAACATGTTTTATTCATTAATAAGAAAACTCGAACAGTCTGCTGGCCGTGGGCGAGTGCGTTATGCTCCGCCAACTAGGCGCAGGCTAACCACAGACAATGAGAATAGAGACACTGGGGTAGCGAAGTTGTCTACAGTGTGTCACTATAAAAAGACGGAAGCGCCTTATGCCAACTGACGGAAACCCGTATCGAGGTGCACGCGTGTCTCGCCCACTCACGCGGGTCACCTTCTGTCTTACACCTTCGTGAGTGTCTTACCCCCCTGATGGGAGGCTAAAAACATGTAAGATGCCCGCTGGCAGGCTGGGAAGCGGATAGCTAGGAGGATATGTAAGCGTTAAACTGCCACAAAGACTTGCACAACCGGCTGGCTATAACCATGCACTCCCACCGGGCCTGTCAAGAGGTAGTGTGTGCCGACGCGGATCGCCTCAATGACTGAACAGATTGGCTAAGGTCGGCTACGTCGGGGACTCTGAGGTTTAATATGACCTATTCTCGTGTTATGTTTCCTATAGACGATTTGAGTGTAACCCTTGACGTTGGATAGGGCACCTCTGTTGGTGAATAAAAGTAATGAATCGCGGGGGTGCGCCTGTACGGATTTTAAGCCGATGCATCCCCAAAGTGTGGTAGCATTTCAATGTTAGTATTAGGCTTCACGCGTCAGGCAGTGACCTTTCGTGTAACTAAACATAATAAAGACATTTATTCGGTACATCTAGTTCGGGTGCTCACGCTACATACACGCAGTCCATCGAACGTGTCCGCAAAATAAGCAAGGGACCCCAGTTTCAGCCATTATAAGGCGCTACGAAAGGCTATTTGGACAAGAGCTGCCGTACGGCTTCGGTCTTGTCTAGTATCATGGCTCCCTGCCTCTGGGATTTTATTAAACTTCGTCTCAAGGAGGAGAAGCCAGGCCAAGCCATCCACGCAAGGTTCCATAAAGCACTGCTGGTAATGGGTATCCACCTAAGCTGATTGATTAGGGAGCCCCACAATTTCGACCTTCAGCCACGTTGCATTCCCGCCAACTATTACGAACTATATGACTGATCATCAGGGCACACCGGCAAGACGAATCTCAATCAAAAGTCAGGGTAGCGGAAAAAGATGTAAAAGCAGTGTACATCGTACACGTGAGCGATAGGAAGCCAACCATCAAACTAATTTGCGCCCCCTGGTGTACGCCGCTACTTTTGAAAAGATTGGCGTCGATCCGTGTCATGAGTGCTATTCTGCACTATGTGGAATCAAATGATTGTTCACCGGGATAGCAGCGGGTCAGGCAGGCAGGAGATCCTCGGCATGCCAAAAGTTCTCTCAAACTCCTGAGAACACTCTTGTTCCTGTCTTGGCGCGCACATACCTCAGCCCGACAACTTGCATAAACGTTTTTTGTTTGATGCTCCAAAAGCATGTTGTTCGCCCATTTCGTGCATTCTTCGTGCTACATTCCCCGGTTAGGGAACGAGGATTCAGTCGCTCGAAACTACCTACCAATGGTCTAGGACTCTGGTGCTCGTCGTTGGATCTAGTATCGCAGACTGAGTAACCTATCTGTCGATGATATGACGCGTTGCCAAAGAAGAGATGTCCTTAAGGCGGGTCATGACCAATTCAAAACATATCATGACCTGGAGTCAGGTCCGGGTAAGAGCGTAGAAGCGATCCCCGGTCCAGTCAGATCACTATTTAACGGCAAAGTCTATACCCCAAGCCCGAGGTTCGGTCGACAGCCTGCGAACCGTGTTTACCGCTCCAGGAGCAATGAGATAAATGACTTGTCTCCCTGAACGGTTCTCGTCCCCACTCAATTTTATTACTATTACGCGCAGTCGCGACTTTTGATCAGGGTAGATTCGCGAGGTATACTGCCTGAAGCTTCCAACGAAAGCTCTAATTCGTAGCCTATCCCAAGCTAAATATGACATGAATTGCACTCGCGAGAAATTCTGCCACCAATGCAAGGACGCGCGTATTTCGGCCGCGCGCCAACGCTGTATGATCCGACTCCTACATAAT ... TGATCTGAACAACCTCGACTCAAACTAGTGCTCCCCGTTGGCAGCGTCCACTGAATCCATACTCTAGCGTCGACGTAGGGTGGTTGCTGGAGTGCCCAAGATCTAGGAGACGGTGCCCGCGCAATGAAGCGACACCTACGTATAATTAAGTGTCTATCAATTAAACTATTGGGTGGCCGGCATGGTACGCTATCTACGACGACGGGAGACCAGCAGGGGGTTACCCCCTATCGCAAATTACCGTATTGGCAGAGTGAGACAGCACCTCGGCTTTCGCGCTGCTCGCAACCACCGGGGAGGGTTTGTCGGGACCGTCCGGACTCTCAAAAGTCCTCCCTAACCGCCCAGGTGGAAGGCATATAAGGGCGCCCCAAAGCTGAGGTAATGCGGCAGTACACTGCCGCACCTTCAAGAGGATGACAATTAGGGCTGTCGTCGCTAATGGGAAGTGTAAATTGTAAGAGAGACATAACATAATCGCATTACTTCGACACACGGATGATGAAATCTCAGTACGATCCGCGGCACATGGTGAAACGTCTTAGCCGAATATTAGCCTAACTAGTTTTTCCGGTCGACGGCGACGCCCACAACAGTCACAGTGCCTTGTCAAGTTACAAGGGATCCCATTCGAGAACCGTAGACATGCCGAAACTCGCAATGTAACTTCGTGGAATTCGGGAGCTCTAGCACCACATGTCCGAAAAATCCATAGGCGTAGTAGCATTACCCAACCTGAGACTTCCAGCTGTGAGACGTGTGATGCTGTTCTTCAACCCTATGACTCGTTTTTACAGATACGCTCATTCGAGTTCGGGGCGGCAATTCACCATTGTGCGATGAGACAGACACGGTTTGGAGGCTTTGATGTGCCTCACCGCCCCTTCAAGTAGCAGCATAAGTGGGGGAGCACGGAAAACTCACGAGCGTGGCTCGGCCCTTATTGGGAACAGTAACAAGAAGCTTAAACAGATCCTGCACAGAATAGGTAAGGCTCTAACTCATTTCGCGCAGTCCGTGATACCGCTACGAACCCCAGGTTGATCCGGACCGGAGATCATTCACATTAACCACCGCTCGCAGAGTATCTGGAGTCGGCTTACCGGCCTACCTATTCTGCGGCGACATGGCTGCTCTGTCATTCCTACAACAGCAGGGGGCAGTGTTGTGTCAACGGATGGCCTTAAACGAAGTCTTCCATTATGCTAGACCCCGTGCGGGTTGTTTCACTGACCGTTGGCTCCCGCCCGCAAGAGACTGAGCTCCTGGTCTTCGCCGCACGAGTAGTTGGCACACATGCGGACTCACTTGCTAGTGCCCCTGCACGTTAGACTGCATACATATCATCTCAATGAACAGCACGATTCCGTCCCCGTTTCTCTTTCTTAGTTGTTGACTACGAATTAGTATAACAATTCCTAGCGGTAGTCGGCCGTGCCGGTGCCTGCGCCCGTTCCAAGAGCGGGCGCGGACTTTGGGCTTGGGCGTCCAGTGATATAAGGGGGGAAGGGAAACGCCTAGCGGATGTCCATCCAATGCCGAGATGGAATTAACTTTGTACGTGTGTCCCGTTGCGTTCCGAGTTGCTCGGCTTCGGACTGGAGCAGGGAACAATACTTGCACCCGGGTAGTTGGTTCACTATGGTCATAGCAGGAATGATTTAAGGGCCCTAGAGTGGCTCCGCAACAGAATATTTGCCTCGTCGCCGTTTCGGACGTGACCTCCGGGCTGGCGGTATGAAAAAGTAGTCACACTTAGCTTCTGCTGTTGAGCCACTGAGGTAGATGCTATTTTACACAGCCGTAGGAAGACACAGGAACACCCGGCGACTCTAAAAAAAGCGTAGGTGCACCTGTGGACTGGCTGTTAATCCTATCGGGATAGCTATTTGGGCAGCGCCTTAGATTCATTCAGATGGACGACTTGGTTCTCATGGCTACGCTGTTGCCGGGTTGGGAAGTTTGCAAGCCTTCCAGGAGAATCTGTATATGTTGTGCACTGGCGACAGCACTAAGGATTTGAACTCGAAAGCTTGTGTCCCTAAAAATTGCATTTCTGGTCTTTCTTAGCCATCTCCGAGTTAAAATCCTCACGGTTGAACGCACAGGCACCCCCATGGGGCCCACGACAGTATTAGGCTTCGAGAGTTTAACAGATGACGTGACCCACTAATTAGGTTAGCTTGGATCATTTGAGCTGAGCTTCCGTTGGCCGCCTAGGTCAACTGGTTGACCATTTAGTATGCAGTAGCCATCAATAGAGGCTTTAATCTAACCCTTACAGCGCGCATAACGGTACATGAGTGGTATTCTATGAACGAGCTATCAATGTAGGATCGTTATGGAGGCGG$

    Apart from this, I thought of below test case to develop algo : 
        pakpanmpanmpana$
*/