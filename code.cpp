#include <bits/stdc++.h>
#define INF 1000000009
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, char> ic;

map<string,int> dic;
map<int,string> rdic;
vector< vector< ic > > grf;
vector< vector<int> > dp;
vector<int> path;
set<char>alfa;
set<string> qf;
string q0, word;
bool ans_find;
int n_aresta;

bool valid_symbol(char c) {
    return ((c >= 'a' && c <= 'z')  || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')  ||  (c == '/')  || (c == '*')  || (c == '+')   || (c == '-') );  
} 

void build() {
    
    stringstream ss;
    string line, st;
    int count=0;
    
    getline(cin, line);
    ss << line;
    
    while(ss >> st) {
        dic[st] = count;
        rdic[count++] = st;
    }
        
    getline(cin, line);
    ss.clear();
    ss << line;
    
    for(int i=0; i<(int)line.size(); i++) {
        if(!valid_symbol(line[i])) line[i] = ' ';
    }

    while(ss >> st) {
        char aux = st[0];
        alfa.insert(aux);
    }
    
    getline(cin, line);
    ss.clear();

    for(int i=0; i<(int)line.size(); i++) 
        if(line[i] == '(' || line[i] == ')' || line[i] == ',') line[i] = ' ';

    ss << line;
    grf.resize(dic.size());
    
    string ori, dest;
    char simb;

    n_aresta=0;
    while(ss >> ori >> simb >> dest) {
        if(!alfa.count(simb) && simb != '$') continue;
        grf[dic[ori]].push_back({dic[dest], simb});
        n_aresta++;
    }
    
    cin >> q0;
    getline(cin, line);
    
    getline(cin, line);
    ss.clear();
    ss << line;

    while(ss >> st) {
        qf.insert(st);
    }
    
}

void print() {
    cout << (int)grf.size() << endl;

    for(auto s:dic) cout << s.first << endl;

    cout << n_aresta << endl;

    for(int i=0; i<(int)grf.size(); i++) {
        for(auto v: grf[i]) {
            cout << rdic[i] << " " << rdic[v.first] << " " << v.second <<  endl; 
        }
    }
    
    puts("");
    cout << q0 << endl;
    cout << qf.size() << endl;
    for(auto s:qf) cout << s << endl;

    if(!ans_find) {
        cout << "0\n";
        return;
    }

    cout << path.size() << endl;
    
    for(auto i:path) cout << rdic[i] << endl;
    
}

bool recognize() {
    getline(cin, word);
    getline(cin, word);

    dp.resize(dic.size());
    
    for(int i=0; i<dic.size(); i++)
        dp[i].assign(word.size()+1, INF);

    ans_find = false;

    for(int i=0; i<word.size(); i++)
        if(!alfa.count(word[i])) return ans_find;


    queue<ii> fila;
    map<ii, ii> pai;
    ii aux;

    fila.push(ii(dic[q0], -1));
    pai[ii(ii(dic[q0], -1))] = ii(-1, -1);

    while(fila.size()) {
        ii u = fila.front(); 
        fila.pop();

        if(qf.count(rdic[u.first])  && u.second == (int)word.size()-1) {
            ans_find = true;
            aux = ii(u.first, u.second);
            while(fila.size()) fila.pop();

            break;
        }

        for(auto v: grf[u.first]) {
            if(u.second < (int)word.size() && v.second == word[u.second+1] && (u.second == -1 || ( dp[u.first][u.second]+1 < dp[v.first][u.second+1]))) {
                dp[v.first][u.second+1] = (u.second == -1)?0:dp[u.first][u.second];
                pai[ii(v.first, u.second+1)] = u;
                fila.push(ii(v.first, u.second+1));
            }
            if(v.second == '$' && (u.second == -1 || dp[v.first][u.second] > dp[u.first][u.second])) {
                dp[v.first][u.second] = (u.second == -1)?-1:dp[u.first][u.second];
                pai[ii(v.first, u.second)] = u;
                fila.push(ii(v.first, u.second));
            }
        } 
    }

    while(aux != ii(-1,-1)) {
        path.push_back(aux.first);
        aux = pai[aux];
    }

    reverse(path.begin(), path.end());
    return ans_find;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    build();
    recognize();
    print();
}