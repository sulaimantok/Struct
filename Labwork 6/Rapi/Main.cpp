#include "stdio.h"
#include "iostream"
#include "fungsi.h"

using namespace std;

int main(){
	inisialisasi();

	int xtom = 0;
	int ytom = 0;

	int xmom = 5;
	int ymom = 5;

	pushToPath(maps[0][0]);
	//int dir = cekrules(top(path), forbidden);
	////int dir = findInForbidden(top(path));
	//cout << dir;
	//move(top(path), dir, maps);

	//cout << top(path).x;
	//cout << top(path).y;
	while (xtom != 3) {
		int dir = cekrules(top(path), forbidden);
		if (dir != 0) {
			move(top(path), dir);
		}
		/*else {
			back();
		}*/
		xtom = top(path).x;
		ytom = top(path).y;
	}
	printList(path);
}