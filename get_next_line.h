/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tgrangeo <tgrangeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 12:08:12 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 19:29:56 by tgrangeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>

char		*ft_strndup(const char *s, int len);
int			ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char const *s2);
int			ft_strchr(const char *s, int c);
char		*ft_substr(char *s, int start, int len);
int			get_next_line(int fd, char **line);
char		*ft_strdup(const char *s);

#endif
