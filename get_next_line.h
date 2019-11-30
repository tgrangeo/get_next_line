/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tgrangeo <tgrangeo@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 12:08:12 by tgrangeo     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 12:17:56 by tgrangeo    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>

char		*ft_strndup(const char *s, int len);
int			ft_strlen(const char *str);
char		*ft_strjoin(char *s1, char const *s2);
int			ft_strchr(const char *s, int c);
char		*ft_substr(char *s, int start, int len);
int			get_next_line(int fd, char **line);
char		*ft_strdup(char *s);

#endif
