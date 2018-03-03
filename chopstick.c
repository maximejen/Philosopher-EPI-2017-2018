/*
** EPITECH PROJECT, 2018
** philosophers
** File description:
** chopsticks file
*/

#include <stdlib.h>
#include <pthread.h>
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
	return (ret);
}