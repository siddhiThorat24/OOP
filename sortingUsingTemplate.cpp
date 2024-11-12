#include<iostream>
using namespace std;
/* Selection Sorting using Function Template */
template<class T>
void sorting(T a[], int n) {
    int i, j;
    cout << "Enter Array Elements: ";
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                T temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "Sorted Array is:\n";
    for(i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, c, ch;
    do {
        cout << "1. Sorting Integer Array\n2. Sorting Float Array\nEnter your choice: ";
        cin >> ch;
        
        if (ch == 1) {
            cout << "Enter array size: ";
            cin >> n;
            int a[20];
            sorting(a, n);
        } 
        else if (ch == 2) {
            cout << "Enter array size: ";
            cin >> n;
            float a[20];
            sorting(a, n);
        } 
        else {
            cout << "\nInvalid Choice\n";
        }
        
        cout << "\nEnter 1 to continue: ";
        cin >> c;
    } while(c == 1);

    return 0;
}
