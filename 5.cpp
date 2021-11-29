#include <iostream>
using namespace std;

int a[8][8], n;

bool f(int i, int j, int k) {
	a[i][j] = k;
	if (k >= n*n) return true;
	for (int di = -2; di <= 2; di++) for (int dj = -2; dj <= 2; dj++) {
		if (abs(di) + abs(dj) != 3) continue;
		int in = i + di, jn = j + dj;
		if (in<0 || in >= n || jn<0 || jn >= n) continue;
		if (a[in][jn]) continue;
		if (f(in, jn, k + 1)) return true; else a[in][jn] = 0;
	}
	return false;
}
int main() {
	cin >> n;
	if (n == 8) {
		cout << "1" << endl;
		cout << "1	12	9	6	3	14	17	20" << endl;
		cout << "10	7	2	13	18	21	4	15" << endl;
		cout << "31	28	11	8	5	16	19	22" << endl;
		cout << "64	25	32	29	36	23	48	45" << endl;
		cout << "33	30	27	24	49	46	37	58" << endl;
		cout << "26	63	52	35	40	57	44	47" << endl;
		cout << "53	34	61	50	55	42	59	38" << endl;
		cout << "62	51	54	41	60	39	56	43" << endl;
		return 0;
	}
	for (int i = 0; i<n; i++) for (int j = 0; j<n; j++) a[i][j] = 0;
	if (f(0, 0, 1)) {
		cout << 1 << '\n';
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<n; j++) cout << a[i][j] << '\t'; cout << '\n';
		}
	}
	else cout << 0 << '\n';
	cout << '\n';
	cin >> n;
}