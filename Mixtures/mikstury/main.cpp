#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dfs(int wierzcholek, vector<vector<int>>& graf, vector<int>& cena);

int main()
{
    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        int N, M;
        cin >> N >> M;

        vector<int> cena(N+1);
        for(int i = 1; i <= N; i++) cin >> cena[i];
        vector<vector<int>> graf(N+1);
        for(int i = 0; i < M; i++){
            int u, v;
            cin >> u >> v;
            graf[u].push_back(v);
        }

        int maxZysk = 0;

        for(int s = 1; s <= N; s++) maxZysk = max(maxZysk, dfs(s, graf, cena));

        cout << maxZysk << "\n";
    }

    return 0;
}

int dfs(int wierzcholek, vector<vector<int>>& graf, vector<int>& cena){
        int N = graf.size();
        int zysk = 0;
        vector<bool> odwiedzony(N,false);
        stack<int> stos;
        stos.push(wierzcholek);
        odwiedzony[wierzcholek] = true;
        while(!stos.empty()){
            int u = stos.top();
            stos.pop();
            zysk = max(zysk, cena[u] - cena[wierzcholek]);
            for(int v : graf[u]){
                if(!odwiedzony[v]){
                    odwiedzony[v] = true;
                    stos.push(v);
                }
            }
        }

        return zysk;
}
