/*
Full name: Ariel Gutierrez
Student ID: 2318163
Chapman email: arigutierrez@chapman.edu
Course number and section: CPSC 350-01
Assignment or exercise number: Assignment 1

Assignment 1: A simple analysis program that will compute basics statistics for
a list of DNA strings.
*/

#include <iostream> //input and output
#include <fstream> //read and open files
#include <math.h> //pow, sqrt, M_PI, log
#include <stdlib.h> //rand, RAND_MAX
#include <algorithm> //transform
using namespace std;

//The DnaProcessor class includes a simple analysis program that will compute
//basic statistics, which include sum, mean, variance, and standard deviation
//of the length of the DNA strings in the list. Moreover, DnaProcessor computes
//the probability of each nucleotide and each nucleotide bigram. Then, it
//generates 1000 DNA strings whose lengths follow a Gaussian distribution.
class DnaProcessor{
  public:
    //Default constructor
    DnaProcessor();
    //Destructor
    ~DnaProcessor();

    //Computes and outputs the statistics (sum, mean, variance, and standard
    //deviation) of the length of the DNA strings to a file ArielGutierrez.out
    void statistics(string fileName, ofstream& ofs);
    //Computes and outputs the probability of each nucleotide to the file
    //ArielGutierrez.out
    void nucleotideProbability(string fileName, ofstream& ofs);
    //Computes and outputs the probabilty of each nucleotide bigram to the file
    //ArielGutierrez.out
    void bigramProbability(string fileName, ofstream& ofs);
    //Generates and appends 1000 DNA strings whose lengths follow a Gaussian
    //distrubution to the file ArielGutierrez.out
    void gaussianDistribution(ofstream& ofs);
  private:
    //sum of all the nucleotides
    int sum;
    //mean length of the DNA strings
    double mean;
    //variance of the length of the DNA strings
    double var;
    //standard deviation of the length of the DNA strings
    double standardDev;
    //probability of nucleotide A
    double probA;
    //probability of nucleotide C
    double probC;
    //probability of nucleotide T
    double probT;
    //probability of nucleotide G
    double probG;
};
