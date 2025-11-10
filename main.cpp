#include <iostream>
using namespace std;

//INDEXAM DE LA 1 APROPO
int n, m, a[25][25], sol_i[1000], sol_j[1000], sol_len, s_max = 0;
int poz_init_I, poz_init_J;
int poz_fin_I, poz_fin_J;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

//EDI
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
} //in urma citirii, e umpluta matricea, de asemenea si n si m, pozitia initiala si finala la final

//VLADUTZ
void back(int i, int j, int suma) {
    sol_i[sol_len++] = i, sol_j[sol_len] = j;
    //ceva ceva caz in care ajunge la destinatie
    for(int k = 0; k < 4; k++) {
        int vi = i + di[k];
        int vj = j + dj[k];
        if(0<=vi && vi<=n && 0<=vj && vj<=m) {
            //ceva ceva conditie de parcurgere
        }
    }
    
    sol_len++;
} //parcurge matricea conform cerintei din poza

//LARGEANU
void tiparire(){
    for(int i = 1; i<=sol_len; i++) {
        cout<<"("<<sol_i[i]<<", "<<sol_j[i]<<")";
        if(i!=n) cout<<", ";
    }
    cout<<"\n";
} //tipareste vectorul de solutii

int main() {
    citire();
    back(poz_init_I, poz_init_J);
    tiparire();
return 0;
}
 
