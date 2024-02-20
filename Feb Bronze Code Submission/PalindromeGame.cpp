#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(int x) {
    string orig = to_string(x);
    string reversed = orig;
    reverse(reversed.begin(), reversed.end());
    return orig == reversed;
} 

int main() {
    int T = 0;
    int S = 0;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> S;

        if(S < 10 || isPalindrome(S)) {
            cout << "B" << endl;
        }
        else if(S % 10 == 0) {
            cout << "E" << endl;
        }
        else {
            cout << "B" << endl;
        }
    }
    
}