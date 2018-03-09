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