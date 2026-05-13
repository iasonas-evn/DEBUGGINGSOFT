/** \file bugExample.cpp
 *  \brief  shows array operations with VAT calculation.
 *  \details   Demonstrates filling, multiplying, displaying, summing, averaging,
 *             and reverting integer arraysvia a menu. Prices are
 *             random and sums are stored both with and without VAT.
 *  \author    Harald Gjermundrod
 *  \version   0.3
 *  \date      20/10/2025
 *  \copyright University of Nicosia.
 */

 
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
using namespace std;
const double VAT = 0.21;

int printMenu();
void fillInArray(int[], const int);
void multArrays(const int[], const int[], int[][2], const int);
void displayArray(const int[][2], const int);
int sumOddArray(const int[][2], const int);
bool isAllPositive(const int[][2], const int);
bool avgOddArray(const int[][2], const int, int&);
void revertNumbers(int[][2], const int);

/**
 * <code>main</code> is the main function of this program.
 * <BR>
 * @return Returns 0 if success, any other value otherwise.
 */
int main() {
    int choice;
    const int SIZE = 10;

   
    srand(time(NULL));
    int price[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        price[i] = 10 + rand() % 41;
    }
    int quantity[SIZE], total[SIZE][2];

    // Interactive menu
    do {
        choice = printMenu();

        switch (choice) {
            // Enter quantity
        case 1:
            fillInArray(quantity, SIZE);
            cout << endl;
            break;
            // Calculate total
        case 2:
            multArrays(quantity, price, total, SIZE);
            cout << endl;
            break;
            // Print total
        case 3:
            displayArray(total, SIZE);
            cout << endl;
            break;
            // Sum of odd elements
        case 4:
            cout << "\nSum of odd numbers: " << sumOddArray(total, SIZE);
            cout << endl;
            break;
            // Check all positive
        case 5:
            if (isAllPositive(total, SIZE))
                cout << "\nAll values are positive." << endl;
            else
                cout << "\nNot all values are positive." << endl;
            break;
            // Average of odd elements
        case 6: {
            int avg = 0;
            if (avgOddArray(total, SIZE, avg))
                cout << "Average of odd numbers: " << avg << endl;
            else
                cout << "No odd numbers found in the array." << endl;
            break;
        }
              // Revert array
        case 7: {
            revertNumbers(total, SIZE);
            cout << "Array reverted." << endl;
            displayArray(total, SIZE);
            break;
        }
              // Exit
        case 0:
            // No code needed
            break;
        default:
            assert(false);
        }
    } while (choice != 0);

    cout << "\nHave a nice day:)" << endl;
    return 0;
}

/**
 * <code>printMenu</code> shows a menu and gets the choice
 * from the user which is returned.
 * <BR>
 * @return Returns the menu choice
 */
int printMenu() {
    int choice;

    do {
        cout << "== MENU =="<<endl;
        cout << "1) Enter quantity" << endl;
        cout << "2) Calculate total"<<endl;
        cout << "3) Print total"<<endl;
        cout << "4) Sum of odd elements in total"<<endl;
        cout << "n5) Check if all elements are positive"<<endl;
        cout << "6) Average of odd elements in total"<<endl;
        cout << "7) Revert total array"<<endl;
        cout << "0) Exit"<<endl;
        cout << "Enter choice: "<<endl;
        cin >> choice;

        if (choice < 0 || choice > 7) {
            cout << "\nWrong choice, try again.";
        }
    } while (choice < 0 || choice > 7);
    return choice;
}

/**
 * <code>fillInArray</code> will
 * fill in the elements of an array.
 * <BR>
 * @param arr  The array to be filled in.
 * @param size The size of the array.
 */
void fillInArray(int arr[], const int size) {
    assert(size > 0);

    for (int i = 0; i < size; ++i) {
        cout << "Enter an element for the array at " << i << ": " << endl;
        cin >> arr[i];
    }
}

/**
 * <code>multArrays</code> multiplies the value of elements of the quantity array
 * by the corresponding value of the price array and stores the result in the
 * total array both with and without VAT.
 * <BR>
 * @param arrQuantity The array containing the quantity elements.
 * @param arrPrice    The array containing the price elements.
 * @param arrTotal    The 2D array that will receive the computed totals.
 *                    arrTotal[i][0] = total without VAT.
 *                    arrTotal[i][1] = total with VAT.
 * @param size        how big are the arrays.
 */
void multArrays(const int arrQuantity[], const int arrPrice[], int arrTotal[][2], const int size) {
    assert(size > 0);

    for (int i = 0; i < size; ++i) {
        arrTotal[i][0] = arrQuantity[i] * arrPrice[i];
        arrTotal[i][1] = static_cast<int>(arrQuantity[i] * (arrPrice[i] * (1 + VAT)));
    }
}

/**
 * <code>displayArray</code> prints the value of every element of the array,
 * both without and with VAT. also addition the function finds the sum of all values
 * with VAT and prints it.
 * <BR>
 * @param arr  The 2D array containing the values .
 * @param size The size of the array.
 */
void displayArray(const int arr[][2], const int size) {
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        cout << "Value at " << i << endl;
        cout << " with no VAT: " << arr[i][0] << endl;
         cout   << "  with VAT: " << arr[i][1]<<endl;
        sum += arr[i][1];
    }

    cout << "The grand total with VAT is: " << sum<<endl;
}

/**
 * <code>sumOddArray</code> sums all odd numbers
 * in the array and returns the result.
 * <BR>
 * @param arr  The 2D array .
 * @param size The number of numbers in the array.
 * @return     The sum of all odd values and  0 if none exist.
 */
int sumOddArray(const int arr[][2], const int size) {
    assert(size > 0);
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i][0] % 2 != 0)
            sum += arr[i][0];
    }
    return sum;
}

/**
 * <code>isAllPositive</code> checks if every element in the array is
 * positive. Checks the without VAT .
 * <BR>
 * @param arr  The 2D array to examine.
 * @param size The number of elements in the array.
 * @return     Returns <code>true</code> if all elements are positive,
 *             <code>false</code> otherwise.
 */
bool isAllPositive(const int arr[][2], const int size) {
    assert(size > 0);
    for (int i = 0; i < size; ++i) {
        if (arr[i][0] <= 0)
            return false;
    }
    return true;
}

/**
 * <code>avgOddArray</code> computes the integer average of all odd
 * elements in the array and stores the result in
 * <code>avgOdd</code>.
 * <BR>
 * @param arr    The 2D array to examine.
 * @param size   The number of elements in the array.
 * @param avgOdd parameter that has the computed average.
 * @return       Returns <code>true</code> if at least one odd element was found
 *               and the average has been stored; <code>false</code> if the
 *               array contains no odd numbers .
 */
bool avgOddArray(const int arr[][2], const int size, int& avgOdd) {
    assert(size > 0);
    int sum = 0, count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i][0] % 2 != 0) {
            sum += arr[i][0];
            ++count;
        }
    }
    if (count == 0)
        return false;
    avgOdd = sum / count;
    return true;
}

/**
 * <code>revertNumbers</code> reverses the rows of the 2D array in place.
 * <BR>
 * @param arr  The 2D array whose rows are to be reversed.
 * @param size The number of elements in the array.
 */
void revertNumbers(int arr[][2], const int size) {
    assert(size > 0);
    int left = 0, right = size - 1;
    while (left < right) {
        // swap column 0
        int temp = arr[left][0];
        arr[left][0] = arr[right][0];
        arr[right][0] = temp;
        // swap column 1
        temp = arr[left][1];
        arr[left][1] = arr[right][1];
        arr[right][1] = temp;
        ++left;
        --right;
    }
}