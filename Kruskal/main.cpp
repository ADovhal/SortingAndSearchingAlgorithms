#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

struct DSU {
    std::vector<int> parent;    // pamięta rodzica elementu
    std::vector<int> size;      // pamięta rozmiar zbioru, po find() (path compression) ma znaczenie tylko dla top-rodzica (korzenia)
    int num_sets;               // szybki wgląd w liczbę zbiorów

    DSU(int n) {    // konstruktor, parametrem jest liczba 'zbiorów'
        parent.resize(n);   // tu pamiętamy indeks rodzica elementu o tym indeksie
        size.resize(n, 1);  // przygotuj miejsce dla n elementów
        num_sets = n;       // na początku każde element to osobny zbiór, jest n zbiorów

        for (int i = 0; i < n; i++) // na początku każdy element o indeksie i ma rodzica i, czyli samego siebie (zbiory są rozłączne)
            parent[i] = i;
    }

    int find(int x) {       // rekurencyjne wyszukanie top-rodzica elementu o indeksie x
        if (parent[x] == x) // jeśli rodzicem elementu jest on sam, to jest rodzic najwyższego poziomu, koniec poszukiwań
            return x;
        // a jeśli rodzicem elementu jest inny element..
        // optymalizacja Path Compression, żeby hierarchia była prawie płaska, wszyscy podwładni będą mieli tego samego rodzica
        // dzięki temu nie ma pionowych struktur i szybko można znaleźć rodzica
        // minus: od teraz rozmiar (wartość wektora size) ma sens tylko dla reprezentanta zbioru (top-rodzica zbioru)
        return parent[x] = find(parent[x]); // rekurencyjnie poszukaj top-rodzica i przypisz go jako rodzica tego elementu
    }

    bool unite(int a, int b) {  // połącz dwa zbiory, jeden zawiera element a, drugi zawiera element b
        int root_a = find(a);    // znajdź top-rodziców a i b
        int root_b = find(b);

        if (root_a == root_b)     // jeśli a i b mają wspólnego rodzica, to już są w jednym zbiorze
            return false;

        if (size[root_a] < size[root_b])  // optymalizacja Union by Size: mniejszy zbiór dołączamy do większego, jeśli trzeba to zamienimy teraz indeksy
            std::swap(root_a, root_b);

        parent[root_b] = root_a;  // od tej pory rodzic a będzie rodzicem rodzica b, zmieniamy hierarchię
        size[root_a] += size[root_b]; // top-rodzic a będzie większy o elementy zbioru b
        num_sets--; // zmniejszamy liczbę zbiorów po połączeniu

        return true;
    }

    friend std::ostream& operator<<(std::ostream& os, const DSU& dsu);
};

// struktura przechowująca miasto1, miasto2 i wagę (drogę)
struct Krawedz {
    int waga, u, v;
};

// funkcja porównania dla sort() - sortujemy po wadze od najmniejszej
bool porownaj(const Krawedz& a, const Krawedz& b) {
    return a.waga < b.waga;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int n, m;
        cin >> n >> m;

        // wczytujemy wszystkie drogi
        vector<Krawedz> krawedzie(m);
        for (int i = 0; i < m; i++)
            cin >> krawedzie[i].u >> krawedzie[i].v >> krawedzie[i].waga;

        // sortujemy drogi od najkrótszej do najdłuższej
        // algorytm Kruskala wymaga posortowanych krawędzi
        sort(krawedzie.begin(), krawedzie.end(), porownaj);

        // tworzymy DSU - na początku każde miasto w osobnym zbiorze
        DSU dsu(n);
        int maxWaga = 0;       // najdłuższa droga użyta w MST = odpowiedź
        int iloscKrawedzi = 0; // licznik krawędzi dodanych do MST

        // algorytm Kruskala - iterujemy po posortowanych krawędziach
        for (int i = 0; i < m; i++) {
            int u = krawedzie[i].u;
            int v = krawedzie[i].v;
            int w = krawedzie[i].waga;

            // próbujemy połączyc zbiory zawierajace u i v
            if (dsu.unite(u, v)) {
                // unite zwrócił true = miasta były w różnych zbiorach
                // = brak cyklu = bierzemy tę krawędź do MST

                maxWaga = max(maxWaga, w); // aktualizujemy maksymalną wagę
                iloscKrawedzi++;

                // MST jest gotowe gdy mamy n-1 krawędzi
                if (iloscKrawedzi == n - 1)
                    break;
            }
            // unite zwrócił false = miasta już w jednym zbiorze
            // = dodanie tej krawędzi utworzyłoby cykl = pomijamy
        }

        // odpowiedź: minimalny zasięg samochodu = najdłuzsza droga w MST
        cout << maxWaga << "\n";
    }

    return 0;
}
