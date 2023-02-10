ARGS="$(seq 500 | sort -R | xargs)" && ./push_swap $ARGS | ./checker $ARGS
ARGS="$(seq 500 | sort -R | xargs)" && ./push_swap $ARGS | wc -l