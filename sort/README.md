Pairs are sorted primarily according to their first elements and secondarily according to their second element.
In a similar way, tuples are sorted primarily by the first element, secondarily by
the second element, etc.

Many scheduling problems can be solved by sorting the input data and then using a
greedy strategy to construct a solution.
A greedy algorithm always makes a choice
that looks the best at the moment and never takes back its choices.

Many problems can be solved using either sets or sorting. It is important to realize
that algorithms that use sorting are usually much faster, even if this is not evident by
just looking at the time complexities.
It turns out that the unordered_set
algorithm is about two times faster than the set algorithm, and the sorting algorithm
is more than ten times faster than the setalgorithm.
 Note that both the setalgorithm
and the sorting algorithm work in O(n log n) time; still the latter is much faster.
reason for this is that sorting is a simple operation, while the balanced binary search
tree used in set is a complex data structure.

the upper
bound 106 is quite small, we were also able to use arrays
While unordered_map is about
three times faster than map, an array is almost a hundred times faster. Thus, arrays should be used whenever possible instead of maps. Especially, note that while
unordered_map provides O(1) time operations, there are large constant factors
hidden in the data structure.