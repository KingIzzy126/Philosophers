/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:14:06 by ismailalash       #+#    #+#             */
/*   Updated: 2024/12/28 22:37:56 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_input input;

    if (ac != 5 && ac != 6)
        print_instructions_and_exit();
    if (check(&input, av) != 0)
        return (1);
    return(0);
}