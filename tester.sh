#!/bin/bash
i='0'
failed='0'
if [ $# = 4 ]; then
	make
	while [ $i -lt $1 ]; do
		LD_LIBRARY_PATH=. timeout $2 ./philo -p $3 -e $4
		if [ $? -gt '0' ]; then
			printf "failed :/\n"
			failed=`expr $failed + 1`
		else
			printf "okay\n"
		fi
		i=`expr $i + 1`
	done
	printf "%d failed test.\n" $failed
	make fclean
else
	echo $0 "iteration timeout philo dishes"
fi
