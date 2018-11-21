/*
** EPITECH PROJECT, 2018
** Test_Thread
** File description:
** init
*/

#ifndef INIT_H_
	#define INIT_H_

#include "bsq.h"

bsq_t data = {
    .synchro = PTHREAD_COND_INITIALIZER,
    .mut = PTHREAD_MUTEX_INITIALIZER,
};

#endif /* !INIT_H_ */
