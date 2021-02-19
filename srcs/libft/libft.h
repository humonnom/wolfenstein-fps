/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jackjoo <jackjoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:54:19 by juepark           #+#    #+#             */
/*   Updated: 2021/02/19 13:17:50 by jackjoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				ft_del(void *target);
void				*ft_free(void *target);
double				ft_max(double x, double y);
double				ft_min(double x, double y);
int					ft_cumulate(int x);

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *str, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

void				*ft_calloc(size_t count, size_t size);

void				ft_bzero(void *s, size_t n);

char				*ft_strchr(const char *s, int c);
int					ft_strchr_i(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *str, const char *target,
								size_t len);
char				*ft_strdup(const char *s1);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strncmp_reverse(const char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);

int					ft_toupper(int c);
int					ft_tolower(int c);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_spaceskip(const char *s, int *i);
int					ft_isoverflow(long long small, long long big);

int					ft_atoi(const char *str);
int					ft_atoiskip(const char *s, int *i);
char				*ft_itoa(int nbr);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *str, char c);

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **pointer, t_list *new);
int					ft_lstsize(t_list *head);
t_list				*ft_lstlast(t_list *head);
void				ft_lstadd_back(t_list **pointer, t_list *new);
void				ft_lstdelone(t_list *target, void (*del)(void *));
void				ft_lstclear(t_list **pointer, void (*del)(void *));
void				ft_lstiter(t_list *node, void (*f)(void *));
t_list				*ft_lstmap(t_list *origin, void *(*f)(void *),
							void (*del)(void *));

#endif
