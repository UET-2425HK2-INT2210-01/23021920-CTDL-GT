#include <iostream>
#include <string>

using namespace std;

int main()
{
    string n;
    getline(cin, n);
    int l = n.length();
    for(int i = l-1; i>=0; i--){
    cout << n[i];
}
    cout << endl;
    return 0;
}