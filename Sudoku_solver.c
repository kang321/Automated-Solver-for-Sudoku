#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
const int row = 9;
const int col = 9;


void print(int[][9]); //printing the sodoku board
int find_empty(int[][9], int *, int *); //finding empty positions
int valid(int [][9],int,int,int); //to check if num inserted is valid
int solve(int[][9]); //SOlving board using backtracking

int main() {
    int arr[9][9] = {
                        {7,8,0,4,0,0,1,2,0},
                        {6,0,0,0,7,5,0,0,9},
                        {0,0,0,6,0,1,0,7,8},
                        {0,0,7,0,4,0,2,6,0},
                        {0,0,1,0,5,0,9,3,0},
                        {9,0,4,0,6,0,0,0,5},
                        {0,7,0,3,0,0,0,1,2},
                        {1,2,0,0,0,7,4,0,0},
                        {0,4,9,2,0,6,0,0,7}
    };
    int prow=0; 
    int pcol=0;
    
    print(arr);   //printing the sudoku
    printf("\n\n");   
      
    if(solve(arr)){
        printf("* * * * * * * SOLUTION BELOW * * * * * *\n\n");
        print(arr);

    }
    else{
        printf("No solution Exists");
    }    
    // print(arr);
    // int a = ;
    return 0;
}
void print(int arr[][9]){
    for(int i = 0;i<row;i++){
        if(i%3==0 && i!=0){
            printf("\n----------------------\n");
        }
        for(int j=0; j<col; j++){
            if(j%3==0 && j!=0){
                printf("|");
                printf(" ");
            }
            printf("%d",arr[i][j]);
            printf(" ");
        }       
        printf("\n");       
    }
    // printf("%d %d", prow,pcol);
}

int find_empty(int arr[][9], int *prow, int *pcol){
    for(int i = 0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==0){
                *prow = i; //using pointers to get position of empty row
                *pcol = j; //using pointers to get position of empty col
                return 1;
            }
        }
    }
    return 0;
    
}

int valid(int arr[][9],int prow, int pcol, int num){    
    //Checking Row
    for(int i=0; i<9; i++){
        if((num==arr[prow][i]) && pcol!=i){           
            return 0;
        }
    }      
    //Checking Col
    for(int i=0;i<9;i++){
        if((num==arr[i][pcol]) && prow!=i){
            return 0;
        }
    }    
    //Checking 3x3 grid
    int box_x = pcol/3;
    int box_y = prow/3;   
    for(int i=(box_y *3); i<((box_y*3) +3); i++){
        for(int j = (box_x*3); j<((box_x*3+3)); j++){            
            if((arr[i][j]==num) && (prow != i) && (pcol !=j)){
                return 0;                
            }
        }
    }    
    return 1;    
}

int solve(int arr[][9]){
    int prow; //declaring prow and pcol for find empty function
    int pcol;    
    // printf("%d %d",*prow, *pcol);
    if(!find_empty(arr,&prow,&pcol)){ //finding empty positions
        return 1;
    }
    for(int i=1; i<10;i++){
        if(valid(arr,prow,pcol,i)){ //checking given i is valid 
            arr[prow][pcol] = i;        
        
        if(solve(arr)==1){  //sudoku solved
            return 1;}        
        arr[prow][pcol] = 0 ; //backtracking
        // print(arr);             
        } 
    }
    return 0;
}
