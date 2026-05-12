/** \file bugExample.cpp
 *  \brief     A little with logical bugs in it
 *  \details   This program is littered with logical bugs. Your task is the
 *              following:
 *                1) Compile and run the program.
 *                2) For each bug you find you must fix the bug then commit
 *                   the code with a comment on the fix you did
 *                3) There are a four functions that are not completed, you need to
 *                   complete them and also update the menu and the main function
 *  \author    Harald Gjermundrod
 *  \version   0.1
 *  \date      20/10/2025
 *  \bug       Many logical bugs
 *  \copyright University of Nicosia.
 */

#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

// Function prototypes
int printMenu();
void fillInArray(int[], const int);
void multArrays(const int[], const int[], int[], const int);
void displayArray(const int[], const int);
int sumOddArray(const int[], const int);
bool isAllPositive(const int[], const int);
bool avgOddArray(const int[], const int, int&);
void revertNumbers(int[], const int);

/**
 * <code>main</code> is the main function of this program.
 * <BR>
 * @return Returns 0 if success, any other value otherwise.
 */
int main() {
    int choice;
    const int SIZE = 10;

    // Initialize array price
    int price[SIZE] = { 12, 4, 8, 1, 17, 2, 4, 2, 9, 1 };
    // Declare array quantity and total
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
        case 4:
            cout << "Sum of odd numbers: " << sumOddArray(total, SIZE);
            cout << endl;
            break;
            case 5:
                if (isAllPositive(total, SIZE))
                    cout << "All values are positive."<<endl;
                else
                    cout << "Not all values are positive."<<endl;
                break;
               
                case 6:
                    int avg = 0;
                    if (avgOddArray(total, SIZE, avg))
                        cout << "Average of odd numbers: " << avg<<endl;
                    else
                        cout << "No odd numbers found in the array."<<endl;
                    break;
                case 7: int avg = 0;
                    revertNumbers(total, SIZE);
                    cout << "Array reverted."<<endl;
                    displayArray(total, SIZE);
                    break;
            // Exit
        case 0:
            // No code needed
            break;
        default:
            assert(false);
        }
    } while (choice != 0); 
    srand(time(0));
    for (int i = 0; i < SIZE; ++i) {
        price[i] = 10 + rand() % 41;
    }
    // With:

  
    cout << "Have a nice day:)" << endl;
    return 0;
}

/**
 * <code>printMenu</code> shows a menu and accepts the choice
 * from the user which is returned.
 * <BR>
 * @return Returns the menu choice
 */
int printMenu() {
    int choice; 

    do {
        //New menu with the 4 new options
        cout << "\n == MENU ==";
        cout << "\n1) Enter quantity";
        cout << "\n2) Calculate total";
        cout << "\n3) Print total";
        cout << "\n4) Sum of odd elements in total";
        cout << "\n5) Check if all elements are positive";
        cout << "\n6) Average of odd elements in total";
        cout << "\n7) Revert total array";
        cout << "\n0) Exit";
        cout << "Enter choice" << endl;
        cin >> choice;

        if (choice < 0 || choice > 7) {
            cout << "\nWrong choice, try again.";
        }
    } while (choice < 0 || choice > 7);
    return choice;
}

/**
 * <code>fillInArray</code> is a function that will
 * fill in the elements of an array.
 * <BR>
 * @param arr The array to be filled in.
 * @param size The size of the array.
 */
void fillInArray(int arr[], const int size) {
    assert(size > 0);

    for (int i = 0; i < size; ++i) {
        cout << "\nEnter an element for the array at " << i << ": ";
        cin >> arr[i];
    }
}

/**
 * <code>multArrays</code> multiplies the value of elements of the source array
 * to the corresponding value at the destination array. NOTE: precondition
 * is that the arrays have the same size.
 * <BR>
 * @param arrSource The array containing the destination elements.
 * @param arrDest The array containing the source elements.
 * @param size The size of the arrays.
 */
void multArrays(const int arrQuantity[], const int arrPrice[], int arrTotal[], const int size) {
    assert(size > 0);
    for (int i = 0; i < size; ++i) {
        arrTotal[i] = arrQuantity[i] * (arrPrice[i] * (1 + VAT));
    }
}

/**
 * <code>displayArray</code> prints the value of each of the elements of the
 * array. In addition the function sums up the value of all the elements and
 * print the total.
 * <BR>
 * @param arr The array containing the values
 * @param size The size of the array.
 */
void displayArray(const int arr[], const int size) {
    int sum = 0;

    for (int i = 0; i < size; ++i) {
        cout << "\nValue at " << i << ": " << arr[i];
        sum += arr[i];
    }

    cout << "\nThe total is: " << sum;
}


/**
 * <code>sumOddArray</code> sums all odd numbers found in the array and
 * returns the result.
 * <BR>
 * @param arr  The array to examine.
 * @param size The number of elements in the array.
 * @return     The sum of all odd valued elements and 0 if none exist.
 */
int sumOddArray(const int arr[], const int size) {
        assert(size > 0);
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            if (arr[i] % 2 != 0)
                sum += arr[i];
        }
        return sum;
}

 /**
 * <code>isAllPositive</code> checks if every element in the array is
 * positive 
 * <BR>
 * @param arr  The array to examine.
 * @param size The number of elements in the array.
 * @return     Returns <code>true</code> if all elements are positive
 * <code>false</code> otherwise.
 */
bool isAllPositive(const int arr[], const int size) {
    assert(size > 0);
    for (int i = 0; i < size; ++i) {
        if (arr[i] <= 0)
            return false;
    }
    return true;
}

/**
 * <code>avgOddArray</code> finds the integer average of all odd values
 * in the array and stores the result in <code>avgOdd</code>.
 * <BR>
 * @param arr    The array we want to examine.
 * @param size   The number of elements in the array.
 * @param avgOdd parameter wiht the average
 * @return       Returns <code>true</code> if at least one odd element was found
 *               and the average has been stored <code>false</code> if the
 *               array contains only even numbers.
 */
bool avgOddArray(const int arr[], const int size, int& avgOdd) {
    assert(size > 0);
    int sum = 0, count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 != 0) {
            sum += arr[i];
            count++;
        }
    }
    if (count == 0){
        return false;
        }
    avgOdd = sum / count;
    return true;
}
/**
 * <code>revertNumbers</code> reverses the elements of the array.
 * <BR>
 * @param arr  The array with the elements we want to reverse.
 * @param size The number of elements in the array.
 */

void revertNumbers(int arr[], const int size) {
       assert(size > 0);
       int temp = 0;
       for (int i = 0; i < (size / 2); i++) {
           temp = arr[i];
           arr[i] = arr[size - i - 1];
           arr[size - i - 1] = temp;
       }

}
