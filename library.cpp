#include <iostream>
using namespace std;

int main() {
    const int BOOK_COUNT = 4;
    const int STUDENT_COUNT = 4;

    int choice, index;
    bool is_found;
    int iban, student_roll_number;

    int book_iban_arr[BOOK_COUNT] = {1, 2, 3, 4};
    string book_names[BOOK_COUNT] = {"History", "Computer Science", "Chemistry", "Literature"};
    string book_authors[BOOK_COUNT] = {"John Doe", "Jane Smith", "Alice Johnson", "Bob Brown"};
    string book_editions[BOOK_COUNT] = {"1st Edition", "2nd Edition", "3rd Edition", "4th Edition"};
    double book_prices[BOOK_COUNT] = {800.0, 1200.0, 600.0, 150.0};
    int book_quantities[BOOK_COUNT] = {3, 2, 5, 2};

    int student_roll_numbers[STUDENT_COUNT] = {101, 102, 103, 104};
    int student_ages[STUDENT_COUNT] = {20, 21, 22, 23};

    do {
        cout << "\n1. Issue a book to a student" << endl;
        cout << "2. Student returns a book" << endl;
        cout << "3. Display details of all books sorted by price" << endl;
        cout << "4. Display details of all students sorted by age" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter student roll number (101, 102, 103, 104): ";
                cin >> student_roll_number;

                is_found = false;
                for (int i = 0; i < STUDENT_COUNT; i++) {
                    if (student_roll_number == student_roll_numbers[i]) {
                        is_found = true;
                        break;
                    }
                }
                if (!is_found) {
                    cout << "Invalid student roll number. Please try again." << endl;
                    break;
                }

                cout << "Enter book IBAN (1 for History, 2 for Computer Science, 3 for Chemistry, 4 for Literature): ";
                cin >> iban;

                is_found = false;
                for (int i = 0; i < BOOK_COUNT; i++) {
                    if (iban == book_iban_arr[i] && book_quantities[i] > 0) {
                        is_found = true;
                        index = i;
                        break;
                    }
                }

                if (is_found) {
                    cout << "Book \"" << book_names[index] << "\" by " << book_authors[index] << " (Edition: " << book_editions[index] << ") has been issued to student with roll number " << student_roll_number << endl;
                    book_quantities[index]--;
                } else {
                    cout << "Book not available or invalid IBAN. Please try again." << endl;
                }
                break;

            case 2:
                cout << "Enter student roll number (101, 102, 103, 104): ";
                cin >> student_roll_number;

                is_found = false;
                for (int i = 0; i < STUDENT_COUNT; i++) {
                    if (student_roll_number == student_roll_numbers[i]) {
                        is_found = true;
                        break;
                    }
                }
                if (!is_found) {
                    cout << "Invalid student roll number. Please try again." << endl;
                    break;
                }

                cout << "Enter book IBAN (1 for History, 2 for Computer Science, 3 for Chemistry, 4 for Literature): ";
                cin >> iban;

                is_found = false;
                for (int i = 0; i < BOOK_COUNT; i++) {
                    if (iban == book_iban_arr[i]) {
                        is_found = true;
                        index = i;
                        break;
                    }
                }

                if (is_found) {
                    cout << "Book \"" << book_names[index] << "\" by " << book_authors[index] << " (Edition: " << book_editions[index] << ") has been returned by student with roll number " << student_roll_number << endl;
                    book_quantities[index]++;
                } else {
                    cout << "Invalid IBAN. Please try again." << endl;
                }
                break;

            case 3:
                for (int i = 0; i < BOOK_COUNT - 1; i++) {
                    for (int j = 0; j < BOOK_COUNT - i - 1; j++) {
                        if (book_prices[j] > book_prices[j + 1]) {
                            swap(book_iban_arr[j], book_iban_arr[j + 1]);
                            swap(book_names[j], book_names[j + 1]);
                            swap(book_authors[j], book_authors[j + 1]);
                            swap(book_editions[j], book_editions[j + 1]);
                            swap(book_prices[j], book_prices[j + 1]);
                            swap(book_quantities[j], book_quantities[j + 1]);
                        }
                    }
                }

                cout << "Sorted book details by price:" << endl;
                for (int i = 0; i < BOOK_COUNT; i++) {
                    cout << "IBAN: " << book_iban_arr[i] << " | Name: " << book_names[i] << " | Author: " << book_authors[i] << " | Edition: " << book_editions[i] << " | Price: " << book_prices[i] << " | Quantity: " << book_quantities[i] << endl;
                }
                break;

            case 4:
                for (int i = 0; i < STUDENT_COUNT - 1; i++) {
                    for (int j = 0; j < STUDENT_COUNT - i - 1; j++) {
                        if (student_ages[j] > student_ages[j + 1]) {
                            swap(student_roll_numbers[j], student_roll_numbers[j + 1]);
                            swap(student_ages[j], student_ages[j + 1]);
                        }
                    }
                }

                cout << "Sorted student details by age:" << endl;
                for (int i = 0; i < STUDENT_COUNT; i++) {
                    cout << "Roll Number: " << student_roll_numbers[i] << " | Age: " << student_ages[i] << endl;
                }
                break;

            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}