#include "stdio.h"
#include "iostream"

using namespace std;

void inisialisasi() {
	for (int i = 0; i < 6; i++) {
		maps[0][i].huruf = "A";
		maps[1][i].huruf = "B";
		maps[2][i].huruf = "C";
		maps[3][i].huruf = "D";
		maps[4][i].huruf = "E";
		maps[5][i].huruf = "F";

		maps[i][0].angka = "1";
		maps[i][1].angka = "2";
		maps[i][2].angka = "3";
		maps[i][3].angka = "4";
		maps[i][4].angka = "5";
		maps[i][5].angka = "6";
	}
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++) {
			maps[i][j].x = j;
			maps[i][j].y = i;
		}


	//baris 1
	maps[0][0].bawah = 1;
	maps[0][1].status = 0;
	maps[0][2].atas = 1;
	maps[0][2].kiri = 1;
	maps[0][3].atas = 1;
	maps[0][3].kiri = 1;
	maps[0][4].bawah = 1;
	maps[0][5].status = 0;

	//baris 2
	maps[1][0].bawah = 1;
	maps[1][0].kanan = 1;
	maps[1][1].bawah = 1;
	maps[1][1].kanan = 1;
	maps[1][2].bawah = 1;
	maps[1][2].kanan = 1;
	maps[1][3].atas = 1;
	maps[1][3].kiri = 1;
	maps[1][4].bawah = 1;
	maps[1][4].kanan = 1;
	maps[1][5].bawah = 1;

	//baris 3
	maps[2][0].bawah = 1;
	maps[2][1].status = 0;
	maps[2][2].bawah = 1;
	maps[2][3].bawah = 1;
	maps[2][3].kanan = 1;
	maps[2][4].atas = 1;
	maps[2][4].kiri = 1;
	maps[2][5].status = 0;

	//baris 4
	maps[3][0].bawah = 1;
	maps[3][0].kiri = 1;
	maps[3][1].bawah = 1;
	maps[3][1].kiri = 1;
	maps[3][2].bawah = 1;
	maps[3][2].kiri = 1;
	maps[3][3].bawah = 1;
	maps[3][3].kanan = 1;
	maps[3][4].bawah = 1;
	maps[3][4].kanan = 1;
	maps[3][5].bawah = 1;


	//baris 5
	maps[4][0].bawah = 1;
	maps[4][1].status = 0;
	maps[4][2].bawah = 1;
	maps[4][2].kanan = 1;
	maps[4][3].status = 0;
	maps[4][4].status = 0;
	maps[4][5].kiri = 1;
	maps[4][5].bawah = 1;

	//baris 6
	maps[5][0].atas = 1;
	maps[5][0].kiri = 1;
	maps[5][1].bawah = 1;
	maps[5][1].kiri = 1;
	maps[5][2].bawah = 1;
	maps[5][2].kanan = 1;
	maps[5][3].bawah = 1;
	maps[5][3].kanan = 1;
	maps[5][4].bawah = 1;
	maps[5][4].kanan = 1;
	maps[5][5].bawah = 1;
};

int main(){
	int xtom = 0;
	int ytom = 0;

	int xmom = 5;
	int ymom = 5;

}