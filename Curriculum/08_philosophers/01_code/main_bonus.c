/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akekesi <akekesi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 19:04:51 by akekesi           #+#    #+#             */
/*   Updated: 2023/09/09 21:01:23 by akekesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t semaphore;

void *thread_function(void *arg) {
	sem_wait(&semaphore);
	sem_post(&semaphore);
	return NULL;
}

int	main(int argc, char **argv)
{
	if (1 < argc)
	{
		printf("%s\n", argv[1]);
	}
	sem_t semaphore;
	if (sem_init(&semaphore, 0, 1) != 0) {
		perror("Semaphore initialization failed");
	exit(EXIT_FAILURE);
}
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, thread_function, NULL);
	pthread_create(&thread2, NULL, thread_function, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	sem_destroy(&semaphore);

	return 0;
}
