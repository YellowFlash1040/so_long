#ifndef STRING_H
# define STRING_H

# include <stdbool.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		index_of(char c, char *str);
int		last_index_of(char c, char *str);
bool	ft_strcmp(char *s1, char *s2);
char	*ft_strdup(char *str);

#endif