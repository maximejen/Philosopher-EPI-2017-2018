/*
** EPITECH PROJECT, 2018
** unit tests
** File description:
** chopstick.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <stdio.h>
#include "philosophers.h"

Test(philo, test_chop_create)
{
	chops_t *ick = new_chopstick();

	destroy_chopstick(ick);
}

Test(philo, test_chops_create)
{
	int quantity = 5;
	chops_t **ick = create_chopsticks(quantity);

	for (int i = 0; i < quantity; i++)
		destroy_chopstick(ick[i]);
}
