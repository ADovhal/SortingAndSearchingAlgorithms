
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main2(){
    int T;
    cin >> T;

    for (int t = 0; t < T; t++){
        int N, M;
        cin >> N >> M;

        vector<int> cena(N + 1);
        for (int i = 1; i <= N; i++) cin >> cena[i];

        vector<vector<int>> graf(N + 1);
        vector<int> inDegree(N + 1, 0); // входящие рёбра

        for (int i = 0; i < M; i++){
            int u, v;
            cin >> u >> v;
            graf[u].push_back(v);
            inDegree[v]++;  // вершина v получила входящее ребро
        }

        // Алгоритм Кана
        queue<int> kolejka;
        vector<int> PT; // порядок топологический

        // Все вершины с 0 входящими рёбрами → в очередь
        for(int i = 1; i <= N; i++) if (inDegree[i] == 0) kolejka.push(i);

        while(!kolejka.empty()){
            int u = kolejka.front();
            kolejka.pop();

            PT.push_back(u); // добавляем в топологический порядок

            for (int v : graf[u]){
                inDegree[v]--;
                if (inDegree[v] == 0) kolejka.push(v);
            }
        }

        // Выводим топологический порядок
        if(PT.size() == N){
            cout << "Porzadek topologiczny: ";
            for (int v : PT)
                cout << v << " ";
            cout << "\n";
        } else {
            cout << "Graf zawiera cykl!\n";
        }

        // Propagacja minCena i obliczanie maxZysk
        // minCena[v] = minimalna cena na dowolnej sciezce konczacej sie w v
        vector<int> minCena(N + 1);
        for(int i = 1; i <= N; i++) minCena[i] = cena[i]; // na poczatek kazda wierzcholek zna tylko swoja cene

        int maxZysk = 0;

        // Przetwarzamy wierzcholki w porzadku topologicznym
        for(int u : PT){
            for(int v : graf[u]){
                // czy mozemy zarobic sprzedajac v po dotarciu z u?
                int zysk = cena[v] - minCena[u];
                maxZysk = max(maxZysk, zysk);

                // propagujemy minimalna cene do sasiadow
                minCena[v] = min(minCena[v], minCena[u]);
            }
        }

        cout << maxZysk << "\n";
    }

    return 0;
}
