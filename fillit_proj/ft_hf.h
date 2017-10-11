/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:19:02 by abadraja          #+#    #+#             */
/*   Updated: 2016/11/21 16:35:10 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HF_H
# define FT_HF_H
# define BUF_SIZE		21
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef	struct	s_tetr
{
	char		let;
	int			width;
	int			height;
	char		**content;
}				t_tetr;
typedef struct	s_tab
{
	char		**tab;
	int			size;
}				t_tab;
typedef struct	s_vector2
{
	int			x;
	int			y;
}				t_vector2;
void			ft_exit_werror(char *text);
int				ft_b(char c);
t_vector2		*ft_new_vector2(int x, int y);
int				ft_lstlen(t_list *list);
void			ft_lstrev(t_list **alst);
t_list			*ft_parse(int fd);
void			ft_free_tab(t_tab *tab);
t_tab			*ft_tab_inst(int size);
int				ft_try(t_tetr *tet, t_tab *tab, int x, int y);
void			ft_remove(t_tetr *tet, t_tab *tab, t_vector2 *point);
t_list			*ft_lstfree(t_list *lst);
void			ft_check_tet(char *t);
t_tetr			*ft_prepare_tet(char **t, char let);
char			**ft_tetrimino_to_bitab(char *str);
void			ft_lstrev(t_list **alst);
int				ft_count_elements(char *str);
void			ft_check(char *str);
#endif
