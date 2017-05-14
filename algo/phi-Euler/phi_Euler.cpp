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
    

    if (n > 1) {
        cout << res << " " << n << " " << res/n << endl;
		res -= res/n; 
        cout << "ans: " << res << endl << endl;
    }
	return res;
}

int main(int argc, char *argv[]) {
    cout << "gdfgf" << endl;
	
	for ( int i =1; i < 10; i++) {
        // if (phi(i) != phi0(i)) {
        //     cout << phi(i) << "!=" <<  phi0(i) << endl;
        // }
        cout << i << endl;
        phi(i);
        
    }
    // system("pause");

} 