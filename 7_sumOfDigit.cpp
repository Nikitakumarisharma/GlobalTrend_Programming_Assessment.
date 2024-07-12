#include <iostream>

using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    n = abs(n); // To handle negative numbers

    while (n != 0) {
        sum += n % 10; // Add the last digit to sum
        n /= 10;       // Remove the last digit
    }

    return sum;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    int result = sumOfDigits(num);
    cout << "Sum of the digits of " << num << " is " << result << endl;

    return 0;
}
