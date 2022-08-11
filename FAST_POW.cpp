#include <iostream>
using namespace std;

double fastPow(double x, int n) {
	if (n < 0) {
		return fastPow(1/x, -n);
	} else if (n == 0) {
		return 1;
	} else if (n == 1) {
		return x;
	} else if (n % 2 == 0) {
		return fastPow(x * x, n / 2);
	} else { // if (n % 2 != 0) {
		return x * fastPow(x * x, (n - 1) / 2);
	}
}

int main(int argc, char* argv[]) {
	double x;
	int n;
    
	cin >> x >> n;
	cout << x << "^" << n << " = " << fastPow(x,n) << "\n";
}