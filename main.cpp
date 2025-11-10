#include <iostream>
#include <fstream>
using namespace std;

//INDEXAM DE LA 1 APROPO
int n, m, a[25][25], sol_I[1000], sol_j[1000], s_max = 0;
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
    
} //parcurge matricea conform cerintei din poza

//LARGEANU
void tiparire(){
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++)
            cout << a[i][j] << " ";
    cout << endl;
    }

} //tipareste vectorul de solutii

int main() {
    citire();
    back(poz_init_I, poz_init_J);
    tiparire();
return 0;
}
 
