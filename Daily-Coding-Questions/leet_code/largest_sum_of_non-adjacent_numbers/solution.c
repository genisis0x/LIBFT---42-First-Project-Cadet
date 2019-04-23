/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:55:17 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/06 19:05:04 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int ft_sum(int arr[], int size)
{
	 int incl = arr[0]; 
  int excl = 0; 
  int excl_new; 
  int i; 
  
  for (i = 1; i < size; i++) 
  { 
     /* current max excluding i */
     excl_new = (incl > excl) ? incl: excl; 
  
     /* current max including i */
     incl = excl + arr[i]; 
     excl = excl_new; 
  } 
  
   /* return max of incl and excl */
   return ((incl > excl) ? incl : excl); 
}

int main (void)
{
	int arr[] = { 2, 4, 6, 2, 5 };
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("%d",ft_sum(arr,size));
	return (0);
}
