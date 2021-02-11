## 2013_jan_liars_and_truth_tellers ##

Link:   
http://www.usaco.org/index.php?page=viewproblem2&cpid=225

Analysis:   
If “x y T” is given, we treat x and y as the same type.   
If “x y L” is given, we treat x and y as different types.   
We can propose a graph where very vertex represents a cow, and for any statement about cows x and y, we put an edge between those two cows in the graph to represent the new relation.    
For any connected component of the graph, we can separate it into two subcomponents A and B (each T edge is between two vertices of the same subcomponent and each L edge is between two vertices of opposite  subcomponents). 

Key concepts：   
graph  
connected components  
1D array   
logical operators    

## 2012_dec_meet_and_greet ##

Link:    
http://www.usaco.org/index.php?page=viewproblem2&cpid=205

Analysis:   
We can approach this problem by getting all the inputs and storing them as 1s  or -1s in two 1D arrays (each cow is assigned an array, recording their movements). 1s represent a step to the right and -1s represent a step to the left. We can then compare the two cows’ positions at each second and find out when they meet and greet each other.

Key concepts:   
1D array   
logical operators   
simulation   
number-line  

## 2012_dec_scrambled_letters ##

Link:    
http://www.usaco.org/index.php?page=viewproblem2&cpid=206

Analysis:    
A string appears earliest if its letters are sorted in alphabetical order and every other string was sorted in reverse alphabetical order. A string appears latest if its letters are sorted in reverse alphabetical order and every other string is sorted in alphabetical order.     
Thus, we can make four 1D string arrays. Two of them consist of each string being sorted alphabetically or reverse alphabetically. The other two are alphabetically and reverse alphabetically sorted arrays.     
We compare each alphabetically sorted string with the reverse alphabetically sorted array, finding the lowest possible position. Then we implement the same idea for finding the highest possible position.

Key concepts:    
1D array  
sorting   
string    
