#! /bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'

./PmergeMe "sorted" $(shuf -i 1-9999 -n $1)

if sort -n -C sortedVector.txt; then
  echo -e "${GREEN}Vector sorted"
else
  echo -e "${RED}Vector not sorted"
fi

if sort -n -C sortedDeque.txt; then
  echo -e "${GREEN}Deque sorted"
else
  echo -e "${RED}Deque not sorted"
fi

rm sortedVector.txt
rm sortedDeque.txt
