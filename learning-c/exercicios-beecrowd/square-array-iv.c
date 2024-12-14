#include <stdio.h>
#include <stdlib.h>

int main(){
    //1 - Get the test-cases and store in a array os the mtx sizes
    int *sizes = (int*)malloc(sizeof(int));
    int mtxSize;
    int counter = 1;

    //While the scanf returns is != -1 (EOF is a constant)
    int status = scanf("%d", &mtxSize);
    while(status != EOF){
        //Stores mtxSize at the end of the sizes vector
        sizes[counter - 1] = mtxSize;

        //Get the next mtx size
        status = scanf("%d", &mtxSize);

        //Checking for EOF
        if (status != EOF) {
            //Updates counter
            counter ++;
            //Realloc the sizes vector (1+ space)
            int *temp_sizes = (int*)realloc(sizes, counter * sizeof(int));
            sizes = temp_sizes;
        }
    }

    //2 - Draw the matrix's using the test-cases array info
    for (int i = 0; i < counter; i++) {
        //Get the size from the array
        mtxSize = sizes[i];

        //Create the mtx of sizes[i]xsizes[x]
        int **mtx = (int**)malloc(mtxSize * sizeof(int**));
        for (int j = 0; j < mtxSize; j++) {
            mtx[j] = (int*)malloc(mtxSize * sizeof(int));
        }

        //Fill the mtx with zero's
        for (int i = 0; i < mtxSize; i++) {
            for (int j = 0; j < mtxSize; j++) {
                mtx[i][j] = 0;
            }
        }

        //Fill the main diagonal with 2's
        for (int i = 0; i < mtxSize; i++) {
            mtx[i][i] = 2;
        }

        //Fill the secondary diagonal with 3's
        for (int i = 0; i < mtxSize; i++) {
            mtx[i][(mtxSize - 1) - i] = 3;
        }

        //Fill the mtx core with 1's
            //Calculate the first 1 location (left-up position)
            int pos1mtx = mtxSize / 3;
            //Calculate the 1's matrix dimension 
            int dim1mtx = mtxSize - (2 * pos1mtx);
            //Fill the original mtx core with 1's
            for (int i = pos1mtx; i < (pos1mtx + dim1mtx); i++) {
                for (int j = pos1mtx; j < (pos1mtx + dim1mtx); j++) {
                    mtx[i][j] = 1;
                }
            }
        
        //Place a 4 in the center of the mtx
            //Calculate the position (mtxSize / 2) + 1
            int center = (mtxSize / 2);
            //Place the 1
            mtx[center][center] = 4;

        //Show the mtx line-by-line without spaces
        for (int i = 0; i < mtxSize; i++) {
            for (int j = 0; j < mtxSize; j++) {
                if (j == (mtxSize - 1)) {
                    printf("%d\n", mtx[i][j]);
                }else{
                    printf("%d", mtx[i][j]);
                }
            }
        }
        printf("\n");
    }


    return 0;
}