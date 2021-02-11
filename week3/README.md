## 2015_us_open_palindromic_paths ##

Link:     
http://www.usaco.org/index.php?page=viewproblem2&cpid=548

Analysis:     
We can observe that every palindrome has its middle character on the diagonal starting at the top-right corner of the grid and ending at the bottom-left corner of the grid.
Therefore, for a given square on that diagonal, we can keep track of all possible strings that we can generate going from the top-left corner to that square going only right and down, as well as all strings that we can generate from the bottom-right corner going to that square going only up and left. If, for a given square, a string appears in both of those sets, then that string is a prefix to a valid palindrome.

Key concepts：     
unordered_set    
recursion   
combinatorics     

## 2015_feb_censoring ##

Link:    
http://www.usaco.org/index.php?page=viewproblem2&cpid=526

Analysis:    
We can approach this problem by reading in each letter of the string one by one. As soon as the end matches T, we delete it and resize the string. We repeat this process until all letters are read and there’s no occurrence of T left.

Key concepts:    
string operations   
optimization    
searching   

## 2015_feb_cow ##

Link:    
http://www.usaco.org/index.php?page=viewproblem2&cpid=527

Analysis:    
If the next character is a "C", then the number of times "C" appears increases by 1.
If the next character is a "O", then the number of times "CO" appears increases by the number of instances of the sequence "C" seen so far.
If the next character is a "W", then the number of times "COW" appears increases by the number of instances of the sequence "CO" seen so far.

Key concepts:    
combinatorics
