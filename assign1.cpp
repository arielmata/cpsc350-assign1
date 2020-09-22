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

//Default Constructor: sets sum to 0, and sets mean, var, standardDev,
//probA, probC, probT, and probG to 0.0.
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

//Destructor: Wishes a farewell to the user
DnaProcessor::~DnaProcessor(){
  cout << "Farewell!" << endl;
}

//Computes the sum, mean, variance, and standard deviation of the length of
//the DNA strings in the list, and adds information to ArielGutierrez.out
void DnaProcessor::statistics(string fileName, ofstream& ofs){
  int count = 0;
  string line;
  double numerator = 0.0;

  ifstream infile;
  infile.open(fileName);
  while(getline(infile, line)){
    line.erase(line.length()-1); //delete new line character
    sum += line.length();
    ++count;
  }
  mean = sum/count;
  infile.close();

  infile.open(fileName);
  while(getline(infile, line)){
    line.erase(line.length()-1); //delete new line character
    numerator += pow((line.length() - mean),2);
  }
  infile.close();
  var = numerator/(sum-1);
  standardDev = sqrt(var);

  ofs << "The Sum of the length of the DNA strings: " << sum << endl;
  ofs << "The Mean of the length of the DNA strings: " << mean << endl;
  ofs << "The Variance of the length of the DNA strings: " << var << endl;
  ofs << "The Standard Deviation of the length of the DNA stings: " <<
    standardDev << endl;
  ofs << endl;
  ofs << endl;
}

//Computes the relative probability of each nucleotide (A,C,T, or G) and
//outputs them to file ArielGutierrez.out
void DnaProcessor::nucleotideProbability(string fileName, ofstream& ofs){
  string line;
  int countA = 0, countC = 0, countT = 0, countG = 0;

  ifstream infile;
  infile.open(fileName);
  while(getline(infile, line)){
    line.erase(line.length()-1); //delete new line char
    for (int i = 0; i < line.length(); ++i){
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

  probA = (double)countA/sum;
  probC = (double)countC/sum;
  probT = (double)countT/sum;
  probG = (double)countG/sum;

  ofs << "Here is the relative probability of each nucleotide:\n";
  ofs << endl;
  ofs << "A:     " << probA << endl;
  ofs << "G:     " << probG << endl;
  ofs << "T:     " << probT << endl;
  ofs << "C:     " << probC << endl;
  ofs << endl;
}

//Computes the relative probability of each nucleotide bigram
//(AA, CC, TT, GG, AC, AT, AG, CA, CT, CG, TA, TC, TG, GA, GC, GT)
//and outputs the result into given output file.
void DnaProcessor::bigramProbability(string fileName, ofstream& ofs){
  int countAA = 0, countCA = 0, countTA = 0, countGA = 0;
  int countAC = 0, countCC = 0, countTC = 0, countGC = 0;
  int countAT = 0, countCT = 0, countTT = 0, countGT = 0;
  int countAG = 0, countCG = 0, countTG = 0, countGG = 0;
  int bigramCount = 0;;
  string line, compare;

  ifstream infile;
  infile.open(fileName);
  while(getline(infile, line)){
    line.erase(line.length()-1);
    if(line.length()%2 == 1){
      //if odd, add first nucleotide to end of string
      line += line[0];
    }
    bigramCount += line.length()/2;
    //converting string to lowercase
    for(int j = 0; j < line.length(); ++j){
      line[j] = tolower(line[j]);
    }
    for(int i = 0; i < line.length()/2; ++i){
      compare = line.substr(i*2,2);
      if(compare == "aa"){
        ++countAA;
      } else if(compare == "ca"){
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

  ofs << "Here is the relative probability of each nucleotide bigram:" << endl;
  ofs << "AA:     " << (double)countAA/bigramCount << endl;
  ofs << "AC:     " << (double)countAC/bigramCount << endl;
  ofs << "AT:     " << (double)countAT/bigramCount << endl;
  ofs << "AG:     " << (double)countAG/bigramCount << endl;
  ofs << "CA:     " << (double)countCA/bigramCount << endl;
  ofs << "CC:     " << (double)countCC/bigramCount << endl;
  ofs << "CT:     " << (double)countCT/bigramCount << endl;
  ofs << "CG:     " << (double)countCG/bigramCount << endl;
  ofs << "TA:     " << (double)countTA/bigramCount << endl;
  ofs << "TC:     " << (double)countTC/bigramCount << endl;
  ofs << "TT:     " << (double)countTT/bigramCount << endl;
  ofs << "TG:     " << (double)countTG/bigramCount << endl;
  ofs << "GA:     " << (double)countGA/bigramCount << endl;
  ofs << "GC:     " << (double)countGC/bigramCount << endl;
  ofs << "GT:     " << (double)countGT/bigramCount << endl;
  ofs << "GG:     " << (double)countGG/bigramCount << endl;
  ofs <<  endl;
  ofs <<  endl;
}

//Generate 1000 DNA strings whose lengths follow a Gaussian distribution, and
//it appends it to the output file, ArielGutierrez.out
void DnaProcessor::gaussianDistribution(ofstream& ofs){
  double a, b, C, D, num;
  string nucleoStr;
  double minProb = probA;

  //applying gaussian distribution to generate 1000 DNA strings
  for(int i = 0; i < 1000; ++i){
    a = (double)rand()/RAND_MAX;
    b = (double)rand()/RAND_MAX;
    C = sqrt(-2*log(a))*cos(2*M_PI*b);
    D = standardDev*C + mean;
    nucleoStr = "";

    for(int j = 0; j < D; ++j){
      num = (double)rand()/RAND_MAX; //make a percentage
        if(num <= probA){
          nucleoStr += "A";
        } else if(num <= probT + probA){
          nucleoStr += "C";
        } else if(num <= probC + probT + probA){
          nucleoStr += "T";
        } else{
          nucleoStr += "G";
        }
    }
    //append string to ArielGutierrez.out
    ofs << nucleoStr << endl;
  }
}
