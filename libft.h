/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra <ebezerra@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:31:31 by ebezerra          #+#    #+#             */
/*   Updated: 2023/01/05 20:52:03 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>

# define SPECIFIERS "cspdiuxX%"
# define FLAGS "-0# +"
# define PRECISION "."
# define STDOUT 1

typedef enum e_bool
{
	false_,
	true_
}			t_bool;

typedef struct s_formatted
{
	char	*str;
	int		length;
}			t_formatted;

typedef struct s_flags
{
	int		width;
	int		precision;
	t_bool	has_minus;
	t_bool	has_zero;
	t_bool	has_width;
	t_bool	has_precision;
	t_bool	has_hash;
	t_bool	has_space;
	t_bool	has_plus;
	t_bool	unknown_format;
	t_bool	default_precision;
	t_bool	has_error;
	t_bool	is_negative;
	t_bool	int_min;
	char	pad;
	char	specifier;
}			t_flags;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// Printf Functions
int		ft_printf(const char *format, ...)
		__attribute__((format(printf, 1, 2)));
int		ft_dprintf(int fd, const char *format, ...)
		__attribute__((format(printf, 2, 3)));
int		ft_vprintf(const char *format, va_list args);
int		ft_vdprintf(int fd, const char *format, va_list args);
int		init_flags(t_flags *flags);
void	format_string(const char *format, va_list args, t_formatted *fmt,
			t_flags *flags);
t_bool	validate_args(const char *format, t_flags *flags, va_list args);
void	add_default_precision_unknown_args(const char *format,
			t_formatted *fmt);
void	init_formatted_arg(va_list args, t_flags *flag, char **formatted_arg);
void	update_width(char *formatted_arg, t_flags *flags, int len);
void	update_precision(char *formatted_arg, t_flags *flags, int len);
void	append_args_and_flags(char *formatted_arg, t_formatted *fmt,
			t_flags *flags);
char	*char_to_str(int c);
void	append_width(t_formatted *fmt, t_flags *flags);
void	append_hash(t_formatted *fmt, t_flags *flags);
void	append_plus(t_formatted *fmt, t_flags *flags);
void	append_space(t_formatted *fmt, t_flags *flags);
void	append_precision(t_formatted *fmt, t_flags *flags);
void	join_char_to_fmt_str(t_formatted *fmt, const char **format,
			t_flags *flags);
// Libft Functions
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isxdigit(int c);
int		ft_isspace(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
int		ft_atoi_base(char *str, char *base);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *str, size_t n);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(size_t, char));
void	ft_striteri(char *s, void (*f)(size_t, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*ft_strdjoin(char *s1, const char *s2);
char	*ft_strd2join(char *s1, char *s2);
char	*ft_btoa(unsigned int nbr, char *base);
char	*ft_uitoa(unsigned int nbr);
char	*ft_ptoa(void *nbr, char *base);
char	*ft_specstrjoin(const char *s1, const char *s2, size_t s1_len,
			char specifier);
char	*ft_specstrdjoin(char *s1, const char *s2, size_t s1_len,
			char specifier);
char	*ft_specstrd2join(char *s1, char *s2, size_t s1_len,
			char specifier);
char	*get_next_line(int fd);
char	*ft_strchr2(const char *s, int c);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_getenv(const char *name);
void	free_str_array(char **str);
int		ft_strcmp(char *s1, char *s2);

#endif