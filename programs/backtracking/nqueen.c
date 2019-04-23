/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NQueen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 20:55:09 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/15 19:06:04 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include<stdbool.h>
#define N 8
static int k = 1;

void printsolution(int board[N][N])
{
	k++;
	//printf("The %d solution is\n", k++);
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			
			if (board[i][j])
				printf("%d", j + 1);
			else
				;
			;
		}
	}
	printf ("\n");
}

static bool safe_way(int board[N][N], int row, int col)
{
	int i = 0;
	int j = 0;
	while (i < col)
	{
		 if (board[row][i]) // check this row on left side
			 return false;
		 i++;
	}
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) // check the upper diagonal on left side
	{
		if (board[i][j])
			return false;
	}
	for (i = row, j = col; j >= 0 && i < N; i++, j--) // check the lower diagonal on left side
	{
		if (board[i][j])
			return false;
	}
	return true;
}
static bool ft_board_solver(int board[N][N], int col) // board solver fuction 
{
	
	if (col >= N)
	{
		printsolution(board);
		return true;
	}
	bool res = false;
	for (int i = 0; i < N; i++) // integer i is used to iterate the each row 
	{
		if (safe_way(board, i, col)) // check if the position is safe or not
		{
			board[i][col] = 1;
			if (ft_board_solver(board, col + 1))
					res = true;// call recursively
			board[i][col] = 0; // backtrack
		}
	}
	return (res);
}


int main (void)
{
	int board[N][N] = {{0}};
	if(!ft_board_solver(board, 0)) // board and the coloum where we have to start 
		printf("The Board has no solution");
	return (0);
}
