#include <iostream>
#include <m>

using namespace std;

void fillQ(map<char, int> aplphabeth, int pos, string str) {
    char c = 'A';
    for (int i = pos; i < pos + 26; ++i) {
        
    }
}

int main(int argc, char *argv[]) {
    string s;
    cin >> s;
    int length = s.length();
    // cout << s;

    if (length < 26) {
        cout << "-1" << endl;
        return 0;
    }

    map<char, int> alphabeth;

    int L = 0;
    int R = -1;
    int qcnt = 0;
    bool f = false;


    while (R + 1 < 26) {
        ++R;
        if (s[R] == '?') {
            ++qcnt;
        } else {
            ++alphabeth[s[R]];
        }
    }

    // if
    
    if (qcnt + alphabeth.size() == 26) {
        f = true;
        fillQ(alphabeth, L, s);
    }

    while ( !ok && R + 1 < length ) {
        
    }
    


}