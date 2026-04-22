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

### Longest  Common Subsequence: 
