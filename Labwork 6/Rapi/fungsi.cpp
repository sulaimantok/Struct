#include "fungsi.h"


fungsi::~Stack(){

}

void fungsi::inisialisasi() {
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

void fungsi::pushToPath(petak input) {
	path.isi[path.batas] = input;
	path.batas++;
}

void fungsi::pushToForbidden(petak input) {
	path.isi[forbidden.batas] = input;
	forbidden.batas++;
}

void fungsi::pushToBranch(petak input) {
	branch.isi[path.batas] = input;
	branch.batas++;
}

petak fungsi::popPath() {
	return path.isi[path.batas - 1];
	path.batas--;
}

petak fungsi::popBranch() {
	return branch.isi[branch.batas - 1];
	branch.batas--;
}

void fungsi::enqueue(petak input, list queue) {
	queue.isi[queue.batas] = input;
	queue.batas++;
}

petak fungsi::dequeue(list queue) {
	return queue.isi[0];
	for (int i = 0; i < queue.batas; i++)
		queue.isi[i] = queue.isi[i + 1];
	queue.batas--;
}
petak fungsi::top(list input) {
	return input.isi[input.batas - 1];
}

void fungsi::move(petak input, int direction){
	if (direction == 2) {
		pushToPath(maps[input.y][input.x+1]);
		if (cekBelokan(top(path)) == 1)
			pushToBranch(top(path));
	}

	else if (direction == 3) {
		pushToPath(maps[input.y + 1][input.x]);
		if (cekBelokan(top(path)) == 1)
			pushToBranch(top(path));
	}
}

void fungsi::back() {
	while (top(path).angka != top(branch).angka && top(path).huruf != top(branch).huruf) {
		pushToForbidden(popPath());
	}
	popBranch();
}

int fungsi::cekrules(petak input, list forbidden) {
	int bawah = 0, kanan = 0, output = 0;
	if (maps[input.y][input.x].kanan == 1) {
		petak temp = maps[input.y][input.x + 1];
		if (temp.status != 0 && findInForbidden(temp) == 0)
			kanan = 1;
		else
			maps[input.y][input.x].kanan = 0;
	}
	if (maps[input.y][input.x].bawah == 1) {
		petak temp = maps[input.y+1][input.x];
		if (temp.status != 0 && findInForbidden(temp) == 0)
			bawah = 1;
		else
			maps[input.y][input.x].bawah = 0;
	}

	if (kanan == 1)
		output = 2;
	else if (bawah == 1)
		output = 3;

	return output;
}

int fungsi::findInForbidden(petak input) {
	int status = 0;
	if (forbidden.batas == 0)
		return status;
	else {
		for (int i = 0; i < forbidden.batas; i++)
			if (input.huruf == forbidden.isi[i].huruf&&input.angka == forbidden.isi[i].angka)
				status = 1;
	}
	return status;
}
int fungsi::cekBelokan(petak input) {
	int count = 0;
	if (input.kanan == 1)
		count++;
	if (input.bawah == 1)
		count++;

	if (count == 2)
		return 1;
	else
		return 0;
}

void fungsi::printList(list print) {

	cout << "Jalan yang harus dilewati adalah	:" << endl;
	for (int i = 0; i < print.batas; i++) {
		cout << print.isi[i].huruf << print.isi[i].angka << " " << "-";
		cout<<endl;
	}
}