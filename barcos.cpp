#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

void juego(int m[9][9][1]);
bool acabar(int m[9][9][1], int z);
int eval(int m[9][9][1], int a, int b, int z);
bool comp(int m[9][9][1], int a, int b, int z, int cons);
bool unoadiez(int a);
bool comp4(int i, int j, int i1, int j1, int a);
int cambiar(int& a);
void ver(int m[9][9][1]);
int main() {
	int mat[9][9][1], i, j, i1, j1, cnt2;
	for (int z = 0; z <= 1; z++) {
		cnt2 = 1;
		cout << "JUGADOR " << z + 1 << "!!!!!!!!!!!!!!!";
		for (int i = 0; i < 10; i++) { //Inicializar la matriz a 0
			for (int j = 0; j < 10; j++) {
				mat[i][j][z] = 0;
			}
		}
		do { //Poner el barco de 4
			do {
				cout << "\nIntroduce la 1 coordenada del barco de 4: "; cin >> i; cin >> j;
				cout << "\nIntroduce la 2 coordenada del barco de 4: "; cin >> i1; cin >> j1;
			} while (unoadiez(i) != true || unoadiez(j) != true || unoadiez(i1) != true || unoadiez(j1) != true);
		} while (comp4(i, j, i1, j1, 3) != true);
		if (i == i1) {
			if (j < j1) {
				for (int k = j - 1; k < j1; k++) {
					mat[i - 1][k][z] = cnt2;
				}
			}
			else {
				for (int k = j - 1; k > j1; k--) {
					mat[i - 1][k][z] = cnt2;
				}
			}
		}
		else {
			if (i < i1) {
				for (int k = i - 1; k < i1; k++) {
					mat[k][j - 1][z] = cnt2;
				}
			}
			else {
				for (int k = i - 1; k > i1; k--) {
					mat[k][j - 1][z] = cnt2;
				}
			}
		}
		cnt2++;
		for (int cnt = 1; cnt <= 2; cnt++) {
			do { //Poner los barcos de 3
				do {
					cout << "\nIntroduce la primera coordenada del " << cnt << " barco de 3: "; cin >> i; cin >> j;
					cout << "\nIntroduce la segunda coordenada del " << cnt << " barco de 3: "; cin >> i1; cin >> j1;
				} while (unoadiez(i) != true || unoadiez(j) != true || unoadiez(i1) != true || unoadiez(j1) != true);
			} while (comp4(i, j, i1, j1, 2) != true);
			if (i == i1) {
				if (j < j1) {
					for (int k = j - 1; k < j1; k++) {
						mat[i - 1][k][z] = cnt2;
					}
				}
				else {
					for (int k = j - 1; k > j1; k--) {
						mat[i - 1][k][z] = cnt2;
					}
				}
			}
			else {
				if (i < i1) {
					for (int k = i - 1; k < i1; k++) {
						mat[k][j - 1][z] = cnt2;
					}
				}
				else {
					for (int k = i - 1; k > i1; k--) {
						mat[k][j - 1][z] = cnt2;
					}
				}
			}
			cnt2++;
		}
		for (int cnt1 = 1; cnt1 <= 3; cnt1++) {
			do { //Poner los barcos de 2
				do {
					cout << "\nIntroduce la primera coordenada del " << cnt1 << " barco de 2: "; cin >> i; cin >> j;
					cout << "\nIntroduce la segunda coordenada del " << cnt1 << " barco de 2: "; cin >> i1; cin >> j1;
				} while (unoadiez(i) != true || unoadiez(j) != true || unoadiez(i1) != true || unoadiez(j1) != true);
			} while (comp4(i, j, i1, j1, 1) != true);
			if (i == i1) {
				if (j < j1) {
					for (int k = j - 1; k < j1; k++) {
						mat[i - 1][k][z] = cnt2;
					}
				}
				else {
					for (int k = j - 1; k > j1; k--) {
						mat[i - 1][k][z] = cnt2;
					}
				}
			}
			else {
				if (i < i1) {
					for (int k = i - 1; k < i1; k++) {
						mat[k][j - 1][z] = cnt2;
					}
				}
				else {
					for (int k = i - 1; k > i1; k--) {
						mat[k][j - 1][z] = cnt2;
					}
				}
			}
			cnt2++;
		}
		for (int cnt1 = 1; cnt1 <= 4; cnt1++) {   //Poner los barcos de 1
			do {
				cout << "\nIntroduce la posicion del " << cnt1 << " barco de 1: "; cin >> i; cin >> j;
			} while (unoadiez(i) != true || unoadiez(j) != true);
			mat[i - 1][j - 1][z] = cnt2;
			cnt2++;
		}
	}
	ver(mat);
	juego(mat);
	return 0;
}

void juego(int m[9][9][1]) {
	int i, j = 0, z = 1;
	do {
		cout << "\nIntroduce las coordenadas de los barcos del jugador " << z + 1 << ": "; cin >> i; cin >> j;   //Coordenadas a evaluar
		m[i - 1][j - 1][z] = eval(m, i - 1, j - 1, z);   //Evaluaci�n de coordenadas, si era una casilla de barco sin tocar, devuelve un 10	 
		z = cambiar(z);
	} while (acabar(m, z) != true);   //Acaba cuando acabar sea true (sea todo 0 o 11 en alguna de las 2 matrices)
	cout << "\nGana el jugador " << z << "!!!!!!!!!!!!!!!";
	cout << "\nTermina..." << endl;
}

bool acabar(int m[9][9][1], int z) {
	if (z == 0) {
		z = 1;
	}
	else {
		z = 0;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (m[i][j][z] == 1 || m[i][j][z] == 2 || m[i][j][z] == 3 || m[i][j][z] == 4 || m[i][j][z] == 5 || m[i][j][z] == 6 || m[i][j][z] == 7 || m[i][j][z] == 8 || m[i][j][z] == 9 || m[i][j][z] == 10) {
				return false;    //Al encontrar un espacio no tocado de un barco se acaba la rutina y se env�a false
			}
		}
	}
	return true;
}

int cambiar(int& a) {
	if (a == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

int eval(int m[9][9][1], int a, int b, int z) {
	int res = 0;
	if (m[a][b][z] == 0) {
		cout << "\nAgua";
	}
	else if (m[a][b][z] == 1 || m[a][b][z] == 2 || m[a][b][z] == 3 || m[a][b][z] == 4 || m[a][b][z] == 5 || m[a][b][z] == 6 || m[a][b][z] == 7 || m[a][b][z] == 8 || m[a][b][z] == 9 || m[a][b][z] == 10) {
		res = m[a][b][z];
		if (comp(m, a, b, z, m[a][b][z]) == true) {
			if (res == 1) {
				cout << "\nHundido el barco de 4";      //Se supone que cuando alguna de las comprobaciones del if da true el barco es tocado pero no hundido
			}
			else if (res == 2 || res == 3) {
				cout << "\nHundido un barco de 3";
			}
			else if (res >=4 || res<= 6) {
				cout << "\nHundido un barco de 2";
			}
			else if (res >= 7 || res <= 10) {
				cout << "\nHundido un barco de 1";
			}
			return 11;
		}
		else {
			cout << "\nTocado";
			return 11;
		}
	}
	else if (m[a][b][z] == 11) {
		cout << "\nYa estaba dicho";
	}
	return m[a][b][z];
}

bool comp(int m[9][9][1], int a, int b, int z, int cons) {
	m[a][b][z] = 11;
	for (int i = 0; i < 10; i++) {      //Si encuentra alg�n valor que concuerde con su barco env�a falso (tocado)
		for (int j = 0; j < 10; j++) {
			if (m[i][j][z] == cons) {
				return false;
			}
		}
	}
	return true;
} 

bool unoadiez(int a) {
	if (a > 0 && a <= 10) {
		return true;
	}
	cout << "\nNo has introducido unas coordenadas v�lidas";
	return false;
}

bool comp4(int i, int j, int i1, int j1, int a) {
	if (i == i1 && (j1 - j == a || j - j1 == a)) {
		return true;
	}
	if (j == j1 && (i1 - i == a || i - i1 == a)) {
		return true;
	}
	cout << "\nNo has introducido unas coordenadas v�lidas";
	return false;
}

void ver(int m[9][9][1]) {
	for (int z = 0; z < 2; z++) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << m[i][j][z] << "      ";
			}
			cout << endl;
		}
		cout << endl;
		cout << endl;
		cout << endl;
	}
}