# ./PmergeMe `jot -r 3000 1 3000 | tr '\n' ' '`
# ./PmergeMe `shuf -i 1-10 -n 3000 | tr "\n" " "`
ARGS="$(seq 500 | sort -R | xargs)" && ./PmergeMe $ARGS