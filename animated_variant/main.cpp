#include <iostream>
#include "color.h"
#include <windows.h>
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
            if(1<=vi && vi<=n && 1<=vj && vj<=m) {
                if(a[vi][vj] >= a[i][j])
                    back(vi, vj, suma + a[vi][vj] - a[i][j], pas + 1);
            }
        }
    }
}

void animation() { 
    cout<<'\n';
    for(int i = 1; i<=sol_len; i++) { //luam fiecare pas din solutie
        for(int line = 1; line<=n; line++) { // parcurgem matricea
            for (int col=1; col<=m; col++) {
                if (sol_fin_i[i]==line && sol_fin_j[i]==col)
                    cout<<rosu<<a[line][col]<<reset<<' '; // afisam cu rosu elementul curent din pas
                else cout<<a[line][col]<<' '; //afisam in mod normal celelalte elemente
            }
            cout<<'\n';
        }
        Sleep(2000); //asteptam 2 secunde
        if (i<sol_len)
            for (int k=1;k<=n;k++)
                cout<<cursor_sus<<sterge; //mergem cu cursorul sus si stergem matricea
    }
}
int main() {
    citire();
    back(poz_init_I, poz_init_J, a[poz_init_I][poz_init_J], 1);
    tiparire();
    animation(); // apelam functia animation
    cin.ignore(); //cin.ignore() ignora orice input anterior pentru a nu fi declansat cin.get(), ceea ce ar face ca programul sa se termine prematur.
    cin.get(); //asteptam input de la user
    return 0;
}
/*  Numerele din problema
    3 4
    16 2 12 20
    4 5 9 30
    8 13 16 19
    1 2
    3 4
*/
