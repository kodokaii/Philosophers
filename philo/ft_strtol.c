/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/16 12:13:55 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static t_bool	_isspace(int c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}

static long	_get_nb(const char **str, int sign)
{
	unsigned long	res;

	res = 0;
	while (_isdigit(**str))
	{
		res *= 10;
		res += **str - '0';
		if (LONG_MAX < res - (sign == -1))
		{
			errno = ERANGE;
			if (sign < 0)
				return (LONG_MIN);
			return (LONG_MAX);
		}
		(*str)++;
	}
	return (res * sign);
}

long	ft_strtol(const char *str, char **endptr)
{
	long	res;
	long	sign;

	if (endptr)
		*endptr = (char *)str;
	while (_isspace(*str))
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!_isdigit(*str))
		return (0);
	res = _get_nb(&str, sign);
	if (endptr)
		*endptr = (char *)str;
	return (res);
}
