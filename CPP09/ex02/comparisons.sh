#! /bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'

maxComparisons=$(awk -v n="$1" 'BEGIN {
	res=0.0
    a = 3.0
    b = 4.0
    k = 1
    while (k <= n) {
        res += int(log((a/b) * k) / log(2) + 0.999999)  # ceil(log2(x))
        k++
    }
    print res
}')

./PmergeMe "comparisons" $(shuf -i 1-9999 -n $1) > comparisons.txt

vectorComparisons=$(head -n 1 comparisons.txt)
dequeComparisons=$(tail -n 1 comparisons.txt)

if ((vectorComparisons <= maxComparisons)); then
  echo -e "${GREEN}Vector ${vectorComparisons} out of ${maxComparisons}"
else
  echo -e "${RED}Vector ${vectorComparisons} out of ${maxComparisons}"
fi

if ((dequeComparisons <= maxComparisons)); then
  echo -e "${GREEN}Deque ${dequeComparisons} out of ${maxComparisons}"
else
  echo -e "${RED}Deque ${dequeComparisons} out of ${maxComparisons}"
fi

rm comparisons.txt
