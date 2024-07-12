#include <iostream>

using namespace std;

int factorialRecursive(int n) {
    if (n < 0) {
        throw invalid_argument("Factorial is not defined for negative numbers.");
    }
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorialRecursive(n - 1);
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    try {
        int result = factorialRecursive(num);
        cout << "Factorial of " << num << " is " << result << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    return 0;
}
