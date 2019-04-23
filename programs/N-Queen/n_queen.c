/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 04:29:24 by maparmar          #+#    #+#             */
/*   Updated: 2019/03/10 04:31:45 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#define N 8 // let N is 8 we can change the N and get different solution

void printsolution(int board[N][N]) // print solution
{
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if (board[i][j])
				printf("Q ");
			else
				printf("- ");
		}
		printf("\n");
	}
}

static int safe_way(int board[N][N], int row, int col) // safeway function to check the position is safe or not 
{
	int i = 0;
	int j = 0;
	while (i < col)
	{
		 if (board[row][i])
			 return 0;
		 i++;
	}
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j])
			return 0;
	}
	for (i = row, j = col; j >= 0 && i < N; i++, j--)
	{
		if (board[i][j])
			return 0;
	}
	return 1;
}


static int ft_board_solver(int board[N][N], int col) // board solver fuction 
{
	if (col >= N)
		return 1;
	for (int i = 0; i < N; i++) // integer i is used to iterate the each row 
	{
		if (safe_way(board, i, col)) // check if the position is safe or not
		{
			board[i][col] = 1;
			if (ft_board_solver(board, col + 1)) // call recursively
				return (1);
			board[i][col] = 0;
		}
	}
	return (0);
}


int main (void)
{
	int board[N][N] = {{0}};
	if(!ft_board_solver(board, 0)) // board and the coloum where we have to start 
		printf("The Board has no solution");
	else
		printsolution(board);
	return (0);
}
