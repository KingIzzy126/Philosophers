/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:47:13 by ismailalash       #+#    #+#             */
/*   Updated: 2025/01/11 21:21:51 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_atoi(char *str)
{
    long long result;
    int i;

    i = 0;
    result = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i++;
    if (str[i] == '-')
        return (-1);
    if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        if (result > 2147483647)
            return(-1);
        i++;
    }
    if (str[i] != '\0')
        return(-1);
    return ((int)result);
}

void *safe_malloc(size_t bytes)
{
    void    *buff;
    
    buff = malloc(bytes);
    if (NULL == buff)
    {
        printf("Error: Memory allocation of %zu bytes failed.\n", bytes);
        return (NULL);
    }
    return(buff);
}

size_t  get_current_time(void)
{
    struct timeval  time;

    if (gettimeofday(&time, NULL) == -1)
        printf("Error: gettimeofday() fail\n");
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void    print_message(t_philo *philo, char *str)
{
    size_t  time;

    pthread_mutex_lock(&philo->input->print_mutex);
    time = get_current_time() - philo->input->program_start_time;
    if(!philo->input->dead_flag)
        printf("%zu %d %s\n", time, philo->id, str);
    pthread_mutex_unlock(&philo->input->print_mutex);
}

void    precise_sleep(size_t time, t_philo *philo)
{
    size_t start_time;

    start_time = get_current_time();
    while ((get_current_time() - start_time) < time)
    {
        if (philo->input->dead_flag)
            break;
        usleep(500);
    }
}

void    clean_up(t_input *input)
{
    int i;

    i = 0;
    while(i < input->num_philos)
    {
        pthread_mutex_destroy(&input->forks[i].fork);
        i++;
    }
    pthread_mutex_destroy(&input->print_mutex);
    pthread_mutex_destroy(&input->dead_mutex);
}