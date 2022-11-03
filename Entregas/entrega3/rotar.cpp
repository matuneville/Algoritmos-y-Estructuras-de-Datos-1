#include <iostream>
#include <string>

using namespace std;

string rotar(string s, int j){
    string res;
    while (j - int (s.length()) >= 0){      // sin el int fallaba porque s.length() es unsigned
        j -= s.length();
    }
    for (int i = s.length() - j; i < s.length(); ++i) {
        res += s[i];
    }
    for (int i = 0; i < s.length() - j; ++i) {
        res += s[i];
    }
    return res;
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s;
    int j;
    cin >> s >> j;
    
    string res = rotar(s, j);
    cout << res;
    return 0;
}
