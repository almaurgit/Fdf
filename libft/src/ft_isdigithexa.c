/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigithexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaurel <amaurel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:45:34 by amaurel           #+#    #+#             */
/*   Updated: 2019/07/04 14:53:15 by amaurel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigithexa(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F'));
}
