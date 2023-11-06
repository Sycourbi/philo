/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sycourbi <sycourbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:16:51 by sycourbi          #+#    #+#             */
/*   Updated: 2023/11/06 17:13:19 by sycourbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arg(int argc, char **argv)
{
	int	i;
	int	j;
	int	count_significant_digits;

	i = 1;
	while (i <= argc - 1)
	{
		j = 0;
		count_significant_digits = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (printf("problem args\n"), 1);
			count_significant_digits += argv[i][j] != '0';
			j++;
		}
		if (count_significant_digits > 10)
			return (printf("problem arg\n"), 1);
		i++;
	}
	return (0);
}

void	signal_print_death(t_data *data, int i)
{
	pthread_mutex_lock(&data->mutex_check);
	data->someone_died = 1;
	pthread_mutex_unlock(&data->mutex_check);
	pthread_mutex_lock(&data->write);
	printf("%ld %d died\n", get_time(data->t0), i);
	pthread_mutex_unlock(&data->write);
}

void	update_philo_data(t_data *data, int *iteration, int *time, int i)
{
	pthread_mutex_lock(&data->mutex_check);
	*iteration += data->philo[i].reste_meal;
	*time = get_time(data->t0) - data->philo[i].last_meal;
	pthread_mutex_unlock(&data->mutex_check);
}

void	check_philo_life(t_data *data)
{
	int	i;
	int	time_since_last_meal;
	int	iteration_meal_count;

	i = 0;
	iteration_meal_count = 0;
	while (1)
	{
		update_philo_data(data, &iteration_meal_count,
			&time_since_last_meal, i);
		if (time_since_last_meal > data->global_rules.time_to_die
			&& data->philo[i].reste_meal)
			return (signal_print_death(data, i + 1));
		if (i == data->global_rules.nbr_philo - 1
			&& iteration_meal_count == 0)
			return ;
		else if (i == data->global_rules.nbr_philo - 1
			&& iteration_meal_count != 0)
			iteration_meal_count = 0;
		i++;
		i = i % data->global_rules.nbr_philo;
	}
}
