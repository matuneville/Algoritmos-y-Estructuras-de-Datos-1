#include <iostream>
#include <string>

using namespace std;

bool subsecuencia(string s1, string s2) {
    int cont = 0;
    int j = 0;
    for (int i = 0; i < s1.length(); i++){
        while (j < s2.length() && not s2.empty()) {
            if (s2[j] == s1[i]) {
                cont++;
                j++;
                break;
            }
            j++;
        }
    }
    return (cont == s1.length() || s1.empty());
}

int main()
{
    /* No hace falta modificar el main */
    // Leo la entrada
    string s, t;
    cin >> s >> t;
    
    bool res = subsecuencia(s, t);
    cout << (res ? "true" : "false");
    return 0;
}

