#include<iostream>
using namespace std;

int rev(int x) {
    long rev=0;
    int rem;
    while(x!=0) {
        rem = x%10;
        rev = 10*rev + rem;
        x /= 10;
        if(rev > INT_MAX|| rev < INT_MIN) {
                return 0;
        }
    }

    return (int)rev;
}

int main() {
    int n;
    cin>>n;
    cout<<rev(n);
}