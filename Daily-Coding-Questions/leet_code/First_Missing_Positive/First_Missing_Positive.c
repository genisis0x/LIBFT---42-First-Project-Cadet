/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   First_Missing_Positive.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 21:04:16 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/26 23:00:59 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int firstMissingPositive(int* nums, int numsSize) {
    int i = 0;
    int p = numsSize;

    while (i < p) {
        int n = nums[i];
        if (n == i+1)
            ++i;                 // Found it! Look for the next one.
        else if (n < 1 || n > p || n == nums[n-1])
            nums[i] = nums[--p]; // Useless. Get new candidate from the end.
        else {
            nums[i] = nums[n-1]; // Within range; put it in the right place.
            nums[n-1] = n;
        }
    }
    return p + 1;
}
