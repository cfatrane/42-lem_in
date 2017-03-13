/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfatrane <cfatrane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 13:48:28 by cfatrane          #+#    #+#             */
/*   Updated: 2017/03/13 13:48:39 by cfatrane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int		ft_modify(t_lem_in *env)
{
	int		hash_tmp;
	int		flag = 0;
//	int		i = 0;
	t_rooms	*tmp_1;
	t_rooms	*tmp_2;
	t_rooms	*tmp_3;
	t_rooms	*tmp;

	tmp_1 = env->rooms;
	while (tmp_1)
	{
		tmp_2 = tmp_1->next;
		hash_tmp = tmp_1->hash;
		while (tmp_2)
		{
			if (hash_tmp == tmp_2->hash)
			{
				ft_printf("|Name = %s Hash = %d| avec |Name = %s Hash = %d|\n", tmp_1->name, tmp_1->hash, tmp_2->name, tmp_2->hash);
			//	ft_printf("|Name = %s Hash = %d| avec |Name = %s Hash = %d| COLLISION\n", tmp_1->name, tmp_1->hash, tmp_2->name, tmp_2->hash);
				while (1)
				{
//					tmp_2 = env->rooms;
//					hash_tmp = tmp_2->hash;
					while (tmp_2)
					{
						tmp_2->hash++;
						hash_tmp = tmp_2->hash;
						tmp_3 = tmp_2->next;
						while (tmp_3)
						{
//							ft_printf("LA tmp3 hash = %d\n", tmp_3->hash);
							if (hash_tmp == tmp_3->hash)
								break ;
							if (tmp_3->next == NULL)
								flag = 1;
							tmp_3 = tmp_3->next;
						}
						ft_printf("name = %s hash = %d\n", tmp_2->name, tmp_2->hash);
//						ft_printf("FIN\n");
					/*	if (tmp_2->hash )
						{
						}*/
						if (flag == 1)
							tmp_2 = tmp_2->next;
						tmp = tmp_2;
						while (tmp)
						{
//							ft_printf("ISSOU\n");
							tmp = tmp->next;
						}
					}
					break ;
				}
//				return (-1);
			}
			ft_printf("AFTER BREAK\n");
			if (tmp_2->next == NULL)
				break ;
			ft_printf("AFTER BREAK 2\n");
			tmp_2 = tmp_2->next;
		}
		tmp_1 = tmp_1->next;
	}
	return (0);
}
