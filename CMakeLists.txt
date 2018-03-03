PROJECT(Philosophers)

set(sources main.c
        include/philosophers.h
        philo.c
        include/extern.h)

add_executable(philo ${sources})