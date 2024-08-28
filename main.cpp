//Name: Angel Moreno
//ASU ID: 1219993034

#include "util.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;

int main(int argc, char *argv[]){  

  if (argc < 3){
    cout << "Usage: ./PJ2 DataStructure Capacity" << endl;
    cout << "       DataStructure should be in {MaxHeap, MinHeap, DoubleHeap}" << endl;
    cout << "       Capacity must be a positive integer" << endl;
    exit (1);
  }

  string arg =std::string(argv[1]);
  int arg2 =std::atoi(argv[2]);
  int ADT;

  if(arg == "MaxHeap" || arg=="MinHeap" ||arg =="DoubleHeap"){
    if(arg == "MaxHeap")
      ADT=1;
  
    if(arg == "MinHeap")
      ADT=2;

    if(arg == "DoubleHeap"){
      ADT=3;
   
    }
  }else{
    cout << "Usage: ./PJ2 DataStructure Capacity" << endl;
    cout << "       DataStructure should be in {MaxHeap, MinHeap, DoubleHeap}" << endl;
    cout << "       Capacity must be a positive integer" << endl;

    return 0;
  }

  //--------------------------------------------------------------
    
  util * b = new util[arg2];
  TAG_ELEMENT * arr = new TAG_ELEMENT[arg2];

  arr[0].capacity = arg2;
  arr[0].size=0;

  char word[50];
  int value, pos;
  while (1){
    scanf("%s", word);

    //--------------------------------------------------------------
    if (strcmp(word, "Read")==0){
      int n;
      read(&ADT, &n);

      if(arr[0].capacity > n || arr[0].capacity ==NULL){
	b[0].ADT= ADT;
	readArray(b);
	
	for(int i =0;i<n;i++){
	  arr[i].key = b[i].array;
	  arr[i].min = b[i].array;
	
	}
	arr[0].size= n;
	arr[0].minSize= n;
	
	//----------------
	
	if(ADT == 1 || ADT == 3){
	  BuildMaxHeap(arr);

	  if(ADT == 1)
	    arr[0].minSize = 0;
	}
	if(ADT == 2 || ADT == 3){
	  BuildMinHeap(arr);
   
	  if(ADT == 2)
	    arr[0].size = 0;
	}  
      }else{
	if(ADT == 1){
	  fprintf(stderr, "Error: Cannot allocate memory for max heap array\n");
	}
	if(ADT == 2){
	  fprintf(stderr, "Error: Cannot allocate memory for min heap array\n");
        }
	if(ADT == 3){
	  fprintf(stderr, "Error: Cannot allocate memory for heap\n");
        }

      }
      //--------------------------------------------------------------    
    }else if(strcmp(word, "Write")==0){
      write(arr, ADT);
      
      //--------------------------------------------------------------
    }else if(strcmp(word, "Insert")==0){
      int iVal;
      scanf("%d", &iVal);
      if(iVal >= 0 && iVal <= arr[0].capacity){
	Insert(arr, iVal, ADT);
      }else{	
	fprintf(stderr, "Error: Invalid command\n");
      }
      //--------------------------------------------------------------
    }else if(strcmp(word, "Print")==0){
      print(arr, ADT);
      //--------------------------------------------------------------
    }else if(strcmp(word, "Stop")==0){
      return 0;
      //--------------------------------------------------------------
    }else if(strcmp(word, "ExtractMax")==0){
      if(ADT == 1 || ADT == 3){
      ExtractMax(arr, ADT);
      //print(arr, ADT);
      }else{
        fprintf(stderr, "Error: ExtractMax in a min heap or a null/empty heap\n");
      }
      //--------------------------------------------------------------
    }else if(strcmp(word, "ExtractMin")==0){
      if(ADT == 2 || ADT == 3){
      ExtractMin(arr, ADT);

      }else{
	fprintf(stderr, "Error: ExtractMin in a max heap or a null/empty heap\n");
      }
      //--------------------------------------------------------------
    }else if(strcmp(word, "IncreaseKey")==0){
      if(ADT == 1 || ADT == 3){

	scanf("%d", &pos);
	scanf("%d", &value);

	if(pos-1 < arr[0].size && pos-1 >= 0 && value > arr[pos-1].key){
	  IncreaseKey(arr, pos-1, value, ADT);

	}else{
	  fprintf(stderr, "Error: Invalid position or newKey in IncreaseKey\n");
	}
      }else{
        fprintf(stderr, "Error: IncreaseKey in a min heap or a null/empty heap\n");
      }
      //--------------------------------------------------------------
    }else if(strcmp(word, "DecreaseKey")==0){
      if(ADT == 2 || ADT == 3 || arr[0].minSize == 0){

        scanf("%d", &pos);
        scanf("%d", &value);
        if(pos < arr[0].size && pos >= 0 && value < arr[pos].key){
          DecreaseKey(arr, pos-1, value, ADT);
        }else{
          fprintf(stderr, "Error: Invalid position or newKey in DecreaseKey\n");
        }
      }else{
        fprintf(stderr, "Error: DecreaseKey in a max heap or a null/empty heap\n");
      }
    }
  }
  return 0;

}

