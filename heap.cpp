//Name: Angel Moreno
//ASU ID: 1219993034

#ifndef DEFNS
#define DEFNS
#include "heap.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h>

using namespace std;


void print(TAG_ELEMENT t[], int ADT){
  int last;
  if(ADT == 1){
    printf("capacity=%d, size=%d\n", t[0].capacity, t[0].size);

    if(t[0].size-1>0){
      cout << "MaxHeap: ";
      for(int i=0;i<(t[0].size-1);i++){ 
	cout << t[i].key << ", ";
      }
      last = t[0].size-1;

      cout << t[last].key << endl;
    }
  }
  if(ADT == 2){
    printf("capacity=%d, size=%d\n", t[0].capacity, t[0].minSize);


    if(t[0].minSize-1>0){
      cout << "MinHeap: ";
      for(int i=0;i<(t[0].minSize-1);i++){
	cout << t[i].min << ", ";
      }
      last = t[0].minSize-1;
      cout << t[last].min << endl;
      
    }
  }if(ADT == 3){
    printf("capacity=%d, size=%d\n", t[0].capacity, t[0].size);
    if(t[0].size-1>0){
      cout << "MaxHeap: ";
      for(int i=0;i<(t[0].size-1);i++){
        cout << t[i].key << ", ";
      }
      last = t[0].size-1;

      cout << t[last].key << endl;

    }
    if(t[0].minSize-1>0){
      cout << "MinHeap: ";
      for(int i=0;i<(t[0].minSize-1);i++){
        cout << t[i].min << ", ";
      }
      last = t[0].minSize-1;
      cout << t[last].min << endl;

    }
  }   
}
void printMin(TAG_ELEMENT t[]){

  cout << "MinHeap: ";
  for(int i=0;i<(t[0].minSize-1);i++){
    cout << t[i].min << ", ";
  }
  int last;
  last = t[0].minSize-1;
  cout << t[last].min << endl;

}

void exchange(TAG_ELEMENT t[], int i, int largest){
  int tmp = t[i].key;
  t[i].key = t[largest].key;
  t[largest].key = tmp;  
}

void exchangeMin(TAG_ELEMENT t[], int i, int largest){
  int tmp = t[i].min;
  t[i].min = t[largest].min;
  t[largest].min = tmp;
}

void MaxHeapify(TAG_ELEMENT t[], int i){  
    int largest;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l < t[0].size && t[l].key > t[i].key){
      largest = l;

    }else{
      largest = i;

    }
    if(r < t[0].size && t[r].key > t[largest].key){
      largest = r;

    }
    if(largest != i){
      exchange(t, i, largest);
      MaxHeapify(t, largest);
      
    }
}

void BuildMaxHeap(TAG_ELEMENT t[]){  
  int size = (floor(t[0].size/2-1));

  for(int i=size;i>=0;i--){
    MaxHeapify(t,i);
  }

}

void MinHeapify(TAG_ELEMENT t[], int i){

  int largest;
  int l = 2*i+1;
  int r = 2*i+2;

  if(l < t[0].minSize && t[l].min < t[i].min){
    largest = l;
  }else{
    largest = i;
  }

  if(r < t[0].minSize && t[r].min < t[largest].min){
    largest = r;
  }
  if(largest != i){

    exchangeMin(t, i, largest);
    MinHeapify(t, largest);

  }
}

void BuildMinHeap(TAG_ELEMENT t[]){

  int size = (floor(t[0].minSize/2-1));

  for(int i=size;i>=0;i--){
    MinHeapify(t,i);
  }

}

void DecreaseKey(TAG_ELEMENT t[], int pos, int  newKey, int ADT){
  int key = t[pos].min;
  if ((pos != NULL) && (t[pos].min > newKey)){
    t[pos].min = newKey;
    BuildMinHeap(t);
  }
  if(ADT == 3){
    for(int i =0;i<t[0].size;i++){
   
      if(t[i].key == key){
        t[i].key = newKey;
        break;
      }
    }
    BuildMaxHeap(t);
  }
}  

void IncreaseKey(TAG_ELEMENT t[], int pos, int  newKey, int ADT){
  int key = t[pos].key;

  if ((pos != NULL) && (t[pos].key < newKey)){
    t[pos].key = newKey;
    BuildMaxHeap(t);
  }

  if(ADT == 3){
    for(int i =0;i<t[0].minSize;i++){
      if(t[i].min== key){
	t[i].min = newKey;
	break;
      }
    }
    BuildMinHeap(t);
  }
}

int Delete(TAG_ELEMENT t[], int pos, int ADT){
  if(ADT == 1 || ADT == 3){
    if(pos < t[0].key){
      int element = t[pos].key;
      int last = t[0].size-1;
      t[pos].key = t[t[0].size-1].key;
      t[0].size = t[0].size-1;

      if(pos > 1 && pos < t[0].size && t[pos].key > t[pos/2].key){
	while(pos > 1 && t[pos].key > t[pos/2].key ){
	  
	  exchange(t, pos, (pos/2));
	  pos = pos/2;
	}
      }else{
	BuildMaxHeap(t);
      }
      return element;
    }
  }
}

int DeleteMin(TAG_ELEMENT t[], int pos, int ADT){
  if(ADT == 2 || ADT == 3){

    if(pos < t[0].minSize ){
      int element = t[pos].min;
      int last = t[0].minSize-1;
      t[pos].min = t[t[0].minSize-1].min;
      t[0].minSize = t[0].minSize-1;

      if(pos > 1 && pos < t[0].minSize && t[pos].min > t[pos/2].min){
        while(pos > 1 && t[pos].min > t[pos/2].min ){

          exchangeMin(t, pos, (pos/2));
          pos = pos/2;
        }
      }else{
        BuildMinHeap(t);

      }
      return element;
    }
  }
}



void ExtractMax(TAG_ELEMENT t[], int ADT){
  int element;
  if(t[0].size < 1){

    cout << "error: heap empty" << endl;
  }else{
    element =  Delete(t, 0, ADT);
    cout << "ExtractMax: " << element << endl;

  }

  if(ADT == 3){       
    for(int i =0;i<t[0].minSize;i++){
      if(t[i].min==element){
      int e = DeleteMin(t, i, ADT);

      break;
      }
    }
    BuildMinHeap(t);

  }
}

void ExtractMin(TAG_ELEMENT t[], int ADT){
  int element;
  if(t[0].minSize < 1){
    cout << "error: heap empty" << endl;

  }else{
    element =  DeleteMin(t, 0, ADT);
    cout << "ExtractMin: " << element << endl;
  }
  if(ADT == 3){
    for(int i =0;i<t[0].size;i++){
      if(t[i].key == element){
        Delete(t, i, ADT);
      }
    }
    BuildMaxHeap(t);
  }

}
void Insert(TAG_ELEMENT t[], int key, int ADT){

  if(ADT == 1 || ADT == 3){
  t[0].size = t[0].size+1;
  t[t[0].size-1].key = key;
  BuildMaxHeap(t);
  }
  if(ADT == 2 || ADT == 3){
    t[0].minSize = t[0].minSize+1;
    t[t[0].minSize-1].min = key;
    BuildMinHeap(t);
  }
}



void write(TAG_ELEMENT t[], int ADT){

  ofstream file;
  file.open("HEAPofile.txt");  

  int c;
  int last;

  if(ADT == 1){

    file << "capacity=" <<t[0].capacity << ", " << "size=" << t[0].size << endl;
    file << "MaxHeap: ";
    
    for(int i=0;i<(t[0].size-1);i++){
      file << t[i].key << ", ";
    }
    last = t[0].size-1;
    file << t[last].key << endl;
  }    
  //--------------------------------------------------------------------------------
  if(ADT == 2){
    file << "capacity=" <<t[0].capacity << ", " << "size=" << t[0].minSize << endl;
    file << "MinHeap: ";

    for(int i=0;i<(t[0].minSize-1);i++){
      file << t[i].min << ", ";
    }
 
    last = t[0].minSize-1;
    file << t[last].min << endl;
  }
  //--------------------------------------------------------------------------------
  if(ADT == 3){
    file << "capacity=" <<t[0].capacity << ", " << "size=" << t[0].minSize << endl;

    file << "MaxHeap: ";

    for(int i=0;i<(t[0].size-1);i++){
      file << t[i].key << ", ";
    }
    last = t[0].size-1;
    file << t[last].key << endl;

    file << "MinHeap: ";

    for(int i=0;i<(t[0].minSize-1);i++){
      file << t[i].min << ", ";
    }
    last = t[0].minSize-1;
    file << t[last].min << endl;
  }
  file.close(); 
}
