
#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    int number_process, process_rank, number, local_number,*data,recdata[100],recdata2[100];
    int  i = 0;
    int root_process = 0;

     MPI_Init(&argc, &argv);

     MPI_Comm_rank(MPI_COMM_WORLD, &process_rank);
     MPI_Comm_size(MPI_COMM_WORLD, &number_process);

    if(process_rank == root_process)
    {
        printf("Enter how many number that you are sorted..\n");

        scanf("%d", &number);

        int avgNumberPerProcess = number / number_process;
        local_number = avgNumberPerProcess;

        data = (int*)malloc(sizeof(int)*number);

        for(i = 0; i < number; i++)
        {
            //cout << data[i];
           // printf("%d", data[i]);
           scanf("%d", &data[i]);
        }

       // cout << endl;
       //printf("/n");

    }

    else
    {
        data = NULL;
    }

     MPI_Bcast(&local_number, 1, MPI_INT, 0, MPI_COMM_WORLD);
     MPI_Scatter(data, local_number,MPI_INT, &recdata, 100, MPI_INT, 0 , MPI_COMM_WORLD);


    // show data from every process that are come

    //   printf("%d:received data: ",process_rank);
    //      for(i=0;i<local_number;i++){
    //      	//cout << recdata[i] << " ";
    //          printf("%d ", recdata[i]);
    //      }
    // cout << endl;
    //printf("/n");

    // locally data sort 
     //sort(recdata,recdata+local_number);

     int rectmp = 0, j;

     for( i = 0; i < local_number; i++)
     {
         for( j = 0; j < local_number; j++)
         {
             if(recdata[i] < recdata[j] )
             {
                rectmp = recdata[i];
                recdata[i] = recdata[j];
                recdata[j] = rectmp;
             }
         }
     }

    //   printf("after local sort: \n");
    //   for(i = 0; i < local_number; i++)
    //   {
    //      printf("%d ", recdata[i]);
    //   }

    //   printf("\n");



    // begin the odd-even sort here
    int oddrank,evenrank;

    if(process_rank % 2 ==0)
    {
    	oddrank = process_rank - 1; 
    	evenrank = process_rank + 1;
	}
 	else {
 		oddrank = process_rank + 1;
 		evenrank = process_rank - 1;
	}

    /* Set the ranks of the processors at the end of the linear */
    // set process boundery 
    if (oddrank == -1 || oddrank == number_process)
    {
        oddrank = MPI_PROC_NULL;
    }

    if (evenrank == -1 || evenrank == number_process)
    {
        evenrank = MPI_PROC_NULL;
    }

    int process , *temp;

    MPI_Status status;


    for(process = 0; process < number_process ; process++)
    {
        // even phase
        if(process % 2 == 0)
        {
             MPI_Sendrecv(recdata, local_number, MPI_INT, evenrank, 1, recdata2,
             local_number, MPI_INT, evenrank, 1, MPI_COMM_WORLD, &status);
        }

        else
        {
            MPI_Sendrecv(recdata, local_number, MPI_INT, oddrank, 1, recdata2,
            local_number, MPI_INT, oddrank, 1, MPI_COMM_WORLD, &status);
        }

        //extract localn after sorting the two
        temp = (int*)malloc(local_number*sizeof(int));

         for(i=0;i<local_number;i++)
         {
 	        temp[i]=recdata[i];
         }


         if(status.MPI_SOURCE == MPI_PROC_NULL)	
         {
             continue;
         }

         else if(process_rank < status.MPI_SOURCE)
         {
            //store the smaller of the two
            int i = 0,j = 0,k = 0;
            for(i=j=k=0; k < local_number; k++)
            {
                if(j == local_number||(i< local_number && temp[i] < recdata2[j]))
                    recdata[k]=temp[i++];
                else
                    recdata[k]=recdata2[j++];
            }
         }
         else{
            //store the larger of the two
            int i,j,k;
            for(i=j=k= local_number-1;k>=0;k--)
            {
                if(j==-1||(i >= 0 && temp[i] >= recdata2[j]))
                    recdata[k]=temp[i--];
                else
                    recdata[k]=recdata2[j--];
            }
         }

    }


     MPI_Gather(recdata,local_number,MPI_INT,data,local_number,MPI_INT,0,MPI_COMM_WORLD);
        
        if(process_rank == root_process)
        {
            printf("sorted data:\n");
                    for( i=0; i < number; i++)
                    {
                       // cout << data[i] << " ";
                       printf("%d ", data[i]);
                    }
                //cout << endl;
                printf("\n");
                
        }



     MPI_Finalize();

     //printf("/n");


    return 0;
}
