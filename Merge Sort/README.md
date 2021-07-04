Merge Sort.<br>
Assuming that we have two sorted subsets. <br>
by merging them together using a simple loop and comparator it's done. <br>
But we can't rely on such an assumption. <br >
the best way to assume something is to do it. <br>
So, we can work around and sort the two subsets using the insertion sort. <br> 
but it's a trivial solution.<br>
with merge sort we recursively call the merge sort using the two halfs of the set.<br>
when there is only one element in the set then it's sorted.<br>
and hence, that is our termination condition for the recursion.<br>
Take a look on the code please :).