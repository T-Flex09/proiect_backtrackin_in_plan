# Documentatie

## Cuprins
- [Descrierea temei](./Documentatie.md#descrierea-temei)
- [Limbajul de programare utilizat](./Documentatie.md#limbaj-de-programare-utilizat)
- [Cerintele sistemului](./Documentatie.md#cerintele-sistemului)
- [Descrierea programului](./Documentatie.md#descrierea-programului)
- [Concluzii](./Documentatie.md#concluzii)
- [Webografie](./Documentatie.md#webografie)

## Descrierea temei
Pe un teren de dimensiune dreptunghiulara, cu denivelari, se afla un sporitv care doreste sa se antreneze pentru un concurs de alpinism. Cunoscand altitudinea fiecarei portiuni de teren, pozitia initiala a alpinistului, si pozitia finala in care doreste sa ajunga, sa se determine un traseu pentru care suma diferentelor de altitudine intre pozitiile consecutive de pe traseu sa fie maxima. Alpinistul nu are voie coboare.

## Limbaj de programare utilizat
Limbajul de programare utilizat este C++, datorita eficientei si popularitatii acestuia.

## Cerintele sistemului
Pentru a rula programul, avem neovie de: 
 - 32KB RAM

## Descrierea programului

### Variabile

Incepem prin a declara variabilele (precum dimensiunile matricei, matricea propriu-zisa, vectorii de solutie, pozitia initiala, pozitia finala, vectorii de deplasare si alte variabile folosite pentru rezolvarea problemei) globale:

```cpp
int n, m, a[25][25], sol_i[1000], sol_j[1000], sol_len, s_max = 0;
int poz_init_I, poz_init_J;
int poz_fin_I, poz_fin_J;

int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
```

### Functii

Prima este o functie de citire; intai, citim dimensiunile matriceii(n, m), dupa aceea folosim o structura repetitiva pentru a parcurge elementele si citim matricea. Dupa, citim pozitia initiala si pozitia finala, folosite pentru rezolvarea problemei.

```cpp
void citire(){
    cout << "Introduceti dimensiunea matricei si matricea in sine: ";
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
            cin >> a[i][j];
    cout << "Introduceti pozitia initiala: ";
    cin >> poz_init_I >> poz_init_J;
    cout << "Introduceti pozitia finala: ";
    cin >> poz_fin_I >> poz_fin_J;
}
```

A doua functie din program este cea de tiparire. O folosim pentru a afisa pe ecran vectorul de solutii in format (x, y). Pentru a face asta, parcurgem elementele vectorului de solutii si le afisam. Afisam o paranteza, abscisa raspunusului, virgula, ordonata si o paranteza. Pentru a realiza insiruirea de solutii, afisam cate o virgula dupa fiecare solutie, cu exceptia ultimei solutii.

```c++
void tiparire(){
    for(int i = 1; i<=sol_len; i++) {
        cout<<"("<<sol_fin_i[i]<<", "<<sol_fin_j[i]<<")";
        if(i!=sol_len) cout<<", ";
    }
    cout<<"\n";
}
```

A treia functie este cea de backtracking. Aceasta functie executa rezolvarea propriu-zisa a problemei.
In momentul in care exploram fiecare celula, o marcam in 2 vectori temporari, pentru a tine minte intregul traseu parcurs pana atunci. Daca ajungem la destinatie, stocam solutia in vectorii finali. Altfel, continuam sa parcurgem toate cele 8 celule din jurul celei initiale, cu conditia ca acestea sa nu coboare in altitudine. Cu ajutorul parametrilui suma copiem in vectorul final solutia corecta doar daca este cea corecta (suma diferentelor de altitudine intre oricare doua celule parcurse trebuie sa fie maxima).
```c++
void back(int i, int j, int suma, int pas) {
    sol_i[pas] = i; sol_j[pas] = j;
    if(i==poz_fin_I && j==poz_fin_J) {
        if(suma > s_max) {
            s_max = suma;
            sol_len = pas;
            for(int x = 1; x<=sol_len; x++) {
                sol_fin_i[x] = sol_i[x];
                sol_fin_j[x] = sol_j[x];
            }
        }
    } else {
        for(int k = 0; k < 8; k++) {
            int vi = i + di[k];
            int vj = j + dj[k];
            if(0<=vi && vi<=n && 0<=vj && vj<=m) {
                if(a[vi][vj] >= a[i][j])
                    back(vi, vj, suma + a[vi][vj] - a[i][j], pas + 1);
            }
        }
    }
}
```

### Main

Ultima parte a programului este functia main. In aceasta parte a programului, apelam functiile de citire, backtracking si afisare.
```c++
int main() {
    citire();
    back(poz_init_I, poz_init_J);
    tiparire();
return 0;
}
```

### Program complet

```c++
#include <iostream>
using namespace std;

int n, m, a[25][25], sol_i[1000], sol_j[1000], sol_fin_i[1000], sol_fin_j[1000], sol_len, s_max = 0;
int poz_init_I, poz_init_J;
int poz_fin_I, poz_fin_J;

int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void citire(){
    cout << "Introduceti dimensiunea matricei si matricea in sine: ";
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
            cin >> a[i][j];
    cout << "Introduceti pozitia initiala: ";
    cin >> poz_init_I >> poz_init_J;
    cout << "Introduceti pozitia finala: ";
    cin >> poz_fin_I >> poz_fin_J;
}

void tiparire(){
    for(int i = 1; i<=sol_len; i++) {
        cout<<"("<<sol_fin_i[i]<<", "<<sol_fin_j[i]<<")";
        if(i!=sol_len) cout<<", ";
    }
    cout<<"\n";
}

void back(int i, int j, int suma, int pas) {
    sol_i[pas] = i; sol_j[pas] = j;
    if(i==poz_fin_I && j==poz_fin_J) {
        if(suma > s_max) {
            s_max = suma;
            sol_len = pas;
            for(int x = 1; x<=sol_len; x++) {
                sol_fin_i[x] = sol_i[x];
                sol_fin_j[x] = sol_j[x];
            }
        }
    } else {
        for(int k = 0; k < 8; k++) {
            int vi = i + di[k];
            int vj = j + dj[k];
            if(0<=vi && vi<=n && 0<=vj && vj<=m) {
                if(a[vi][vj] >= a[i][j])
                    back(vi, vj, suma + a[vi][vj] - a[i][j], pas + 1);
            }
        }
    }
}

int main() {
    citire();
    back(poz_init_I, poz_init_J, a[poz_init_I][poz_init_J], 1);
    tiparire();
    return 0;
}
```

## Concluzii

## Webografie
- [pbinfo](https://www.pbinfo.ro)
