The application I built is a student grade manager in c++ with the purpose of having a single fixed size integer array
the program allows a user to store, view, modify, search, sort, and analyze a list of student grades. Every meny option maps 
to a fundamental array operation so the project doubles as a working refrence for how arrays behave in memory. The problem being solved through this project is 
how arrays are easy to misuse because they have a fixed capacity and no built in length while also requiring mannual bookkepping
when elements are added or removed. The project was created to demonstrate how to create and declare an array as well as track
the logical size seperatly from the physical capacity. Overall serving as a learning artifact that an educator could use to keep 
track of grades. The technologies I used for this project go as follows, Language: C++, std library: iostream,iomanip,limits
compiler: g++, build: single file compilation. In order to setup and install this project you simply need a c++ compiler, then from the project
directory use the command: "g++ -std=c++17 -Wall -Wextra -o student_grade_manager main.cpp" then run: "./student_grade_manager"
The program starts pre-loaded with some sample grades so you can experiement. Some key features and functionality include some of these functions
that i implimented from scratch, display(traversal), insertion, dletion using index, linear search, bubble sort, and statistics.
My role and contributions from this porject was the complete implimentation following the menu driven nature, each operation, and the input validation
I also implimented this README. The goal was to make this code readable so someone who doesnt program in c++ can still understand what is happening in the project.
Here is a potential sample output: ----- Menu -----
1. Display all grades
2. Add a grade
3. Remove a grade (by index)
4. Search for a grade
5. Sort grades (ascending)
6. Show statistics (min/max/avg)
0. Exit
Enter your choice: 1
Current grades (7 items):
  [0] = 85
  [1] = 72
  [2] = 90
  [3] = 67
  [4] = 78
  [5] = 95
  [6] = 88

Enter your choice: 5
Grades sorted in ascending order.
Current grades (7 items):
  [0] = 67
  [1] = 72
  [2] = 78
  [3] = 85
  [4] = 88
  [5] = 90
  [6] = 95

Enter your choice: 6
Statistics:
  Count   : 7
  Minimum : 67
  Maximum : 95
  Average : 82.14

Enter your choice: 0
Goodbye!

Some of the lesson ive learned through this project include working through challenges. One in particular was the implimentation of the deletion function. with a higher-level container like std::vector
calling erase hides the cost of shifting every element after deleting index. writing the shift loop by hand made the time complexity of the program obivious. In addition
learning to track the logical size seperately from the arrays physical capacity.


