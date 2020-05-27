

#include<stdio.h>
#include<math.h>

int board[70],count;
 
int main()
{
   int n,i,j;
   void queen(int row,int n);   //function declaration
   
   printf("-N queens problem Using Backtracking-");
   printf("\nEnter number of Queens:");
   scanf("%d",&n);
   queen(1,n);     //function call 
   printf("\ntotal number of solutions are:%d\n",count);
   return 0;
}
  
  //Function for printing the solution
void print(int n)
{
    int i,j;
    printf("\n solution %d:\n",++count);
  
    for(i=1;i<=n;i++)
    printf("\t%d",i);
    
    for(i=1;i<=n;i++)
    {
          printf("\n%d",i);
     
          for(j=1;j<=n;j++)            //for nxn board
          {
                if(board[i]==j)
                    printf("\tQ");    //Queen is present at i,j position
                else
                    printf("\t-");   //print empty slot empty slot
          }
    }
}
  
  /*Function to check conflicts
  If no conflict for desired position returns 1 otherwise returns 0 */
  
int place(int row,int column)
{
  int i;
  for(i=1;i<=row-1;i++)
  {
    //checking column and diagonal conflicts
    
    if(board[i]==column)
    return 0;        //their is conflict between queens
    else
    if(abs(board[i]-column)==abs(i-row))
    return 0;     //their is confilct between queens
  }
    return 1;   //No conflicts between queens
}
                                                                                                                                           
  
//Function to check for proper positioning of queen
  
void queen(int row,int n)
{
   int column;
   for(column=1;column<=n;column++)
   {
     if(place(row,column))
     {
         board[row]=column;   //No conflicts so place queen
         if(row==n)          //dead n (last row)
         print(n);          //printing the board configuration
         else              //try queen with next position
         queen(row+1,n);  //function call for trying queen with next row
     }
   }
}     

/*
OUTPUT:
-N queens problem Using Backtracking-
Enter number of Queens:5

 solution 1:
	1	2	3	4	5
1	Q	-	-	-	-
2	-	-	Q	-	-
3	-	-	-	-	Q
4	-	Q	-	-	-
5	-	-	-	Q	-
 solution 2:
	1	2	3	4	5
1	Q	-	-	-	-
2	-	-	-	Q	-
3	-	Q	-	-	-
4	-	-	-	-	Q
5	-	-	Q	-	-
 solution 3:
	1	2	3	4	5
1	-	Q	-	-	-
2	-	-	-	Q	-
3	Q	-	-	-	-
4	-	-	Q	-	-
5	-	-	-	-	Q
 solution 4:
	1	2	3	4	5
1	-	Q	-	-	-
2	-	-	-	-	Q
3	-	-	Q	-	-
4	Q	-	-	-	-
5	-	-	-	Q	-
 solution 5:
	1	2	3	4	5
1	-	-	Q	-	-
2	Q	-	-	-	-
3	-	-	-	Q	-
4	-	Q	-	-	-
5	-	-	-	-	Q
 solution 6:
	1	2	3	4	5
1	-	-	Q	-	-
2	-	-	-	-	Q
3	-	Q	-	-	-
4	-	-	-	Q	-
5	Q	-	-	-	-
 solution 7:
	1	2	3	4	5
1	-	-	-	Q	-
2	Q	-	-	-	-
3	-	-	Q	-	-
4	-	-	-	-	Q
5	-	Q	-	-	-
 solution 8:
	1	2	3	4	5
1	-	-	-	Q	-
2	-	Q	-	-	-
3	-	-	-	-	Q
4	-	-	Q	-	-
5	Q	-	-	-	-
 solution 9:
	1	2	3	4	5
1	-	-	-	-	Q
2	-	Q	-	-	-
3	-	-	-	Q	-
4	Q	-	-	-	-
5	-	-	Q	-	-
 solution 10:
	1	2	3	4	5
1	-	-	-	-	Q
2	-	-	Q	-	-
3	Q	-	-	-	-
4	-	-	-	Q	-
5	-	Q	-	-	-   
total number of solutions are:10     
*/
