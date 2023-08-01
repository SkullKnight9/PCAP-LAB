#include <mpi.h>
#include<stdio.h>

int Fibonacci(int n1){        
    if(n1<=1){    
         return 1; 
    }
    else{
    	return Fibonacci(n1-1) + Fibonacci(n1-2);
    }    
}

long Factorial(int n2)  
{  
  if (n2 == 0 || n2 == 1)  
    return 1;  
  else  
    return(n2 * Factorial(n2-1));  
}  



int main(int argc, char *argv[]){
	int rank, size;
	int a,b;


	MPI_Init (&argc, &argv);

	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	if(rank % 2 != 0){
		printf("Fibonacci of %d = %d\n",rank,b=Fibonacci(rank));
	}
	else{
		printf("Factorial of %d = %d\n",rank,a=Factorial(rank));
	}

	


	MPI_Finalize();
	return 0;


}