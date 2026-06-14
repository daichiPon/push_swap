/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnakamot <dnakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 16:56:28 by nakamotodai       #+#    #+#             */
/*   Updated: 2026/05/31 14:49:32 by dnakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

const char	*ft_strchr(const char *s, int c);
int			ft_putchar(int c);
int			ft_putnbr(int n);
size_t		ft_putstr(char *s);
int			ft_putnbr_u(unsigned int n);
int			ft_puthex_lit(unsigned int n);
int			ft_puthex_big(unsigned int n);
int			ft_puthex_p(void *n);
int			ft_putfloat(double n, int prec);

#endif