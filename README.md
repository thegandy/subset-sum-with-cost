# Subset sum with cost algorithm

### Subset sum problem
**Problem statement:**<br>
&nbsp;&nbsp;&nbsp;Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.  
**Solution:**  
&nbsp;&nbsp;&nbsp;This problem can be solved in polynomial time using Dynamic programming.  
&nbsp;&nbsp;&nbsp;You can check it on [Geeksforgeeks.org](https://www.geeksforgeeks.org/subset-sum-problem-dp-25/) as a Method 2.  
&nbsp;&nbsp;&nbsp;Using additional effort we can backtrace and print all solutions. Check it [HERE](https://www.geeksforgeeks.org/perfect-sum-problem-print-subsets-given-sum/).  

### Subset sum with cost problem
**Problem statement:**  
&nbsp;&nbsp;&nbsp;Given a set of objects containing non-negative integer value and cost, and a value of sum, find a subset of the given set of objects with sum of values equal to given sum and minimizing sum of cost values.  
**Solution:**  
&nbsp;&nbsp;&nbsp;This algorithm gives us solution to this problem in polynomial time O(n*sum) where n is size of set.  

#### Solution Design
Example:  
values = {1, 1, 2, 3}  
cost &nbsp;&nbsp;&nbsp;&nbsp;= {1, 3, 3, 4}  
sum &nbsp;&nbsp;&nbsp;&nbsp;= 5  
Possibilities are A = {1, 1, 3} and B = {2, 3}.  
Costs for A is 1 + 3 + 4 = 8 and for B is 4 + 3 = 7, so result should be B = {2, 3}.  

So we will create a 2D array of size (n + 1) * (sum + 1) of type unsigned. The state matrix[i][j] will be false (special value of (unsigned)-1) if there doesn't exists a subset of elements from A[0….i] with sum value = ‘j’. In the other case the value is minimum cost value of subset of elements from A[0..i] with sum value = 'j'.  

| VAL\SUM | 0 | 1 | 2 | 3 | 4 | 5 |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
|          1 |          1 |          1 | false | false | false | false |
|          1 |          3 |          1 |          4 | false | false | false |
|          2 |          3 |          1 |          3 |          4 |          7 | false |
|          3 |          4 |          1 |          3 |          4 |          5 |          7 |
