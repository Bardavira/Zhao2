#include <stdio.h>
#include <stdlib.h>

void readArray (int *array, int tamAr){
  int i;
  for (i = 0; i < tamAr; i++){
    scanf("%d", &array[i]);
  }
}

void problem2 (){
  printf ("Please insert how many numbers will array 'n' and 'm' contain:\n");
  int tamN, tamM,i;
  scanf ("%d", &tamN);
  scanf ("%d", &tamM);
  int *arrayN = (int *) malloc (tamN * sizeof (int)), *arrayM = (int *) malloc (tamM * sizeof (int));
  printf ("Please insert all the %d values for the first array:\n", tamN);
  readArray (arrayN, tamN);
  printf ("as well as the other %d numbers of the second array:\n", tamM);
  readArray (arrayM, tamM);
  int tamDef = (tamN > tamM)? tamM: tamN;
  int *arrayDef = malloc (tamDef * sizeof(int));
  int j, k, found, count = 0;
  for(i=0; i< tamN; i++){
    for(j=0; j< tamM; j++){
      if(arrayN[i] == arrayM[j]){
        found = 0;
        for(k=0; k< count; k++){
          if(arrayDef[k] == arrayN[i]){
            found = 1;
            break;
          }
        }
        if(found == 0){
          arrayDef[count] = arrayN[i];
          count++;
        }
      }
    }
  }
  printf ("The intersecton array is I = [");
  for (k = 0; k < count-1; k++){
    printf("%d, ", arrayDef[k]);
  }
  printf("%d]\n",arrayDef[count-1]);
  free(arrayN);
  free(arrayM);
  free(arrayDef); 
}

int findSubString (char *strA, char *strB, int A, int B){
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
  solution = findSubString (stringA, stringB, tamA, tamB);
  if (solution == -1){
    printf ("0, substring not found\n");
  } else {
    printf ("The first position of the substring in the string is %d (counting from 0)\n", solution);
  }
  
}

void main (){
  printf ("Wellcome!!\n");
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