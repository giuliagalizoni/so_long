/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalizon <ggalizon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:03:56 by ggalizon          #+#    #+#             */
/*   Updated: 2024/12/20 12:40:54 by ggalizon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char		*get_next_line(int fd);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(char *src);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *str);
void		*ft_memcpy(void *dest, const void *src, size_t n);

#endif
