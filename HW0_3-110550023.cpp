#include <iostream>

using namespace std;

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			int k;

			cin >> k;
			if (i == j) continue;
			if (k == 0) {
				cnt += b;
			}
			else if (k == 1) {
				cnt += a;
			}
			else {
				cnt += c;
			}
		}

		cout << cnt << " ";
	}

	return 0;
}