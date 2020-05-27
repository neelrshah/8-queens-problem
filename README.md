# 8-queens-problem
In the game of chess, the queen can attack any piece that lies on the same row, on the same column, or along a diagonal.
The eight-queens is a classic logic puzzle. The task is to place eight queens on a chessboard in such a fashion that no queen can 
attack any other queen.There are many different solutions for this puzzle. Hence we use backtracking techniques to solve this puzzle.

Algorithm:

	Place the queens column wise, start from the left most column
	If the placement within the column does not lead to a solution, the queen is removed and moved down the column. 
	when all rows in a column have been tried ,the call terminates and backtracks to the previous call in previous column.
	If a queen cannot be placed into column I, then do not try to place one onto column i+1, rather, backtrack to column i-1 and
  move the queen that had been placed there, using this approach we can reduce the number of potential solutions even more.
	If all queens are placed. 
  o	return true and print the solution matrix.
	Else 
  o	Try all the rows in the current column.
  o	Check if queen can be placed here safely if yes mark the current cell in solution matrix as Q and try to solve the rest of 
    the problem recursively.
  o	If placing the queen in above step leads to the solution return true.
  o	If placing the queen in above step does not lead to the solution , BACKTRACK, mark the current cell in solution matrix as * and
    return false.
	If all the rows are tried and nothing worked, return false and print NO SOLUTION.

