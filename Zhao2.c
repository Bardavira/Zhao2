#include <stdio.h>
#include <stdlib.h>

void readArray (int *array, int tamAr){
  /*Read a user defined array*/
  int i;
  for (i = 0; i < tamAr; i++){
    scanf("%d", &array[i]);
  }
}

void problem2 (){
  /*Calls readArray two times, using user given parameters, and makes the intersection between them, checking for each element in the first if it occurs in the second and if it already exists in the intersection array*/
  printf ("Please insert how many numbers will array 'n' and 'm' contain:\n");
  int tamN, tamM,i;
  scanf ("%d", &tamN);
  scanf ("%d", &tamM);
  int *arrayN = (int *) malloc (tamN * sizeof (int)), *arrayM = (int *) malloc (tamM * sizeof (int));
  printf ("Please insert all the %d values for the first array:\n", tamN);
  readArray (arrayN, tamN);
  printf ("as well as the other %d numbers of the second array:\n", tamM);
  readArray (arrayM, tamM);
  /*Defines the size of the intersection array to be the size of the smallest set of the given two*/
  int tamDef = (tamN > tamM)? tamM: tamN;
  int *arrayDef = malloc (tamDef * sizeof(int));
  int j, k, found, count = 0;
  for(i=0; i< tamN; i++){
    for(j=0; j< tamM; j++){
      if(arrayN[i] == arrayM[j]){
        /*Checks if the indexed number in the first set is present in the second one*/
        found = 0;
        for(k=0; k< count; k++){
          if(arrayDef[k] == arrayN[i]){
            /*Breaks the loop if the current indexed number already exists in the intersection array*/
            found = 1;
            break;
          }
        }
        if(found == 0){
          /*Appends the checked value, if it's not found in the intersection array*/
          arrayDef[count] = arrayN[i];
          count++;
        }
      }
    }
  }
  printf ("The intersecton array is I = [");
  for (k = 0; k < count-1; k++){
    /*Prints all the numbers in the intersection array, except for the last one (for aesthetical purposes)*/
    printf("%d, ", arrayDef[k]);
  }
  /*Prints the last one*/
  printf("%d]\n",arrayDef[count-1]);
  free(arrayN);
  free(arrayM);
  free(arrayDef); 
}

int findSubstring (char *strA, char *strB, int A, int B){
  /*Compares for each letter of the string if the given substring is equal to the same sized patch starting on the letter, stops when found, returns the letter index if found and -1 if not*/
  int i, j = 0;
  for (i = 0; i < A; i++){
    if (*(strA+i) == *(strB+j)){
      j++;
      if (j == B){
        return (i-j+1);
      }
    }
    else {
      j = 0;
    }
  }
  return -1;
}

void problem1 (){
  /*Reads the two strings and calls findSubstring, then prints if the substring is found (and the position on the sting) or if its not found, printing 0*/
  int tamA, tamB, solution;
  printf ("Please insert the string length for the one that'll be read:\n");
  scanf ("%d", &tamA);
  printf ("and the length of the substring that shall be found:\n");
  scanf ("%d", &tamB);
  char stringA[tamA], stringB[tamB];
  printf ("insert string:\n");
  scanf ("%s", stringA);
  printf ("insert substring:\n");
  scanf ("%s", stringB);
  solution = findSubstring (stringA, stringB, tamA, tamB);
  if (solution == -1){
    printf ("0, substring not found\n");
  } else {
    printf ("The first position of the substring in the string is %d (counting from 1)\n", solution+1);
  }
  
}

void main (){
  /*Main function, in which the code runs, it prints out a menu that gives the user 2 options, if the inserted value is not 1 nor 2, it ends the code and asks for a reboot*/
  printf ("Welcome!!\n");
  printf ("Select the problem intended to solve:\n");
  printf ("Substring:1\n");
  printf ("Intersection:2\n");
  int opt;
  scanf("%d", &opt);
  switch (opt){
    case(1): problem1 (); break;
    case(2): problem2 (); break;
    default: printf ("That's not allowed, please reboot the program");
  }
}