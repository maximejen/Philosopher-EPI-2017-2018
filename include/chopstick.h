/*
** EPITECH PROJECT, 2018
** philosophers
** File description:
** chopstick
*/

#ifndef CHOPSTICK_H_
	#define CHOPSTICK_H_

	#include <pthread.h>

typedef struct {
	pthread_mutex_t *mutex;
	philo_t *owner;
	philo_t *who;
} chops_t;

#endif /* CHOPSTICK_H_ */