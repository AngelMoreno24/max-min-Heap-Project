//Name: Angel Moreno
//ASU ID: 1219993034


typedef struct TAG_ELEMENT{
  int min;
  int key;
  TAG_ELEMENT * next = nullptr;
  int size;
  int minSize;
  int capacity;

}ELEMENT;

void print(TAG_ELEMENT t[], int ADT);
void printMin(TAG_ELEMENT t[]);

void MaxHeapify(TAG_ELEMENT t[], int i);
void MinHeapify(TAG_ELEMENT t[], int i);

void BuildMaxHeap(TAG_ELEMENT t[]);
void BuildMinHeap(TAG_ELEMENT t[]);

void DecreaseKey(TAG_ELEMENT t[], int pos, int  newKey, int ADT);
void IncreaseKey(TAG_ELEMENT t[], int pos, int  newKey, int ADT);

void exchange(TAG_ELEMENT t[], int i, int largest);
void exchangeMin(TAG_ELEMENT t[], int i, int largest);

int Delete(TAG_ELEMENT t[], int pos, int ADT);
int DeleteMin(TAG_ELEMENT t[], int pos, int ADT);

void ExtractMax(TAG_ELEMENT t[], int ADT);
void ExtractMin(TAG_ELEMENT t[], int ADT);

void Insert(TAG_ELEMENT t[], int key, int ADT);
void write(TAG_ELEMENT t[], int ADT);
