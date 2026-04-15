#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_test_case
{
	const char	*label;
	char		*args;
	int			compact;
}t_test_case;

static int	count_operations(const char *file_path)
{
	FILE	*fp;
	char	buffer[4096];
	int	count;

	fp = fopen(file_path, "r");
	if (!fp)
		return (-1);
	count = 0;
	while (fgets(buffer, sizeof(buffer), fp) != NULL)
		count++;
	fclose(fp);
	return (count);
}

static int	run_command(const char *cmd)
{
	int	status;

	status = system(cmd);
	if (status != 0)
		return (1);
	return (0);
}

static char	*get_checker_result(const char *cmd)
{
	FILE	*pipe;
	char	line[64];
	char	*result;
	int		len;

	pipe = popen(cmd, "r");
	if (!pipe)
		return (NULL);
	if (!fgets(line, sizeof(line), pipe))
	{
		pclose(pipe);
		return (NULL);
	}
	pclose(pipe);
	len = (int)strlen(line);
	while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
		line[--len] = '\0';
	result = malloc((size_t)len + 1);
	if (!result)
		return (NULL);
	memcpy(result, line, (size_t)len + 1);
	return (result);
}

static char	*generate_unique_numbers(int size)
{
	int		*numbers;
	char	*args;
	int		i;
	int		j;
	int		tmp;
	size_t	used;
	int		written;

	numbers = malloc(sizeof(int) * (size_t)size);
	args = malloc((size_t)size * 14);
	if (!numbers || !args)
		return (free(numbers), free(args), NULL);
	i = 0;
	while (i < size)
	{
		numbers[i] = i + 1;
		i++;
	}
	srand(42);
	i = size - 1;
	while (i > 0)
	{
		j = rand() % (i + 1);
		tmp = numbers[i];
		numbers[i] = numbers[j];
		numbers[j] = tmp;
		i--;
	}
	used = 0;
	i = 0;
	while (i < size)
	{
		written = snprintf(args + used, (size_t)size * 14 - used,
				"%d%s", numbers[i], (i + 1 == size) ? "" : " ");
		if (written < 0)
			return (free(numbers), free(args), NULL);
		used += (size_t)written;
		i++;
	}
	free(numbers);
	return (args);
}

static void	run_test_case(t_test_case test)
{
	char	tmp_path[] = "/tmp/push_swap_ops_XXXXXX";
	char	cmd_push[10000];
	char	cmd_checker[10128];
	char	*checker_result;
	int		ops_count;
	int		fd;

	if (test.compact)
		printf("\nTestando com 100 numeros\n");
	else
		printf("\nTestando: %s\n", test.args);
	fd = mkstemp(tmp_path);
	if (fd < 0)
	{
		printf("Nao foi possivel criar arquivo temporario.\n");
		return ;
	}
	close(fd);
	snprintf(cmd_push, sizeof(cmd_push), "./push_swap %s > %s", test.args, tmp_path);
	if (run_command(cmd_push) != 0)
	{
		printf("Falha ao executar push_swap.\n");
		unlink(tmp_path);
		return ;
	}
	ops_count = count_operations(tmp_path);
	snprintf(cmd_checker, sizeof(cmd_checker), "./checker_linux %s < %s", test.args, tmp_path);
	checker_result = get_checker_result(cmd_checker);
	if (!checker_result)
		printf("Resultado do checker: KO\n");
	else
	{
		printf("Resultado do checker: %s\n", checker_result);
		free(checker_result);
	}
	printf("Numero de operacoes: %d\n", ops_count);
	unlink(tmp_path);
}

int	main(void)
{
	t_test_case	tests[5];
	char			*big_case;
	int				i;

	printf("Esse projeto foi feito como parte do curriculo academico de João Gabriel\n");
	printf("Push Swap é um programa que ordena uma lista de numeros com instruções ");
	printf("limitadas no menor número de operações possiveis. Ele usa um algoritmo ");
	printf("de radix/bitwise que ordena do bit menos significativo para o mais ");
	printf("significativo (LSB -> MSB).\n");
	big_case = generate_unique_numbers(120);
	if (!big_case)
		return (printf("Falha ao gerar caso grande.\n"), 1);
	tests[0] = (t_test_case){"curto-1", "3 2 1", 0};
	tests[1] = (t_test_case){"curto-2", "42 -10 0 7 3", 0};
	tests[2] = (t_test_case){"medio-1", "9 1 8 2 7 3 6 4 5", 0};
	tests[3] = (t_test_case){"medio-2", "50 4 33 12 89 1 23 77 2 65 31 18", 0};
	tests[4] = (t_test_case){"grande-120", big_case, 1};
	i = 0;
	while (i < 5)
	{
		run_test_case(tests[i]);
		i++;
	}
	free(big_case);
	return (0);
}
