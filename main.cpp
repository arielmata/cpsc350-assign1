/*
Full name: Ariel Gutierrez
Student ID: 2318163
Chapman email: arigutierrez@chapman.edu
Course number and section: CPSC 350-01
Assignment or exercise number: Assignment 1

Assignment 1: A simple analysis program that will compute basics statistics for
a list of DNA strings.
*/

#include "assign1.h"

//Main function: uses class DnaProcessor to run a simple analysis program that
//computes basic statistics (sum, mean, variance, standard deviation),
//computes the relative probability of each nucleotide and each nucleotide
//bigram, as well as generating 1000 DNA strings following a Gaussian
//distrubution. It receives the list from a file given as a command line
//argument. All this information is then added onto a file called
//ArielGutierrez.out
int main(int argc, char** argv){
  if(argc < 1){
    cout << "Invalid usage: please enter a file to open" << endl;
    return -1;
  }
  string fileName = argv[1];

  ofstream outfile;
  outfile.open("ArielGutierrez.out");
  outfile << "Name: Ariel Gutierrez" << endl;
  outfile << "Student ID: 2318163" << endl;
  outfile << "Chapman email: arigutierrez@chapman.edu" << endl;
  outfile << "Course number and section: CPSC 350-01" << endl;
  outfile << "Assignment or exercise number: Assignment 1" << endl;
  outfile << "\n" << endl;

  while(true){
    DnaProcessor dp;
    dp.statistics(fileName, outfile);
    dp.nucleotideProbability(fileName, outfile);
    dp.bigramProbability(fileName, outfile);
    dp.gaussianDistribution(outfile);

    //checking if user wants to process another list
    bool isAsking = true;
    while(isAsking){
      cout << "Do you want to process another list? (y/n)\n" << endl;
      string userInput;
      cin >> userInput;
      if(userInput == "y" || userInput == "Y"){
        cout << "What is the name of the file you want to process?\n" << endl;
        cin >> fileName;
        isAsking = false;
      } else if(userInput == "n" || userInput == "N"){
        isAsking = false;
        outfile.close();
        return 0;
      } else{
        cout << "Invalid Input. Choose y(yes) or n(no).\n" << endl;
      }
    }
  }
  return 0;
}
