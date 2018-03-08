/*
** EPITECH PROJECT, 2018
** philosophers
** File description:
** chopsticks file
*/

#include <stdlib.h>
#include <pthread.h>
#include "extern.h"
#include "philosophers.h"

chops_t *new_chopstick()
{
	chops_t *ret = malloc(sizeof(chops_t));

	if (ret == NULL)
		return (NULL);
	ret->who = NULL;
	ret->owner = NULL;
	ret->mutex = malloc(sizeof(*ret->mutex));
	if (ret->mutex == NULL) {
		free(ret);
		return (NULL);
	}
	pthread_mutex_init(ret->mutex, NULL);
	return (ret);
}

void destroy_chopstick(chops_t *cs)
{
	pthread_mutex_destroy(cs->mutex);
	free(cs->mutex);
	free(cs);
}

chops_t **create_chopsticks(int quantity)
{
	chops_t **ret = malloc(sizeof(chops_t*) * (quantity + 1));

	if (ret == NULL)
		return (NULL);
	for (int i = 0; i < quantity; i++) {
		ret[i] = new_chopstick();
		if (ret[i] == NULL)
			return (NULL);
	}
	ret[quantity] = NULL;
	return (ret);
}

bool take(philo_t *philo, chops_t *chop)
{
	if (chop->who == philo ||
		(chop->who != philo && pthread_mutex_trylock(chop->mutex))) {
		chop->who = philo;
		lphilo_take_chopstick(chop->mutex);
		return (true);
	}
	return (false);
}

void take_two(philo_t *philo, chops_t *first, chops_t *second)
{
	while ((first->who && first->who != philo) ||
		(second->who && second->who != philo)) {
		pthread_mutex_unlock(first->mutex);
		pthread_mutex_unlock(second->mutex);
	}
	pthread_mutex_lock(first->mutex);
	pthread_mutex_lock(second->mutex);
	lphilo_take_chopstick(first->mutex);
	lphilo_take_chopstick(second->mutex);
	first->who = philo;
	second->who = philo;
}

void liberate(chops_t *chop)
{
	if (pthread_mutex_unlock(chop->mutex) == 0) {
		chop->who = NULL;
		lphilo_release_chopstick(chop->mutex);
	}
}