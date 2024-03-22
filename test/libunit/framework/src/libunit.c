/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <htam@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 21:26:15 by htam              #+#    #+#             */
/*   Updated: 2024/02/04 16:01:49 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libunit.h"

void	load_test(t_unit_test **list, char *test_fun,
					char *test_name, t_test_function f)
{
	t_unit_test	*new_test;
	t_unit_test	*test;

	new_test = malloc(sizeof(t_unit_test));
	if (!new_test)
	{
		ft_printf("Cannot load new test\n\n");
		free_exit(*list, 1);
	}
	new_test->fun = f;
	new_test->test_fun = test_fun;
	new_test->test_name = test_name;
	new_test->next = NULL;
	test = *list;
	if (!test)
	{
		*list = new_test;
		return ;
	}
	while (test->next)
		test = test->next;
	test->next = new_test;
}

int	tester(t_unit_test *test, t_unit_test *head)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid < 0)
	{
		ft_printf("fork error\n");
		free_exit(head, 1);
	}
	if (pid == 0)
	{
		signal (SIGALRM, exit);
		alarm(TOUT);
		child_logger(test->test_fun);
		status = test->fun();
		free_exit(head, status);
	}
	else
	{
		wait(&status);
		return (w_check(status));
	}
	return (-2);
}

int	output(int test_result, char *fun, char *name)
{
	if (test_result == 0)
	{
		ft_printf("%s : %s : [%s]\n", fun, name, GREEN"OK"RESET);
		return (1);
	}
	if (test_result == 255)
		ft_printf("%s : %s : [%s]\n", fun, name, RED"KO"RESET);
	else if (test_result == SIGSEGV)
		ft_printf("%s : %s : [%s]\n", fun, name, RED"SIGSEGV"RESET);
	else if (test_result == SIGBUS)
		ft_printf("%s : %s : [%s]\n", fun, name, RED"SIGBUS"RESET);
	else if (test_result == SIGABRT)
		ft_printf("%s : %s : [%s]\n", fun, name, RED"SIGABRT"RESET);
	else if (test_result == SIGFPE)
		ft_printf("%s : %s : [%s]\n", fun, name, RED"SIGFPE"RESET);
	else if (test_result == SIGPIPE)
		ft_printf("%s : %s : [%s]\n", fun, name, RED"SIGPIPE"RESET);
	else if (test_result == SIGILL)
		ft_printf("%s : %s : [%s]\n", fun, name, RED"SIGILL"RESET);
	else if (test_result == SIGALRM)
		ft_printf("%s : %s : [%s]\n", fun, name, RED"TIMEOUT"RESET);
	else
		ft_printf("%s : %s : [%s]\n", fun, name, RED"UNKNOWN"RESET);
	return (0);
}

int	launch_test(t_unit_test **list)
{
	t_unit_test	*test;
	int			total_test;
	int			passed_test;
	int			test_result;

	total_test = 0;
	passed_test = 0;
	test = *list;
	while (test)
	{
		test_result = tester(test, *list);
		total_test += 1;
		passed_test += output(test_result, test->test_fun, test->test_name);
		parent_logger(test, test_result);
		test = test->next;
	}
	ft_printf("%d/%d tests checked\n", passed_test, total_test);
	free_list(*list);
	if (passed_test == total_test)
		return (0);
	return (-1);
}
