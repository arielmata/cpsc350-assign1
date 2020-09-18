/*
Full name: Ariel Gutierrez
Student ID: 2318163
Chapman email: arigutierrez@chapman.edu
Course number and section: CPSC 350-01
Assignment or exercise number: Assignment 1

Assignment 1: A simple analysis program that will compute basics stastics for a
list of DNA strings.
*/
#include <iostream> // input and output
#include <fstream> // read and open files

using namespace std;

class DnaProcessor{
  public:
    DnaProcessor();
    ~DnaProcessor();

    void statistics(string fileName, ofstream& ofs);
    void nucleotideProbability(string fileName, ofstream& ofs);
    void bigramProbability(string fileName, ofstream& ofs);
    void gaussianDistribution(ofstream& ofs);
  private:
    int sum;
    double mean;
    double var;
    double standardDev;
    double probA;
    double probC;
    double probT;
    double probG;
};
