## 2019_dec_cow_gymnastics ##

Link:   
  
http://www.usaco.org/index.php?page=viewproblem2&cpid=963

Analysis:   
  
For each pair of cows (A,B), we will count how many practice sessions cow A did better than cow B in. If cow A did better than cow B in all K practice sessions, we increment a counter, and then print out the value of the counter once we’ve looped over all pairs of cows.

Key concepts：   
  
fstream   
iostream       
combinatorics   
2D array  
searching   

## 2019_dec_where_am_i ##

Link:   
  
http://www.usaco.org/index.php?page=viewproblem2&cpid=964

Analysis:   
  
Since N is at most 100, we can check from K=1 to K=N (stop when there’s a valid answer).
We can check if a value of K is valid by looping over all pairs of substrings of length K and compare them for equality. If we find a repetition for a substring of length K,  we can go directly to the K+1 iteration and repeat the same process.

Key concepts:   
  
nested for loops  
string operations  
combinatorics  
searching    

## 2019_dec_livestock_lineup ##

Link:   
  
http://www.usaco.org/index.php?page=viewproblem2&cpid=965

Analysis:   
  
Since the input is small enough, we can try all the orderings (in alphabetical order) and stop as we see one that matches all the constraints.

Key concepts:   
  
combinatorics   
algorithm  
vector   
