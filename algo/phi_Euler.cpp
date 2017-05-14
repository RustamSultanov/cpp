#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int phi (int n) {
    int res = n;
    for (int i = 2; i*i <= n; i++ ) {
        if (n % i == 0) {
            while (n % i == 0) 
                n /= i; 
            res -= res/i; 
        }
    }
    if (n > 1)
		res -= res/n; 
	return res;
}


int main(int argc, char *argv[]) {
    cout << "gdfgf" << endl;
	
	cout << phi(1) << endl;
	cout << phi(2) << endl;
	cout << phi(3) << endl;
	cout << phi(4) << endl;
	cout << phi(11) << endl;
    // system("pause");

} 