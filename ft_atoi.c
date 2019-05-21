/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 07:22:48 by zhelm             #+#    #+#             */
/*   Updated: 2019/05/21 09:12:43 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int ft_atoi(const char *str)
{
	int i;
	int s;
	int r;

	s = 1;
	i = 0;
	r = 0;
	while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i]== '\f' || str[i] == '\r')
	{
		i++;
	}

	if(str[i] == '-')
	{
		s *= -1;
		i++;	
	}
	else if(str[i] == '+')
	{
		i++;
	}
	while(str[i] >= 48 && str[i] <= 57)
	{
		r = r*10 + str[i] - 48;
		i++;
	}
	return(r * s);

}

int main()
{
	char c[] = "1234B4323";
	printf("%i", ft_atoi(c));
	return 0;
}
