/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsachie <hsachie@student.42.jp>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:23:37 by hsachie           #+#    #+#             */
/*   Updated: 2026/06/05 14:23:41 by hsachie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(void)
{
    t_stack a;
    t_stack b;
    t_node  node1;
    t_node  node2;
    t_node  node3;

    // ノードを手動で作る
    node1.value = 3;
    node2.value = 1;
    node3.value = 2;

    // つなぐ
    node1.next = &node2;
    node1.prev = NULL;
    node2.next = &node3;
    node2.prev = &node1;
    node3.next = NULL;
    node3.prev = &node2;

    // スタックaに入れる
    a.top = &node1;
    a.size = 3;

    // スタックbは空
    b.top = NULL;
    b.size = 0;

    // テスト
    sa(&a);   // 3,1,2 → 1,3,2
    sb(&b);   // bは空なので何もしない
    ss(&a, &b);

    return (0);
}