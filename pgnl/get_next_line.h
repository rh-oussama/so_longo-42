/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orhaddao <orhaddao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:46:53 by orhaddao          #+#    #+#             */
/*   Updated: 2024/02/18 11:26:58 by orhaddao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t n, size_t size);
char	*get_file(int fd, char *tmp);
char	*get_line_file(char *buffer);
char	*get_next(char *buffer);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
///////////////////////////////////
int		ft_printf(const char *str, ...);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
int		ft_putchar(char c);
int		ft_puthex(unsigned int nb, char c);
int		print_hex(unsigned long n, size_t digits);
int		ft_putnbr_unsigned(unsigned int nb);
int		putptr(void *ptr);
int		data_type(char c, va_list args);
int		ft_printf(const char *str, ...);

#endif