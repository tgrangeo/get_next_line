/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: thomasgrangeon <thomasgrangeon@student.    +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 12:08:12 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 19:23:06 by thomasgrang ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>

char		*ft_strndup(const char *s, int len);
int			ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, int start, int len);

#endif