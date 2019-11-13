/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tgrangeo <tgrangeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 12:08:12 by jdel-ros     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 13:17:43 by tgrangeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>

char		*ft_strndup(const char *s, int len);
int			ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, int start, size_t len);