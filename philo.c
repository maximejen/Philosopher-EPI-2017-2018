/*
** EPITECH PROJECT, 2018
** Philosophers
** File description:
** philo.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <err.h>
#include <string.h>
#include "include/philosophers.h"

static void *philo_action_against_starvation(void *arg)
{
	return ("ok");
}

philo_t *init_philo(int id, int max_dish, chops_t **chopsticks)
{
	philo_t *philo = malloc(sizeof(philo_t));
	int ret;

	if (!philo)
		return (NULL);
	philo->id = id;
	philo->dish_counter = 0;
	philo->hungry = 0;
	philo->sleepy = 0;
	philo->max_dish = max_dish;
	philo->own = chopsticks[id];
	philo->own->owner = philo;
	philo->right = chopsticks[id + 1] ? chopsticks[id + 1] : chopsticks[0];
	ret = pthread_create(
	philo->thread, NULL, &philo_action_against_starvation, philo);
	if (ret != 0)
		perror("pthread_create");
	return (philo);
}

void destroy_philo(philo_t *philo)
{
	void *status;

	if (pthread_join(*philo->thread, &status))
		printf("pthread_join Error.\n"), exit(84);
	destroy_chopstick(philo->own);
	free(philo);
}
