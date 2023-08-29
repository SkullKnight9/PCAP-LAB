#include "mpi.h"
#include<stdio.h>

int main (int argc, char *argv[]){

	int rank,size;
    int i;
    char str[5];
	MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Status status;
    if(rank==0){
    	printf("Enter Desired String\n");
    	gets(str);
    	MPI_Ssend(&str,5,MPI_CHAR,1,1,MPI_COMM_WORLD);
    	printf("%s has been sent from process 0\n",str);
        MPI_Recv(&str,5,MPI_CHAR,1,0,MPI_COMM_WORLD,&status);
        printf("The Altered String is: %s \n",str);
        //printf("%s \n",str);
    }
    else{
    	MPI_Recv(&str,5,MPI_CHAR,0,1,MPI_COMM_WORLD,&status);
        for(i=0;i<5;i++){

              if(str[i] >= 'A' && str[i] <= 'Z') 
              str[i] = str[i] + 32; 
              
              
              else if(str[i] >= 'a' && str[i] <= 'z')
              str[i] = str[i] - 32;
        }

        printf("%s has been changed and sent back to 1\n", str);
        MPI_Ssend(&str,5,MPI_CHAR,0,0,MPI_COMM_WORLD);
    }

    MPI_Finalize();
}