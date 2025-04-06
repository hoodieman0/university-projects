Overview
--------

You will create a game involving a slot machine. Slot machines are commonly found in casinos and in video games. They are comprised of several reels. Those reels typically have some graphics or symbols. An arm on the machine (or a button), when pulled by the player, spins the reels. Once they come to a stop, the arangement of the symbols determines if the player wins a prize. The prizes depend on the pay table which assigns values to any combinations of the wheels. Each spin of the wheel costs the player some money.

Your goal is to create a game around a virtual slot machine. 

The Reels
-----------
Each of the reels in will have the following symbols: 

4x 'A'
3x 'B'
2x 'C'
1x '7'

So the rolls would each contain the following (not necessarily in this order, but with the listed frequencies):
['A', 'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', '7']


The slot machine
----------------

The slot machine will have THREE REELS MODELED AS TEMPLATED CIRCULAR LISTS. You will implement the linked list class. For now they will hold on to char data type, but should be flexible to support strings, or any other type in the future. The slot machine will have 3 current pointers pointing to a node in each of the linked lists. A Spin() method will generate 3 random numbers between 1 and 100 and increment the respective "current" pointers by the numbers. Because it is a circular linked list, you can loop around the roll indefinitely. Once all 3 "current" pointers are incremented, check the combination (the three current pointers' data values) against the pay table below for the appropriate payout. If the combination is not in the pay table, it does not pay anything to the player. 

 ----------------------
| Combination | payout |
 ----------------------  
|   A A A     |  $6    |
|   B B B     |  $15   |
|   C C C     |  $50   |
|   7 7 7     |  $500  |
 ----------------------    

The game loop
-----------------------
The game loop will allow the user to play slots until they run out of money, or decide to quit. The user will start with $100. One spin of the slots will cost $1. If a user spins and one of the above combinations come up, that payout is added to their balance. 

Example 1: Player starts with $100. Spin costs $1, so balance reduces to $99. Player gets B B B, so their balance is now $99 + $35 (based on payout table) which totals $134

Example 2: Player starts with $1. Spin costs $1, so balance reduces to $0. Player gets 7 B A, Nothing is added to their balance because this is not a combination which has a payout. The user can no longer play because of a $0 balance. 

After every spin, provide have the option to spin again or quit (take the money and run!). If the user's balance is $0, then don't allow them to play again. If the user gets 7 7 7 print "JACKPOT!" 


Suggested classes
-----------------
These are some suggested classes to help model this program. Feel free to add other classes to help separate concerns in your program. 

Game class to control the game flow and main game loop. Balance can be tracked here.
SlotMachine class to expose the Spin() method, hold onto the state of the rolls, and generate random numbers for the spins
Reel class represented internally by a circular linked list (ReelNode will need to be implemented as well)
PayoutTable class to hold on to payout information with public methods to check a combination of symbols for a payout value. 