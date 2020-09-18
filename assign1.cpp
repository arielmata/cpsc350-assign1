/*
Full name: Ariel Gutierrez
Student ID: 2318163
Chapman email: arigutierrez@chapman.edu
Course number and section: CPSC 350-01
Assignment or exercise number: Assignment 1

Assignment 1: A simple analysis program that will compute basics stastics for a
list of DNA strings.
*/

#include "assign1.h"
#include <math.h> // pow, sqrt, M_PI, log
#include <stdlib.h> //rand, RAND_MAX


// Default Constructor
DnaProcessor::DnaProcessor(){
  sum = 0;
  mean = 0.0;
  var = 0.0;
  standardDev = 0.0;
  probA = 0.0;
  probC = 0.0;
  probT = 0.0;
  probG = 0.0;
}

// Deconstructor
DnaProcessor::~DnaProcessor(){
  cout << "Farewell!" << endl;
}

// Computes the sum, mean, variance, and standard deviation of the length of
// the DNA strings in the list, and adds information to output file.
void DnaProcessor::statistics(string fileName, ofstream& ofs){
  int count = 0;
  string line;
  double numerator = 0.0;

  ifstream infile;
  infile.open(fileName);
  while(getline(infile, line)){ //get line??
    sum += line.length();
    ++count;
  }
  mean = sum/count;
  infile.close();

  infile.open(fileName);
  while(getline(infile, line)){
    numerator += pow((line.length() - mean),2);
  }
  infile.close();
  var = numerator/(sum-1);
  standardDev = sqrt(var);

  ofs << "The Sum of the length of the DNA strings::" << sum;
  ofs << "The Mean of the length of the DNA strings:" << mean;
  ofs << "The variance of the length of the DNA strings:" << var;
  ofs << "The Standard Deviation of the length of the DNA stings:" <<standardDev;
  ofs << "\n";
  ofs << "\n";
}

// Computes the relative probability of each nucleotide (A,C,T, or G) and
// outputs them to given file.
void DnaProcessor::nucleotideProbability(string fileName, ofstream& ofs){
  string line;
  int countA = 0, countC = 0, countT = 0, countG = 0, nuCount = 0;

  ifstream infile;
  infile.open(fileName);
  while(getline(infile, line)){
    for (int i = 0; i < line.length(); ++i){
      ++nuCount;
      if(tolower(line[i]) == 'a'){
        ++countA;
      } else if(tolower(line[i]) == 'c'){
        ++countC;
      } else if(tolower(line[i]) == 't'){
        ++countT;
      } else if(tolower(line[i]) == 'g'){
        ++countG;
      }
    }
  }
  infile.close();

  probA = countA/nuCount;
  probG = countG/nuCount;
  probT = countT/nuCount;
  probC = countC/nuCount;

  ofs << "Here is the relative probability of each nucleotide:\n";
  ofs << "\n";
  ofs << "A:     " << probA << "\n";
  ofs << "G:     " << probG << "\n";
  ofs << "T:     " << probT << "\n";
  ofs << "C:     " << probC << "\n";
  ofs << "\n";
  ofs << "\n";
}

// Computes the relative probability of each nucleotide bigram
// (AA, CC, TT, GG, AC, AT, AG, CA, CT, CG, TA, TC, TG, GA, GC, GT)
// and outputs the result into given output file.
void DnaProcessor::bigramProbability(string fileName, ofstream& ofs){
  int countAA = 0, countCA = 0, countTA = 0, countGA = 0;
  int countAC = 0, countCC = 0, countTC = 0, countGC = 0;
  int countAT = 0, countCT = 0, countTT = 0, countGT = 0;
  int countAG = 0, countCG = 0, countTG = 0, countGG = 0;
  int bigramCount;
  string line, compare;

  ifstream infile;
  infile.open(fileName);
  while(getline(infile, line)){
    if(line.length()%2 == 1){
      // odd - add first nucleotide to end of string
      line += line[0];
    }
    for(int i = 0; i < line.length()/2; ++i){
      ++bigramCount;
      compare = tolower(line[2*i]) + "" + tolower(line[2*i+1]);
      if(compare == "aa"){
        ++countAA;
      } else if(compare == "ca"){ //forbids comparison between pointer and integer
        ++countCA;
      } else if(compare == "ta"){
        ++countTA;
      } else if(compare == "ga"){
        ++countGA;
      } else if(compare == "ac"){
        ++countAC;
      } else if(compare == "cc"){
        ++countCC;
      } else if(compare == "tc"){
        ++countTC;
      } else if(compare == "gc"){
        ++countGC;
      } else if(compare == "at"){
        ++countAT;
      } else if(compare == "ct"){
        ++countCT;
      } else if(compare == "tt"){
        ++countTT;
      } else if(compare == "gt"){
        ++countGT;
      } else if(compare == "ag"){
        ++countAG;
      } else if(compare == "cg"){
        ++countCG;
      } else if(compare == "tg"){
        ++countTG;
      } else if(compare == "gg"){
        ++countGG;
      }
    }
  }
  infile.close();

  ofs << "Here is the relative probability of each nucleotide bigram:\n";
  ofs << "AA:     " << (double)countAA/bigramCount <<"\n";
  ofs << "AC:     " << (double)countAC/bigramCount <<"\n";
  ofs << "AT:     " << (double)countAT/bigramCount <<"\n";
  ofs << "AG:     " << (double)countAG/bigramCount <<"\n";
  ofs << "CA:     " << (double)countCA/bigramCount <<"\n";
  ofs << "CC:     " << (double)countCC/bigramCount <<"\n";
  ofs << "CT:     " << (double)countCT/bigramCount <<"\n";
  ofs << "CG:     " << (double)countCG/bigramCount <<"\n";
  ofs << "TA:     " << (double)countTA/bigramCount <<"\n";
  ofs << "TC:     " << (double)countTC/bigramCount <<"\n";
  ofs << "TT:     " << (double)countTT/bigramCount <<"\n";
  ofs << "TG:     " << (double)countTG/bigramCount <<"\n";
  ofs << "GA:     " << (double)countGA/bigramCount <<"\n";
  ofs << "GC:     " << (double)countGC/bigramCount <<"\n";
  ofs << "GT:     " << (double)countGT/bigramCount <<"\n";
  ofs << "GG:     " << (double)countGG/bigramCount <<"\n";
  ofs << "\n";
  ofs << "\n";
}

// Generate 1000 DNA strings whose lengths follow a Gaussian distribution, and
// it appends it to the output file.
void DnaProcessor::gaussianDistribution(ofstream& ofs){
  double a, b, C, D, num;
  string nucleoStr;

  for(int i = 0; i < 1000; ++i){
    a = (double)rand()/RAND_MAX;
    b = (double)rand()/RAND_MAX;
    C = sqrt(-2*log(a))*cos(2*M_PI*b);
    D = standardDev*C + mean;
    nucleoStr = "";

    for(int j = 0; j < D; ++j){
      num = double(rand())/100; // make a percentage
      while (true){
        if(num == probA){
          nucleoStr += "A";
          break;
        } else if(num == probT){
          nucleoStr += "C";
          break;
        } else if(num == probC){
          nucleoStr += "T";
          break;
        } else if(num == probG){
          nucleoStr += "G";
          break;
        }
      }
    }
    // append string to file
    ofs << nucleoStr << "\n";
  }
}
