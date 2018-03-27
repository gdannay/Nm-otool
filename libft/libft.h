/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdannay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:37:27 by gdannay           #+#    #+#             */
/*   Updated: 2018/03/21 17:12:26 by gdannay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <wchar.h>
# include <stdarg.h>
# include <inttypes.h>

# define BINA "01"
# define DECI "0123456789"
# define HEXAMIN "0123456789abcdef"
# define HEXAMAJ "0123456789ABCDEF"
# define OCTA "01234567"
# define BUFF_SIZE 4096

typedef struct			s_flag
{
	int					minus;
	int					plus;
	int					space;
	int					zero;
	int					hash;
	int					width;
	int					precision;
	int					length;
	char				type;
	int					inttype;
	int					intdisplay;
	long long			nb;
	unsigned long long	unb;
	char				*st;
	wchar_t				*wst;
	struct s_flag		*next;
}						t_flag;

typedef struct			s_type
{
	char				type;
	int					conv;
	int					display;
}						t_type;

typedef	struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

size_t					ft_strlcat(char *dst, const char *src, size_t size);
int						ft_atoi(const char *nbr);
void					ft_bzero(void *s, size_t n);
int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_isascii(int c);
int						ft_isdigit(int c);
int						ft_isprint(int c);
void					*ft_memccpy(void *dest, const void *src,
						int c, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memset(void *s, int c, size_t n);
char					*ft_strcat(char *dest, const char *src);
char					*ft_strchr(const char *s, int c);
int						ft_strcmp(const char *s1, const char *s2);
char					*ft_strcpy(char *dest, const char *src);
char					*ft_strdup(const char *s);
char					*ft_strndup(const char *s, size_t n);
size_t					ft_strlen(const char *s);
char					*ft_strncat(char *dest, const char *src, size_t n);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
char					*ft_strncpy(char *dest, const char *src, size_t n);
char					*ft_strnstr(const char *str,
						const char *need, size_t n);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *str, const char *need);
int						ft_tolower(int c);
int						ft_toupper(int c);
char					*ft_itoa(int n);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
void					ft_putchar(char c);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl(char const *s);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr(int n);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr(char const *s);
void					ft_putstr_fd(char const *s, int fd);
void					ft_strclr(char *s);
void					ft_strdel(char **as);
int						ft_strequ(char const *s1, char const *s2);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
						char (*f)(unsigned int, char));
int						ft_strnequ(char const *s1, char const *s2, size_t n);
void					*ft_memalloc(size_t size);
char					*ft_strnew(size_t size);
char					**ft_strsplit(char const *s, char c);
char					*ft_strsub(char const *s,
						unsigned int start, size_t len);
char					*ft_strtrim(char const *s);
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void					ft_lstdelone(t_list **alst,
						void (*del)(void *, size_t));
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void					ft_puttab(char **tab);
void					ft_lstappend(t_list **alst, t_list *new);
char					*ft_capitalize(char *s);
char					*ft_lowercase(char *s);
size_t					ft_lstsize(t_list *begin_list);
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstnew(void const *content, size_t content_size);
char					*ft_bchar(char c, size_t length);
char					*chartostr(long long c);
int						length_nbr(int n);
long long				atoi_base(char *str, char *input_b);
size_t					ft_wstrlen(wchar_t *str);
wchar_t					*ft_wstrdup(const wchar_t *str);
int						ft_printf(char *str, ...);
t_flag					*create_flag(void);
int						length_nbr(int n);
t_flag					*check_carac(char *str, int *i);
void					fill_wp(t_flag *tmp, va_list va);
void					check_width(char *str, int *i, t_flag *new, int *ret);
int						display(char *str, t_flag *flag);
char					*ltoa_base(t_flag *tmp, char *base);
char					*utoa_base(t_flag *tmp, char *base);
char					*chartostr(long long c);
int						display_flag(char *new, t_flag *tmp, char *buff);
int						manage_nb(t_flag *tmp, char *buff);
int						manage_string(t_flag *tmpa, char *buff);
int						manage_char(t_flag *tmp, char *buff);
char					*ft_bchar(char c, size_t length);
int						display_precision(char *buff, t_flag *tmp, int index);
int						display_width(char *buff, t_flag *tmp, int index);
int						correction_sign(char *new, t_flag *tmp, int index);
int						manage_uni(t_flag *tmp, char *buff);
int						compute_rep(char *c);
int						manage_wstring(t_flag *tmp, char *buff);
int						size_hexa(long long n);
int						display_0(t_flag *tmp, char *c, char *buff);
int						compute_rep(char *c);
void					check_width(char *str, int *i, t_flag *new, int *ret);
void					check_wp(char *str, int *i, t_flag *new);
void					free_lst(t_flag **flag);
int						print_buff(char *buff);
int						manage_buff(char *buff, char *str, size_t length);
int						add_right(char *buff, char *str,
						int index, size_t length);
int						add_char_right(char *buff, char c,
						int index, size_t length);
int						add_char_left(char *buff, char c,
						int *index, size_t length);
char					*ft_joinpath(char *dir, char *name);
char					**ft_tabdup(char **tab);
char					*ft_joinwchar(char *dir, char *name, char c);
char					**ft_strsplitspace(char const *s);
char					**ft_tabjoin(char **s1, char **s2);
size_t					ft_tablen(char **s);
size_t					ft_strlenwq(char *s, char quote);
char					*ft_strjoinwq(char *s1, char *s2, char quote);
char					*ft_strdupwq(char *s, char quote);
char					*ft_strndupwq(const char *s, size_t n);
long					ft_atol(const char *nbr);
void					ft_tabdel(char ***tab);
char					*ft_lltoa_base(uint64_t nb, char *base);

#endif
