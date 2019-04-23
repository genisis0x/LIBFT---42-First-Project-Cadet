/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infix_postfix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:01:24 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/09 02:56:27 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define STK_SIZE 2048

int position = -1;
char stack[STK_SIZE];

int is_operator(char c) // check operator
{
	return (c == '*' || c == '/' || c == '%' || c == '+' || c == '-');
}

int precedence (char d) // function to define the precedence 
{
	if (d == '*')
		return (5);
	if (d == '/')
		return (4);
	if (d == '%')
		return (3);
	if (d == '+')
		return (2);
	if (d == '-')
		return (1);
	return (0);
}

char pop() // pop operation
{
	if (position == -1)
	{
		return (0);
	}
	else
		return(stack[position--]);
}

void push(char item) // push operation
{
	stack[++position] = item;
}

void ft_iftpf(char *s) // driver function
{
	int i = 0;
	while (s[i])
	{
		if (!is_operator(s[i]) && s[i] != ' ')
		{
			write (1, &s[i], 1); // if it's not the operator the just simply print it.
		}
		else if ((is_operator(s[i])) && (position == -1))
		{
			push(s[i]);
		}
		else if (is_operator(s[i]) && (position != -1)) // if the precedence is higher then the stack position then just push in the stack
		{
			if (precedence(s[i]) > precedence(stack[position]))
			{
				push (s[i]);
			}
			else // if the precedence is lower then pop the position and push the precedence after pop
			{
				char item = pop();
				write (1, &item, 1);
				push (s[i]);
			}
		}
		i++;
	}
	while (position != -1) // empty the whole stack at last by displaying all the item's
	{
		int item = pop();
		write (1, &item, 1);
	}
}


int main (int ac , char **av)
{
	if (ac == 2)
	{
		ft_iftpf(av[1]);
	}
	write (1, "\n", 1);
	return 0;
}
