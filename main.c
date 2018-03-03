/*
** EPITECH PROJECT, 2018
** Philosophers
** File description:
** main.c
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/philosophers.h"

static const char FLAGS[4][7] = {
"-p",
"-e",
"--help",
"-h"
};

static const char *HELP_MESSAGE =
"USAGE\n"
"\t./philo -p nbr_p -e nbr_e\n"
"\n"
"DESCRIPTION\n"
"\t-p nbr_p\tnumber of philosophers\n"
"\t-e nbr_e\tmaximum number times a philosopher eats before exiting"
" the program";

static int parse_args(int argc, char **argv, args_t *args)
{
	for (int i = 1 ; i < argc ; i++) {
		if (strcmp(argv[i], FLAGS[0]) == 0 && (i + 1) < argc) {
			i++;
			args->nbr_p = atoi(argv[i]);
		} else if (strcmp(argv[i], FLAGS[1]) == 0 &&
			   (i + 1) < argc) {
			i++;
			args->nbr_e = atoi(argv[i]);
		}
	}
	if (args->nbr_e == -1 || args->nbr_p == -1)
		return (84);
	return (0);
}

int main(int argc, char **argv)
{
	args_t args = {-1, -1};
	int ret = 84;

	if (argc >= 5) {
		ret = parse_args(argc, argv, &args);
		printf("number of philosophers       : %d\n", args.nbr_p);
		printf("number of times they can eat : %d\n", args.nbr_e);
		return (ret);
	}
	if (strcmp(argv[1], FLAGS[2]) == 0 ||
	    strcmp(argv[1], FLAGS[3]) == 0) {
		printf("%s\n", HELP_MESSAGE);
		return (0);
	}
	return (ret);
}