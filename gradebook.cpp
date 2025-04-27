#include <iostream>
#include <string>

using namespace std;

// Function prototypes
void enterStudentData(string studentNames[], int studentGrades[], int size);
void sortGrades(string studentNames[], int studentGrades[], int size);
int searchGrade(string studentNames[], int studentGrades[], int size, const string& name);
void calculateStatistics(int studentGrades[], int size);

int main() {

    // Variable used to allocate for the size/length of the arrays
    int size;

    // User prompt
    cout << "Enter the number of students: ";
    cin >> size;
    
    // Declaring arrays
    string studentNames[size];
    int studentGrades[size];
    
    // Call to function that initializes both arrays
    enterStudentData(studentNames, studentGrades, size);
    
    // Call to function that sorts arrays in ascending order based on grade
    sortGrades(studentNames, studentGrades, size);

    // Display sorted grades after function call   
    cout << "Sorted Grades:\n";
    for (int i = 0; i < size; i++) {
        cout << studentNames[i] << ": " << studentGrades[i] << "\n";
    }
    
    // Variable used to search and find a particular student's name and grade
    string searchName;

    // Prompt user for a name to search
    cout << "Enter student name to search: ";
    cin >> searchName;

    // Call to function that searches and finds inputted student's name and accompanying grade, result stored in variable grade
    int grade = searchGrade(studentNames, studentGrades, size, searchName);

    // Display particular student's grade if found
    if (grade != -1) {
        cout << searchName << "'s grade: " << grade << "\n";
    } else { // If not found, display not found 
        cout << searchName << " not found.\n";
    }
    
    // Call to function that calculates and outputs class statistics
    calculateStatistics(studentGrades, size);
    
    return 0;
}

// Function definitions

// Initializes both arrays bases on a given size
void enterStudentData(string studentNames[], int studentGrades[], int size) {
    // This loop iterates over through the array from the first element to the last element
    for (int index = 0; index < size; index++) {

        // Prompts user for a particular student's name
        cout << "Enter student name: ";
        cin >> studentNames[index];

        // Prompts user for that student's grade
        cout << "Enter " << studentNames[index] << "'s grade: ";
        cin >> studentGrades[index];
    }
}

// Sorts arrays in ascending order based on grades
void sortGrades(string studentNames[], int studentGrades[], int size) {

    // This outer loop iterates through the array from the first element to the second-to-last element because the last iteration is not necessary
    for (int currentIndex = 0; currentIndex < size - 1; currentIndex++) {

        // This inner loop starts from the element right after the current
        for (int nextIndex = currentIndex + 1; nextIndex < size; nextIndex++) {

            // At each iteration, if the current element is greater than the next element, both grades and names are swapped
            if (studentGrades[currentIndex] > studentGrades[nextIndex]) {
                // Swap grades
                int tempGrade = studentGrades[currentIndex];
                studentGrades[currentIndex] = studentGrades[nextIndex];
                studentGrades[nextIndex] = tempGrade;
                
                // Swap names
                string tempName = studentNames[currentIndex];
                studentNames[currentIndex] = studentNames[nextIndex];
                studentNames[nextIndex] = tempName;
            }
        }
    }
}


// Searches for a particular student's name in the studentNames array and returns relative grade from studentGrades array
int searchGrade(string studentNames[], int studentGrades[], int size, const string& name) {

    // This loop iterates through the studentNames array from the first element to the last element
    for (int i = 0; i < size; i++) {

        // For each iteration, the current element in the studentNames array is compared with the name parameter to check for a match
        if (studentNames[i] == name) {

            // If a match is found, the relative grade is returned at that current index
            return studentGrades[i];
        }
    }
    // If a match is not found, a negative integer is returned indicating that the student was not found
    return -1; 
}

// Calculates and outputs the average, highest, and lowest grade from the studentGrades array
void calculateStatistics(int studentGrades[], int size) {

    // Variable to store the total sum of all the grades, used to calculate grade average
    int sum = 0;

    // Variable to store the highest grade, initialized to 0 assuming the first element is the highest
    int highest = studentGrades[0];

    // Variable to store the lowest grade, initialized to 0 assuming the first element is the lowest
    int lowest = studentGrades[0];

    // This loop iterates through the studentGrades array from the first element to the last element
    for (int i = 0; i < size; i++) {

        // Updates the total sum at each iteration
        sum = sum + studentGrades[i];

        // Updates highest grade at each iteration only if current element is greater than the highest grade
        if (studentGrades[i] > highest) highest = studentGrades[i];

        // Updates lowest grade at each iteration only if the current element is less than the lowest grade
        if (studentGrades[i] < lowest) lowest = studentGrades[i];
    }
    // Calculates average 
    double average = static_cast<double>(sum) / size;
    
    // Outputs class statistics after evaluation
    cout << "Class Statistics:\n";
    cout << "Average Grade: " << average << "\n";
    cout << "Highest Grade: " << highest << "\n";
    cout << "Lowest Grade: " << lowest << "\n";
}
