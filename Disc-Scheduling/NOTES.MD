### Notes for Disc Scheduling Algotihms

* The main Goal is to Minimize Seek Time

* Platter: CD. Multiple paltters make up a Hard Disc. There is upper surface & lower surface of disc
* Tracks: Circular lines on Platters are called Trecks
* Sectors: Each Track has multiple sectors. the data is stored in these sectors.

Platter -> (surface) ? upper : lower -> Track -> Sector

* Head ARM: This head moves front back <----->
    * Seek time: Time taken to reach the desired track for the head of the ARM from Desired Track.



#### FCFS DISC SCHEDULING ALGORITHM
* Abstract: Every Disc has a request Queue That has track numbers mapped by the MMU. There are total tracks as well as Given current position of the head. Calculate total track movements wrt to  switches made. Very simple and effecient algorithm

* Problems: starvation-like behavior for far requests, High seek time, no optimization, 

a -> b distance = abs(b- a)

#### SSTF (shortest seek time first)
* We serve the closest track to the current head.

Advantages: Minimizes immediate seek time → lower total movement, 
Disadvantages: ❌ No (locally optimal, not globally optimal)


#### Scan
* Basically we are an elevator. go left serve all left of head. then all right of head.

#### Cscan
* Serve all thge right first then from 0 serve all the way till head.
