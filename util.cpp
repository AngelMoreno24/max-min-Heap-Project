//Name: Angel Moreno
//ASU ID: 1219993034

#ifndef DEFNS
#define DEFNS
#include "util.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;


void read(int* ADT, int* n){
  FILE *file= fopen("HEAPifile.txt", "r");

  if(file == NULL) {
    cout << "Error: Cannot open file HEAPifile.txt\n" << endl;
    exit (1);
  }

  if(!file){
    cout << "Error: Cannot open file HEAPifile.txt\n" << endl;
    exit (1);
  }

  int c;
  fscanf(file, "%d", &c);

  *n =c;

  fclose(file);
}

void readArray(util A[]){
  FILE *file= fopen("HEAPifile.txt", "r");

  int n;
  fscanf(file, "%d", &n);
  for(int j=0; j<n;j++){
    fscanf(file, "%d", &A[j].array);
 
  }
  
  fclose(file);
}

