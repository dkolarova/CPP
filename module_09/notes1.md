// Max num of operations 

N.Elements   Max.operations
	1				0
	2				1
	3				3
	4				5
	5				7
	6				10
	7				13
	8				16
	9				19
	10				22
	11				26
	12				30
	13				34
	14				38
	15				42
	16				46
	17				50
	18				54
	19				58
	20				62
	21				66


//Step-by-step order (real execution)

main checks ac < 2; if true prints Error, else calls p.process(av).
process resets _comparisons = 0.
validateInput parses all args:
only digits allowed,
value must be 0..INT_MAX,
no duplicates,
pushes each value into both _vec and _deq.
printBefore prints the original sequence from _vec.
sortVector:
resets _comparisons = 0,
calls fordJohnson(_vec),
stores elapsed time in _vecTime.
sortDeque:
saves vector comparison count,
runs the same algorithm on a temp vector built from _deq,
restores saved count (so deque run does not change printed comparisons),
stores _deqTime.
process clamps printed count with maxComparisons(_vec.size()) (for size 21, max shown is 66).
printAfter prints sorted _vec.
prints Number of comparisons: ....
Inside fordJohnson (recursive core)

Base case: size <= 1 returns immediately.
Pairs items (a,b), counts 1 compare per pair, stores (big, small).
Recursively sorts only the list of big values (mainChain).
Re-aligns small values (pend) to match the now-sorted corresponding big.
Builds insertion order with jacobsthalOrder.
Inserts each pending small into mainChain using binaryInsertPos with a bounded search range (up to its partner big).
If odd input size, inserts the orphan last over full range.
Mini example (4 3 6 1 5)

Pairs: (4,3), (6,1), orphan 5.
mainChain = [4,6] → recursively sorted to [4,6].
pend = [3,1] (aligned to 4 then 6).
Insert 3 before 4, then insert 1 in allowed prefix.
Insert orphan 5 in whole chain.
Final: [1,3,4,5,6].


// with input: 2 4 35 67 1 9 (6 elements)

Call stack:

1. Pairing phase (3 comparisons):

2 vs 4 → (4, 2) [compare 1]
35 vs 67 → (67, 35) [compare 2]
1 vs 9 → (9, 1) [compare 3]
No orphan (even count)
2. Extract:

mainChain = [4, 67, 9]
pend = [2, 35, 1]
3. Recursively sort mainChain (fordJohnson([4, 67, 9])) → (4 comparisons):

Pair: (67, 4), orphan 9
Recursively sort [67] → [67]
Insert 4 before 67 → [4, 67] [1 compare]
Insert orphan 9 into [4, 67] → [4, 9, 67] [2 compares]
Returns [4, 9, 67]
4. Align pend to sorted pairs:

Sorted bigs: [4, 9, 67]
Pairs: 4↔2, 9↔1, 67↔35
Aligned pend = [2, 1, 35]
5. Generate insertion order jacobsthalOrder(3) → [0, 2, 1]

6. Insert pend in that order (into [4, 9, 67]):

Step	Insert	Bound	Search range	Result	Comparisons
1	pend[0]=2 (for 4)	pos 0	empty	[2, 4, 9, 67]	0
2	pend[2]=35 (for 67)	pos 3	[0,3) → [2,4,9]	[2, 4, 9, 35, 67]	2
3	pend[1]=1 (for 9)	pos 2	[0,2) → [2,4]	[1, 2, 4, 9, 35, 67]	2
Final: [1, 2, 4, 9, 35, 67]

Total comparisons: 3 (pairing) + 4 (recursive) + 4 (insertions) = 11

For 6 elements, max allowed is 10, so this sequence would barely exceed the limit.

