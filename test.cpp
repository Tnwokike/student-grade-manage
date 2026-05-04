

#include <iostream>
#include <iomanip>
#include <limits>

const int MAX_SIZE = 100;   


void displayMenu();
void displayGrades(const int grades[], int size);
void addGrade(int grades[], int& size);
void removeGrade(int grades[], int& size);
int  searchGrade(const int grades[], int size, int target);
void sortGrades(int grades[], int size);
void showStatistics(const int grades[], int size);
int  getValidatedInt(const std::string& prompt);


int main() {
    int grades[MAX_SIZE];     
    int size = 0;             

    int sample[] = {85, 72, 90, 67, 78, 95, 88};
    for (int i = 0; i < 7; ++i) {
        grades[i] = sample[i];
        ++size;
    }

    

    int choice = -1;
    while (choice != 0) {
        displayMenu();
        choice = getValidatedInt("Enter your choice: ");

        switch (choice) {
            case 1:
                displayGrades(grades, size);
                break;
            case 2:
                addGrade(grades, size);
                break;
            case 3:
                removeGrade(grades, size);
                break;
            case 4: {
                int target = getValidatedInt("Enter grade to search for: ");
                int idx = searchGrade(grades, size, target);
                if (idx == -1)
                    std::cout << "Grade " << target << " not found.\n";
                else
                    std::cout << "Grade " << target << " found at index " << idx << ".\n";
                break;
            }
            case 5:
                sortGrades(grades, size);
                std::cout << "Grades sorted in ascending order.\n";
                displayGrades(grades, size);
                break;
            case 6:
                showStatistics(grades, size);
                break;
            case 0:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}



void displayMenu() {
    std::cout << "\n----- Menu -----\n"
              << "1. Display all grades\n"
              << "2. Add a grade\n"
              << "3. Remove a grade (by index)\n"
              << "4. Search for a grade\n"
              << "5. Sort grades (ascending)\n"
              << "6. Show statistics (min/max/avg)\n"
              << "0. Exit\n";
}


void displayGrades(const int grades[], int size) {
    if (size == 0) {
        std::cout << "The array is empty.\n";
        return;
    }
    std::cout << "Current grades (" << size << " items):\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "  [" << i << "] = " << grades[i] << "\n";
    }
}


void addGrade(int grades[], int& size) {
    if (size >= MAX_SIZE) {
        std::cout << "Array is full. Cannot add more grades.\n";
        return;
    }
    int g = getValidatedInt("Enter grade (0-100): ");
    if (g < 0 || g > 100) {
        std::cout << "Grade must be between 0 and 100.\n";
        return;
    }
    grades[size++] = g;
    std::cout << "Grade added. Total grades: " << size << "\n";
}


void removeGrade(int grades[], int& size) {
    if (size == 0) {
        std::cout << "Nothing to remove. Array is empty.\n";
        return;
    }
    int idx = getValidatedInt("Enter index to remove: ");
    if (idx < 0 || idx >= size) {
        std::cout << "Invalid index.\n";
        return;
    }
    for (int i = idx; i < size - 1; ++i) {
        grades[i] = grades[i + 1];   
    }
    --size;
    std::cout << "Grade at index " << idx << " removed.\n";
}


int searchGrade(const int grades[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (grades[i] == target) return i;
    }
    return -1;
}


void sortGrades(int grades[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (grades[j] > grades[j + 1]) {
                int tmp = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = tmp;
            }
        }
    }
}


void showStatistics(const int grades[], int size) {
    if (size == 0) {
        std::cout << "No grades to analyze.\n";
        return;
    }
    int minVal = grades[0];
    int maxVal = grades[0];
    long sum = 0;
    for (int i = 0; i < size; ++i) {
        if (grades[i] < minVal) minVal = grades[i];
        if (grades[i] > maxVal) maxVal = grades[i];
        sum += grades[i];
    }
    double avg = static_cast<double>(sum) / size;
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Statistics:\n"
              << "  Count   : " << size   << "\n"
              << "  Minimum : " << minVal << "\n"
              << "  Maximum : " << maxVal << "\n"
              << "  Average : " << avg    << "\n";
}


int getValidatedInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) return value;
        std::cout << "Invalid input. Please enter a whole number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}