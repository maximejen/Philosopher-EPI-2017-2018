/*
** EPITECH PROJECT, 2018
** Philosophers
** File description:
** philisophers.h
*/

#ifndef PHILISOPHERS_H_
	#define PHILISOPHERS_H_

#include <pthread.h>

typedef struct args_s {
	int nbr_p;
	int nbr_e;
} args_t;

enum action_e {
	EAT,
	THINK,
	REST
};

typedef struct philo_s philo_t;

typedef struct {
	pthread_mutex_t *mutex;
	philo_t *owner;
	philo_t *who;
} chops_t;

struct philo_s {
	int id;
	pthread_t *thread;
	chops_t *own;
	chops_t *right;
	int dish_counter;
	int max_dish;
	int hungry;
	int sleepy;
};

/*
** Chopstick functions
*/
void destroy_chopstick(chops_t *cs);
chops_t **create_chopsticks(int quantity);
chops_t *new_chopstick();

/*
** Philosophers functions
*/
philo_t *init_philo(int id, int max_dish, chops_t **chopsticks);
void destroy_philo(philo_t *philo);

#endif //PHILISOPHERS_H_
