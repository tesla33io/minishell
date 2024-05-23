/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astavrop <astavrop@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:29:54 by astavrop          #+#    #+#             */
/*   Updated: 2024/05/24 22:10:27 by astavrop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* DEQUE */

typedef struct s_deque			t_deque;
typedef struct s_deque_node		t_deque_node;

// typedef int						t_deque_type;
typedef void *					t_deque_type;

struct							s_deque_node
{
	t_deque_node				*prev;
	t_deque_node				*next;
	t_deque_type				data;
};

struct							s_deque
{
	t_deque_node				*head;
	size_t						size;
};

t_deque_type	deque_back(t_deque *deque);
t_deque_type	deque_front(t_deque *deque);
void			deque_emplace_back(t_deque *deque, t_deque_type data);
void			deque_emplace_front(t_deque *deque, t_deque_type data);
void			deque_push_back(t_deque *deque, t_deque_node *node);
void			deque_push_front(t_deque *deque, t_deque_node *node);
t_deque_node	*deque_pop_back(t_deque *deque);
t_deque_node	*deque_pop_front(t_deque *deque);

/* HASH TABLE */

# define TABLE_SIZE 500

typedef struct s_kv
{
	char		*k;
	void		*v;
	struct s_kv	*n;
}				t_kv;

unsigned int	hash(char *key);

void			ht_set(t_kv ht[TABLE_SIZE], char *key, void *value);
char			*ht_get(t_kv ht[TABLE_SIZE], char *key);
t_kv			*ht_init(void);
void			ht_destroy(t_kv ht[TABLE_SIZE]);
void			ht_copy(t_kv src_ht[TABLE_SIZE], t_kv dest_ht[TABLE_SIZE]);

char			**ht_get_keys(t_kv ht[TABLE_SIZE]);
size_t			ht_len(t_kv ht[TABLE_SIZE]);
void			ht_clear(t_kv ht[TABLE_SIZE]);

/* /HASH TABLE */

/* MEMORY */

void			*ft_malloc(t_deque *gc, size_t size);
void			ft_free_gc(t_deque *gc);
void			ft_free_ptr(void *ptr);

int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_strlen(const char *s);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, void const *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dest, const char *src, size_t dstsize);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *str, char c);
char			*ft_strrchr(const char *str, char c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
void			*ft_memchr(const void *src, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(char *big, char *little, size_t len);
long			ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_lft_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
void			ft_strarray_free(char **array);
char			**ft_strarray_alloc(int	str_num);

#endif // !LIBFT_H
