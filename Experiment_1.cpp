#include <iostream>
using namespace std;

// Function to find maximum element
int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

// Function to find minimum element
int findMin(int arr[], int n) {
    int minVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal)
            minVal = arr[i];
    }
    return minVal;
}

// Function to find sum of elements
int findSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size!";
        return 0;
    }

    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int choice;
    char repeat;

    do {
        cout << "\n------ MENU ------\n";
        cout << "1. Find Maximum\n";
        cout << "2. Find Minimum\n";
        cout << "3. Display Second Element\n";
        cout << "4. Find Sum of Elements\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Maximum element is: " << findMax(arr, n);
                break;

            case 2:
                cout << "Minimum element is: " << findMin(arr, n);
                break;

            case 3:
                if (n >= 2)
                    cout << "Second element is: " << arr[1];
                else
                    cout << "Second element not available!";
                break;

            case 4:
                cout << "Sum of all elements is: " << findSum(arr, n);
                break;

            case 5:
                cout << "Exiting program...";
                return 0;

            default:
                cout << "Invalid choice!";
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
