#include <iostream>
#include <cstring>
using namespace std;

const int MAX_DIGITS = 20; // maximum length of integers

// function to reverse the order of the elements in the array
void reverseArray(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

// function to add two large integers represented as arrays of digits
void addArrays(int a[], int b[], int size, int sum[]) {
    int carry = 0;
    for (int i = 0; i < size; i++) {
        int digitSum = a[i] + b[i] + carry;
        sum[i] = digitSum % 10;
        carry = digitSum / 10;
    }
    if (carry > 0) {
        cout << "EROOR!" << endl;
    }
}

int main() {
    while (1) {
        // read in two positive integers
        char input1[MAX_DIGITS + 1], input2[MAX_DIGITS + 1];
        cout << "Enter the first integer (up to " << MAX_DIGITS << " digits): ";
        cin.getline(input1, MAX_DIGITS + 1);
        cout << "Enter the second integer (up to " << MAX_DIGITS << " digits): ";
        cin.getline(input2, MAX_DIGITS + 1);

        // convert the input strings to arrays of digits (in reverse order)
        int len1 = strlen(input1);
        int len2 = strlen(input2);
        int a[MAX_DIGITS] = {0}, b[MAX_DIGITS] = {0};
        for (int i = 0; i < len1; i++) {
            a[i] = input1[len1 - 1 - i] - '0';
        }
        for (int i = 0; i < len2; i++) {
            b[i] = input2[len2 - 1 - i] - '0';
        }

        // add the two arrays and store the result in another array
        int sum[MAX_DIGITS] = {0};
        int size = max(len1, len2);
        addArrays(a, b, size, sum);

        // reverse the order of the elements in the sum array
        reverseArray(sum, size);

        // output the result
        cout << "Result: ";
        for (int i = 0; i < size; i++) {
            cout << sum[i];
        }
        cout << endl;

        // ask the user if they want to continue
        char response;
        cout << "Do you want to perform another addition? (y/n): ";
        cin >> response;
        if (response != 'y' && response != 'Y') {
            break;
        }
        cin.ignore(); // ignore the newline character in the input buffer
    }

    return 0;
}
