/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 10:45:03 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/02 13:53:05 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <wchar.h>

# include <stdio.h>

# define BUFF_SIZE 50000

typedef struct		s_gnl
{
	char			*text;
	char			*tempo;
	struct s_gnl	*next;
	int				fd;
}					t_gnl;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_realloc(void *ptr, size_t newsize);

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strdup_c(const char *s1, char c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcpy_c(char *dst, const char *src, char c);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

int					ft_atoi(const char *str);
long				ft_atol(const char *str);
long long			ft_atoll(const char *str);
unsigned long long	ft_atoull(const char *str);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr_n(const char *s, int n);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strnew(size_t size);
char				**ft_strnew_two(size_t x, size_t y);
char				***ft_strnew_three(size_t x, size_t y, size_t z);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_itoa_base(unsigned long long int n, char *base);

void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr_n(long long int nb, int n);
void				ft_putnbr_base(unsigned long long int n, char *base);
void				ft_putnbr_lng(long long int n);
void				ft_putnbr_uns(unsigned long long int n);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_islower(int c);
int					ft_isspace(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);
int					ft_isupphexa(int c);
int					ft_islowhexa(int c);
int					ft_isalhexa(int c);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_create_elem(void *content);
void				ft_list_push_back(t_list **begin_list, void *content);
void				ft_list_push_front(t_list **begin_list, void *data);
size_t				ft_list_size(t_list *begin_list);
t_list				*ft_list_last(t_list *begin_list);
t_list				*ft_list_push_params(int ac, char **av);
void				ft_list_clear(t_list **begin_list);
t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);
void				ft_list_reverse(t_list **begin_list);
void				ft_list_foreach(t_list *begin_list, void (*f)(void *));
void				ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *content_ref, int (*cmp)());
t_list				*ft_list_find(t_list *begin_list, void *data_ref,
		int (*cmp)());
void				ft_list_remove_if(t_list **begin_list, void *content_ref,
		int (*cmp)());
void				ft_list_merge(t_list **begin_list1, t_list *begin_list2);
t_list				*ft_list_sort(t_list *lst, int (*cmp)());

int					get_next_line(const int fd, char **line);

int					ft_abs(int nb);
void				ft_putwchar(wchar_t c);
void				ft_putwstr(wchar_t const *str);
void				ft_putwstr_n(wchar_t *str, int n);
int					ft_wcharlen(wchar_t c);
size_t				ft_strwlen(const wchar_t *s);
size_t				ft_strwlen_n(const wchar_t *s, int n);

void				ft_print_hex(size_t n);
unsigned char		ft_swap_bits(unsigned char octet);
void				ft_print_bits(unsigned char octet);
int					ft_max(int *tab, unsigned int len);
int					ft_min(int *tab, unsigned int len);

size_t				ft_tabintlen(int *tab);

int					*ft_tabnew(size_t size);
int					**ft_tabnew_two(size_t x, size_t y);
int					***ft_tabnew_three(size_t x, size_t y, size_t z);

int					ft_nbrlen(long long int nb);
int					ft_nbrlen_binary(unsigned long long int nb);
int					ft_nbrlen_octal(unsigned long long int nb);
int					ft_nbrlen_hexa(unsigned long long int nb);
int					ft_nbrlen_uns(unsigned long long int nb);

int					ft_nbrcmp(size_t nb1, size_t nb2);
int					ft_nbcmp_min(int nb1, int nb2);
int					ft_nbcmp_max(int nb1, int nb2);

int					ft_iseven(int nb);
int					ft_ismultiple(int nb, int mlt);
int					ft_size_tab_base(size_t n, int base);
int					ft_count_words_sep(char const *s, char c);
size_t				ft_strlen_sep(char const *s, char c);
char				*ft_strrev(char *str);
void				ft_swap(int *a, int *b);
int					ft_sqrt(int nb);
int					*ft_range(int min, int max);
int					ft_hex_to_dec(char *hex);
void				ft_putmap(char **map);

#endif
