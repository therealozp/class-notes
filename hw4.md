## problem 1
a. 
when using quicksort, a way we can improve pivot selection so that we can guarantee an $O(n\log n)$ runtime is **random sampling, and retrieving the median value**. 

the reason behind this is when quicksort continuously selects the first/last element as a pivot, it will run into an $O(n^2)$ runtime when the list is pre-sorted/reverse-sorted. an ideal version of quicksort is that we are always able to partition the array into 2 perfectly equal subarrays, resulting in a tree height of $O(\log_{2}{n})$. however, doing something like that is very challenging, so we opt for picking the 3-to-1 ratio, where elements are split 25%-75%. 

to be 90% confident that the sorting algorithm will run in $O(n\log n)$, however, we need to sample **9 random elements from the array,** and **pick the median** between all of them to be the pivot. by doing so, we are increasing the chance for the pivot to be the true median, which draws the total worst-case time complexity to be much closer to our desired $O(n\log n)$.

b.
if memory is an issue of a system, **quicksort** would be the much better choice. while quicksort and merge sort both have the same time complexity of $O(n\log n)$, quicksort can be done in place on the same array, avoiding extra memory needs.

merge sort, on the other hand, sorts elements by doing repeated recursive calls, and merges them back on the way up. the way merge sort is done, however, results initializations of new arrays every time it walks back up. each time it is initialized, makes for a worst case of $O(n)$ memory usage. 

so, compared to quicksort's $O(1)$ extra memory use, and given quicksort is also much faster than merge sort due to the low constant term in asymptotic analysis, quicksort would be the right choice.

c. 
the instability of quicksort comes from the fact that elements of the same value gets swapped around during the in-place implementation. if the order is to be preserved, one way we can do it is instead of using extra arrays to contain partitions, instead of swapping elements of the array around.

the pseudocode for stable quicksort would look like:

```cpp
function stableQuickSort(arr):
    if length(arr) <= 1:
        return arr
    
    # pivot (e.g., first element, last element, or a random element)
    pivot = arr[0]
    
    # Partition the array into three parts while maintaining stability
    less = []       # Elements less than the pivot
    equal = []      # Elements equal to the pivot
    greater = []    # Elements greater than the pivot
    
    # Divide elements into the three parts
    for element in arr:
        if element < pivot:
            less.append(element)
        elif element == pivot:
            equal.append(element)
        else:
            greater.append(element)
    
    # Recursively apply stableQuickSort on the 'less' and 'greater' subarrays
    sorted_less = stableQuickSort(less)
    sorted_greater = stableQuickSort(greater)
    
    # Concatenate the sorted results in order
    return sorted_less + equal + sorted_greater
```

this way, the order of the elements remain the same even if the values are equal. another option is to use merge sort, which is guaranteed to be stable due to its invariant merging items going from left to right and picking the correct element.

## problem 2
a. 
first, we define the core of the problem. the most important realization for a divide and conquer solution of this problem is understanding where the maximum subarray could take place.

given an array `[a, b, c, d, e, f, g, h]`, the maximum subarray can occur in the first half, the second half, **but also the crossing range in between**. what this means for the algorithm, is that on the way up, it requires a merging step that is able to determine the value of the maximum subarray.

with that, we can formalize our divide and conquer solution:
- **divide**: we first divide the array in half, up to the midpoint.
- **conquer**: we recursively solve for the answer in the left and right subarray. the return value should be the **sum of all elements in the maximum subarray.**
- **merge**: the merge step is slightly more involved, as now we need to identify how we can account for the maximum subarray in between the two sections.
	- to do this, we make use of the **prefix** and **suffix** arrays. we understand that a subarray has to be contiguous, meaning the elements have to all sit next to each other.
	- the **prefix array** keeps a running count of sums, where `prefix[i]` is `running_sum + array[i]`. similar thing for suffix, except the arrays are initialized backwards.
	- if we get the suffix array of the left and prefix array of the right, we will have a slice of the accumulated sum of two halves of the array, starting from the midpoint. then, `suffix[i] + prefix[j] = sum(array[i:j])`.

pseudocode:
```python
def dnc(array):
	if len(array) <= 1:
		return array[0]

	midpoint = len(array) // 2
	
	left = dnc(array[:midpoint])
	right = dnc(array[midpoint:])

	# merge step
	left_prefix = 0
	max_left = float('-inf') # -infinity
	# iterate through left subarray in reverse
	for i in range(midpoint - 1, -1, -1):
		left_prefix += array[i]
		max_left = max(max_left, left_prefix)
	
	right_prefix = 0
	max_right = float('-inf') 
	# iterate through right subarray from left to right
	for j in range(midpoint, n):
		right_prefix += array[j]
		max_right = max(max_right, right_prefix)
	
	# as we have discussed, the max subarray can go:
	# all in the lef
	# all in the right
	# or somewhere in between.
	return max(left, right, max_left + max_right)
```

time complexity analysis:
- the subarray is split into 2 equal parts of size $\frac{n}{2}$ each. 
- the merge step essentially loops over the entire array, costing $O(n)$

therefore, the recurrence relation is: 
$$T(n) = 2T\left( \frac{n}{2} \right) + O(n)$$

with this, $a = 2, b =2, c= \log_{2}{2} = 1$
therefore, we have $f(n) = \Theta(n^c)$, which is the case 2 of Master theorem. so, the final complexity is $O(n^{c}\log^{k+1}n)=O(n\log n)$

b. 
for the array `[13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7]`, the process is

base case reached with array: `[13]`
base case reached with array: `[-3]`
- current array segment: `[13, -3]`
	- max subarray in left segment (`[13]`): `[13]` with sum 13

base case reached with array: `[-25]`
base case reached with array: `[20]`
- current array segment: `[-25, 20]`
	- max subarray in right segment (`[20]`): `[20]` with sum 20

- current array segment: `[13, -3, -25, 20]`
	- max subarray in right segment (`[-25, 20]`): `[20]` with sum 20

base case reached with array: `[-3]`
base case reached with array: `[-16]`
- current array segment: `[-3, -16]`
	- max subarray in left segment (`[-3]`): `[-3]` with sum -3

base case reached with array: `[-23]`
base case reached with array: `[18]`
- current array segment: `[-23, 18]`
	- max subarray in right segment (`[18]`): `[18]` with sum 18

- current array segment: `[-3, -16, -23, 18]`
	- max subarray in right segment (`[-23, 18]`): `[18]` with sum 18

- current array segment: `[13, -3, -25, 20, -3, -16, -23, 18]`
	- max subarray in left segment (`[13, -3, -25, 20]`): `[20]` with sum 20

base case reached with array: `[20]`
base case reached with array: `[-7]`
- current array segment: `[20, -7]`
	- max subarray in left segment (`[20]`): `[20]` with sum 20

base case reached with array: `[12]`
base case reached with array: `[-5]`
- current array segment: `[12, -5]`
	- max subarray in left segment (`[12]`): `[12]` with sum 12

- current array segment: `[20, -7, 12, -5]`
	- max subarray crossing midpoint: `[20, -7, 12]` with sum 25

base case reached with array: `[-22]`
base case reached with array: `[15]`
- current array segment: `[-22, 15]`
	- max subarray in right segment (`[15]`): `[15]` with sum 15

base case reached with array: `[-4]`
base case reached with array: `[7]`
- current array segment: `[-4, 7]`
	- max subarray in right segment (`[7]`): `[7]` with sum 7

- current array segment: `[-22, 15, -4, 7]`
	- max subarray crossing midpoint: `[15, -4, 7]` with sum 18

- current array segment: `[20, -7, 12, -5, -22, 15, -4, 7]`
	- max subarray in left segment (`[20, -7, 12, -5]`): `[20, -7, 12]` with sum 25

- current array segment: `[13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]`
	- max subarray crossing midpoint: `[18, 20, -7, 12]` with sum 43

so, the final result is the subarray `[18, 20, -7, 12]` with sum 43.

## problem 3
a.
**divide**: divide the array into 2 smaller subarrays
**conquer**: count the frequencies of words in each subarrays
**merge**: on the merge step, merge the two frequency hashmaps into one, and return that alongside the max frequency in the hashmap.

```python
function mostFrequentKeyword(document):
    if len(document) == 1:
        # Returns a dictionary of keyword frequencies for this section
        return countKeywords(document[0])  
    
    # Split document into two halves
    mid = len(document) // 2
    left_freq = mostFrequentKeyword(document[:mid])
    right_freq = mostFrequentKeyword(document[mid:])
    
    combined_freq = mergeFrequencies(left_freq, right_freq)
    most_frequent = getMostFrequent(combined_freq)
    return most_frequent

function countKeywords(section):
    frequency = {}
    for keyword in section:
        if keyword in frequency:
            frequency[keyword] += 1
        else:
            frequency[keyword] = 1
    return frequency

function mergeFrequencies(left_freq, right_freq):
    combined_freq = left_freq.copy()
    for keyword, count in right_freq.items():
        if keyword in combined_freq:
            combined_freq[keyword] += count
        else:
            combined_freq[keyword] = count
    return combined_freq

function getMostFrequent(frequency_dict):
    max_keyword = None
    max_count = 0
    for keyword, count in frequency_dict.items():
        if count > max_count:
            max_count = count
            max_keyword = keyword
    return max_keyword
```

b.
this assumes a hashmap implementation.
- we are dividing the input into 2 different subarrays, and recurring over these 2 sub-inputs.
- the time complexity for total cost per output is:
	- the `mergeFrequencies` function and `getMostFrequent` will only run as much as the number of keys. So, in total, the time complexity is $O(k)$, where $k$ is the number of unique keys.
	- in the worst case where there is $n$ unique keys, the time complexity is $O(n)$.
- so, for the same recurrence relation we defined above:
$$T(n) = 2T\left( \frac{n}{2} \right)+O(n)$$
we get the final time complexity of $O(n\log n)$.

when it is a binary tree, instead of taking $O(1)$ to retrieve and insert keys on the average case, it would take $O(\log n)$, especially for a balanced binary tree. so, the merging step will now take $O(n\log n)$ for each step, making for a total TC of $O(n\log^{2}{n})$.

if we are considering a binary tree, then the worst case will be when the tree mirrors a linked list. in that case, the worst case time complexity for each key insertion is $O(n)$, and the merging step will be take $O(n^{2})$. at this point, the merge step completely dominates the recurrence relation, and the total TC becomes $O(n^{2})$.

c.
dividing into 2...
dividing into 2...
dividing into 2...
base case reached: `['apple', 'banana', 'apple']`
base case reached: `['banana', 'apple', 'orange']`
	- merged frequencies at this step: `{'apple': 3, 'banana': 2, 'orange': 1}`
	- most frequent keyword at this step: **apple**
iteration done

dividing into 2...
base case reached: `['orange', 'apple', 'orange']`
base case reached: `['banana', 'orange', 'orange']`
	- merged frequencies at this step: `{'orange': 4, 'apple': 1, 'banana': 1}`
	- most frequent keyword at this step: **orange**
iteration done

- merged frequencies at this step: `{'apple': 4, 'banana': 3, 'orange': 5}`
- most frequent keyword at this step: **orange**
iteration done

dividing into 2...
dividing into 2...
base case reached: `['apple', 'apple', 'banana']`
base case reached: `['banana', 'banana', 'apple']`
	- merged frequencies at this step: `{'apple': 3, 'banana': 3}`
	- most frequent keyword at this step: **apple**
iteration done

dividing into 2...
base case reached: `['orange', 'orange', 'apple']`
base case reached: `['apple', 'banana', 'orange']`
	- merged frequencies at this step: `{'orange': 3, 'apple': 2, 'banana': 1}`
	- most frequent keyword at this step: **orange**
iteration done

-  merged frequencies at this step: `{'apple': 5, 'banana': 4, 'orange': 3}`
- most frequent keyword at this step: **apple**
iteration done

- merged frequencies at this step: `{'apple': 9, 'banana': 7, 'orange': 8}`
- most frequent keyword at this step: **apple**
iteration done

