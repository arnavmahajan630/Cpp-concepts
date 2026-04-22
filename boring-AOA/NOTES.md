## AOA Algos Practice

### MergeSort
* first declare mergeSort func that takes the v,s,e
* defifne base case for getting atlest 1 sorted element i.e s >= e return;
* Define mid 
* For each s,e i.e valid patition we make a call to s,mid and mid + 1, e under mergeSort
* On obatianing the arraay we merge these two arrays i.e merge(v,s,e);
* The merge function takes same parameters as the Sort
* we declare temp i,j mid for the shortened array. 
* We create a temporary vector and fill the elements in sorted sorder
* then copy leftover elements as it is.
* Finally Copy back the elements from temp to orignal

* TC - O(nlogn)


### QuickSort
* Choose a Pivot Point. about which point we divide the elemen. (pick the last)
* Parition the array into two parts left to pivot and right. pivot is in the correct position.
* Recursively Sort the left and the right Part of the array


### Insertion Sort
* For every element we try to insert it into it's right position. the first element is treated as it is always in it's correct position.


### Selection Sort
* The key Idea: Similar to InsertionSort: Repeatedly find the minimum element from unsorted part of the array and put it into the sorted array. we do this inplace tho.
* The last element always will end up in it's correct position since it will be the max


### Dijkstra's Algorithm
* First take input. n,m as vertices and edges
* Then take x,y,wt and make the graph as an adjeccency List representation
* Continue by building a visited array and distance array initialized with false and infi initially
* Take input a source. 
* For set the distance of source to 0
* create a set of pair keeping in mind (wt, vertex). insert 0,source in the set
* While set is not empty get the node form * begin and erase it
* Then traverse all the children of that node and if `dist[parent] + wt_child < dist[child_node]` update the distance of the child node and insert the new distance[child], child for the further exploration
* Always do this for unvisited arrays and each processing makes it visited


### Job Scheduling with Deadlines
* We are given N jobs with an ID, Profit and Deadline
* key part is to arrance the jobs to maximize profit
* Sort the Jobs in descending order (prefer maximum profit ones)
* For each job fit it from deatline -> 0 wherever it is possible and a slot is free
* else discard that job

### Floyd Warshal Algorthm
* It is a shortest path algorithm for all pair. (Shortest path between given two pair)
* Also called as All pair shortest path algorithm
* Cap on a K i.e for each visit between a pair we are going through k vertex for  visiting
*  k = 1 means pass through 1 similarly k = 2 means 1,2
* on Kth level means we can go through 0->k nodes. k+1 means k through k + 1
* If a shortest path is obtained by k then k + 1th passing should not change the path. only when it passes for a given i,j as j -> k + 1 and j -> k + 1 then and only then we can say k + 1 is valid
* dp[i][j] = dp[i][k] + dp[k][j]


### Fractional Knapsack
* sort descending based on val / w weight
* Take whole weight if <=  knapsack capacity
* else take W/Item.weight * item.value and break



