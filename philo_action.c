/*
** EPITECH PROJECT, 2018
** philosophers
** File description:
** philo_action.c
*/

#include <stdio.h>
#include <unistd.h>
#include "philosophers.h"
#include "extern.h"

static void philo_eat(philo_t *philo)
{
	take_two(philo, philo->own, philo->right);
	lphilo_eat();
	philo->dish_counter++;
	usleep(EAT_TIME);
	liberate(philo->own);
	liberate(philo->right);
}

static void philo_think(philo_t *philo)
{
	while (!take(philo, philo->own) && !take(philo, philo->right));
	lphilo_think();
	usleep(THINK_TIME);
	liberate(philo->right);
	liberate(philo->own);
}

static void philo_sleep(void)
{
	lphilo_sleep();
	usleep(SLEEP_TIME);
}

void *philo_action_against_starvation(void *arg)
{
	philo_t *philo = (philo_t*)arg;

	while (philo->dish_counter < philo->max_dish) {
		usleep(WAIT_TIME * philo->id / 10);
		philo_sleep();
		usleep(WAIT_TIME * philo->id / 10);
		philo_think(philo);
		usleep(WAIT_TIME * philo->id / 10);
		philo_eat(philo);
	}
	return ("ok");
}
