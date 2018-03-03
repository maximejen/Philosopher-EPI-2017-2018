PROJECT(Philosophers)

set(sources main.c
        include/philosophers.h
        philo.c
        chopstick.c
        include/extern.h
        )

add_executable(philo ${sources})