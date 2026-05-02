#include <iostream>
#include <vector>
using namespace std;

void wypisz(const vector<int>& a, int n){
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << "\n";
}

void przesiejWDol(vector<int>& a, int n, int i){
    while (true){
        int najwiekszy = i;
        int lewy  = 2*i + 1;
        int prawy = 2*i + 2;

        if (lewy < n && a[lewy]  > a[najwiekszy]) najwiekszy = lewy;
        if (prawy < n && a[prawy] > a[najwiekszy]) najwiekszy = prawy;

        if (najwiekszy == i) break;

        swap(a[i], a[najwiekszy]);
        i = najwiekszy;
    }
}

void przesiejWGore(vector<int>& a, int i){
    while(i>0){
        int rodzic = (i-1)/2;
        if(a[i] > a[rodzic]){
            swap(a[i], a[rodzic]);
            i = rodzic;
        } else break;
    }
}

void budujKopiec(vector<int>& a, int n){
    for(int i = 1; i < n; i++) przesiejWGore(a, i);
}

void sortowanieStogowe(vector<int> a){
    int n = a.size();

    budujKopiec(a, n);
    wypisz(a, n);

    for (int i = n - 1; i > 0; i--){
        swap(a[0], a[i]);
        przesiejWDol(a, i, 0);

        if (i == 1){
            wypisz(a, n);
        }
        else{
            wypisz(a, i);
        }
    }
}

int main()
{

    int T;
    cin >> T;
    for (int t = 0; t < T; t++){
        int k;
        cin >> k;
        vector<int> a(k);

        for (int i = 0; i < k; i++) cin >> a[i];

        sortowanieStogowe(a);

        if (t < T - 1) cout << "\n";
    }

    return 0;
}
