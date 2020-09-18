/*
Full name: Ariel Gutierrez
Student ID: 2318163
Chapman email: arigutierrez@chapman.edu
Course number and section: CPSC 350-01
Assignment or exercise number: Assignment 1

Assignment 1: A simple analysis program that will compute basics stastics for a
list of DNA strings.
*/

#include "assign1.cpp"

int main(int argc, char** argv){
  if(argc < 1){
    cout << "Invalid usage: please enter a file to open" << endl;
    return -1;
  }
  string fileName = argv[1];

  ofstream outfile;
  outfile.open("ArielGutierrez.out", std::ofstream::out | std::ofstream::app);
  cout << "Name: Ariel Gutierrez\n" << endl;
  cout << "Student ID: 2318163\n" << endl;
  cout << "Chapman email: arigutierrez@chapman.edu\n" << endl;
  cout << "Chapman email: arigutierrez@chapman.edu\n" << endl;
  cout << "Course number and section: CPSC 350-01\n" << endl;
  cout << "Assignment or exercise number: Assignment 1\n" << endl;
  cout << "\n" << endl;

  while(true){
    DnaProcessor dp;
    dp.statistics(fileName, outfile);
    dp.nucleotideProbability(fileName, outfile);
    dp.bigramProbability(fileName, outfile);
    dp.gaussianDistribution(outfile); // not done with this portion

    bool isAsking = true;
    while(isAsking){
      cout << "Do you want to process another list? (y/n)\n" << endl;
      char userInput;
      cin >> userInput;
      if(userInput == ("y"||"Y")){
        cout << "What is the name of the file you want to process?\n" << endl;
        cin >> fileName;
        isAsking = false;
      } else if(userInput == ("n"||"N")){
        isAsking = false;
        outfile.close();
        cout << "Goodbye." << endl;
        return 0;
      } else{
        cout << "Invalid Input. Choose y(yes) or n(no).\n";
      }
    }
  }
  return 0;
}
