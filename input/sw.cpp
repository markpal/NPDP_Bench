#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <omp.h>
#include <math.h>


#define min(a,b) (((a)<(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define ceild(n,d) ceil(((double)(n))/((double)(d)))
#define CHECK_VALID 0


int **H;
int **H1;
int **tmp_H;
int **m1;
int **m2;

int *W;
unsigned char *a;
unsigned char *b;


int N = 100, DIM = 102;

//Similarity score of the elements that constituted the two sequences
int s(unsigned char x, unsigned char z){
   return (x == z) ? 1 : -1;
}


#include "mem.h"
#include "sw_oryg.h"
#include "sw_pluto.h"
#include "sw_tstile.h"
#include "sw_traco.h"




int main(int argc, char *argv[]){

    int i,j,k;


    int num_proc=1;
    if(argc > 1)
        num_proc = atoi(argv[1]);

    int kind=1;

    if(argc > 2)
        N = atoi(argv[2]);
    DIM = 2*N+2;


    if(argc > 3)
        kind = atoi(argv[3]);

    // H is the scoring matrix
    H = mem();
    H1 = mem();
    m1 = mem();
    m2 = mem();

    W = (int*)malloc(DIM * sizeof(int));
    a = (unsigned char *)malloc(DIM * sizeof(unsigned char ));
    b = (unsigned char *)malloc(DIM * sizeof(unsigned char ));



    for(i=0; i<=N; i++){
        H[i][0] = 0;
        H[0][i] = 0;
        H1[i][0] = 0;
        H1[0][i] = 0;

    }


    // W is the gap alignment
    W[0] = 2;
    for(i=1; i<=N; i++)
        W[i] = i*W[0];

    rand_seq(a, N);
    rand_seq(b, N);



    omp_set_num_threads(num_proc);

    double start = omp_get_wtime();

    if(kind == 2)
        sw_pluto();

  

    if(kind == 3)
        sw_traco();


    if(kind == 4)
        sw_tstile();

    if(kind == 1 || CHECK_VALID)
    {    tmp_H = H;
        H = H1;
        sw_seq();
        H = tmp_H;

    if(CHECK_VALID)
     for(i=0; i<N; i++)
      for(j=0; j<N; j++)
       if(H[i][j] != H1[i][j]){
          printf("error!\n");
          exit(0);
      }

    }
    double stop = omp_get_wtime();
    printf("%.4f\n",stop - start);




return 0;
}
