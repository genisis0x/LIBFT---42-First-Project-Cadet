/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lengthOfLongestSubstring.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maparmar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:33:43 by maparmar          #+#    #+#             */
/*   Updated: 2019/02/22 21:34:49 by maparmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#define NO_OF_CHARS 256;

int lengthOfLongestSubstring(char* s) 
{
    
    int n = strlen(s); 
    int cur_len = 1; 
    int max_len = 1; 
    int prev_index; 
    int i; 
    int *visited = (int *)malloc(sizeof(int)*256); 
 
    if (s[0] == '\0')
        return (0);
    for (i = 0; i < 256;  i++) 
        visited[i] = -1;
  
    visited[s[0]] = 0; 

    for (i = 1; i < n; i++) 
    { 
        prev_index =  visited[s[i]]; 
  
        if (prev_index == -1 || i - prev_index > cur_len) 
            cur_len++; 
        else
        { 
            if (cur_len > max_len) 
                max_len = cur_len; 
  
            cur_len = i - prev_index; 
        } 
  
        visited[s[i]] = i; 
    } 
  

    if (cur_len > max_len) 
        max_len = cur_len; 
  
    free(visited); 
    return max_len; 
    
}

