#include <bits/stdc++.h>
using namespace std;

int aridade(char c) {
	if(c == '*') return 1;
	if(c == '.') return 2;
	if(c == '+') return 2;
	return 0;
}

int prioridade(char c) {
    if(c == '(') return 0;
    if(c == '+') return 1;
    if(c == '.') return 2;
    if(c == '*') return 3;
    return -1;
}

bool operador(char c) {
    return (c == '+' || c == '.' || c == '*' || c == '(' || c == ')');
}

typedef struct vertex{
	int l, r;
	char c;
}vertex;

typedef pair<int,char> ii;

vertex *tree;

string s;
map<int, set<ii> > grf;
int V, n;

int build_tree(int k) {
	if(k >= n) return -1;

	int node = V;

	int c = tree[node].c = s[k];
	tree[node].l = tree[node].r = -1;

	if(aridade(c) == 0) return node;

	tree[node].l = build_tree(++V);

	if(aridade(c) == 2) tree[node].r = build_tree(++V);

	return node;
}

void print_tree(){
	for(int i=0; i<n; i++) {
		printf("%c = (", tree[i].c);

		if(tree[i].l != -1) printf("%c", tree[tree[i].l].c);
		if(tree[i].r != -1) printf(",%c", tree[tree[i].r].c);
		puts(")");
	}
}

pair<int,int> build_automato(int u) {
	if(aridade(tree[u].c) == 0) {
		int sz  = grf.size();

		grf[sz].insert({sz+1, tree[u].c});
		grf[sz+1].insert({sz+1, ' '});

		return {sz, sz+1};
	}

	if(tree[u].c == '.') {
		ii a = build_automato(tree[u].l);
		ii b = build_automato(tree[u].r);

		int sz  = grf.size();

		grf[sz].insert({a.first, '$'});
		grf[a.second].insert({sz+1, '$'});
		grf[sz+1].insert({b.first, '$'});
		grf[b.second].insert({sz+2, '$'});
		grf[sz+2].insert({sz+2, ' '});

		return {sz, sz+2};
	}

	if(tree[u].c == '*') {
		ii a = build_automato(tree[u].l);

		int sz  = grf.size();

		grf[sz].insert({a.first, '$'});
		grf[a.second].insert({sz+1, '$'});
		grf[sz+1].insert({a.first, '$'});
		grf[sz].insert({sz+1, '$'});

		return {sz, sz+1};
	}

	if(tree[u].c == '+') {
		ii a = build_automato(tree[u].l);
		ii b = build_automato(tree[u].r);

		int sz  = grf.size();

		grf[sz].insert({sz+1, '$'});
		grf[sz+1].insert({a.first, '$'});
		grf[a.second].insert({sz+2, '$'});
		grf[sz+2].insert({sz+3, '$'});
		grf[sz].insert({sz+4, '$'});
		grf[sz+4].insert({b.first, '$'});
		grf[b.second].insert({sz+5, '$'});
		grf[sz+5].insert({sz+3, '$'});
		grf[sz+3].insert({sz+3, ' '});

		return {sz, sz+3};
	}

	return {-1,-1};
}

void infix_form() {
	string aux;
	stack<char> pilha;
	reverse(s.begin(), s.end());

	for(int i=0; i<n; i++) {
		if(s[i] == '(') s[i] = ')';
		else if(s[i] == ')') s[i] = '(';
	}

	for(int i=0; i<n; i++) {
            if(!operador(s[i])) aux.push_back(s[i]);
            else {
                if(s[i] == '(') pilha.push(s[i]);
                else if(s[i] == ')') {
                    while(pilha.top() != '(') {
                    		aux.push_back(pilha.top());
                            pilha.pop();
                    }
                    pilha.pop();
                }
                else {
                    if(!pilha.size() || (prioridade(pilha.top()) < prioridade(s[i]))) pilha.push(s[i]);
                    else {
                        while(pilha.size() && prioridade(pilha.top()) > prioridade(s[i])) {
                            aux.push_back(pilha.top());
                            pilha.pop();
                        }
                        pilha.push(s[i]);
                    }
                }
            }
        }
        while(pilha.size()) {
         	aux.push_back(pilha.top());
            pilha.pop();
        }
        s = aux;
        reverse(s.begin(), s.end());
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in_regular.txt", "r", stdin);	
		freopen("in.txt", "w", stdout);
	#endif
	
	getline(cin, s);
	n = s.size();
	infix_form();
	V = 0;
	n = s.size();
	tree = (vertex*) malloc(sizeof(vertex) * n);

	build_tree(0);
    pair<int,int> a = build_automato(0);

    for(int i=0; i<grf.size(); i++)
    	cout << " q" << i;

    puts("");

    for(int i=0; i<n; i++)
    	if(tree[i].l == -1 && tree[i].r == -1) cout << " " << tree[i].c;

    puts("");

    for(auto u:grf) {
    	for(auto v:u.second) {
    		if(v.second != ' ') printf(" (q%d, %c, q%d)", u.first, v.second, v.first);
    	}
    }

    puts("");

    cout << " q" << a.first << endl;
    cout << " q" << a.second << endl << endl;

    getline(cin, s);
    cout << s << endl;

    free(tree);
}
