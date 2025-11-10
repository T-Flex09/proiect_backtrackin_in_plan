# Documentatie



Incepem prin a declara variabilele (precum dimensiunile matricei, matricea propriu-zisa, vectorii de solutie, pozitia initiala, pozitia finala, vectorii de deplasare si alte variabile folosite pentru rezolvarea problemei) globale:

```cpp
int n, m, a[25][25], sol_i[1000], sol_j[1000], sol_len, s_max = 0;
int poz_init_I, poz_init_J;
int poz_fin_I, poz_fin_J;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
```

Urmeaza functiile.
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

A doua functie din program este cea de tiparire. O folosim pentru a afisa pe ecran vectorul de solutii in format (x, y). Pentru a face asta, parcurgem elementele vectorului de solutii si le afisam.



Ultima parte a programului este functia main. In aceasta parte a programului, apelam functiile de citire, backtracking si afisare.
```c++
int main() {
    citire();
    back(poz_init_I, poz_init_J);
    tiparire();
return 0;
}
```
In final, tot programul arata in felul urmator:
```c++

```
