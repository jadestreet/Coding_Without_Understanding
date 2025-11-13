#include <unistd.h>
#include <stdio.h>
int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}
int g_size;
int		find_start_block_wide(int step)
{
	int basic_root;
	int it;
	if (step == 0)
		return 0;
	if (step == 1)
		return 10;
	if (step == 2)
		return 22;
	if (step == 3)
		return 38;
	basic_root = 10 + step * 2;
	it = 4;
	while (it < step)
	{
		it += 2;
		basic_root += 2;
	}
	return find_start_block_wide(step - 1) + basic_root;
}
void	print_sastantua(int max_symbols_in_raw, int curr_symbols_in_raw, int block_it, int block_raw_it)
{
	int time_to_place_doors;
	int door_wide;
	for (int i = 0; i < (find_start_block_wide(g_size - 1) + 4 +
		(g_size - 1) * 2 + 2) / 2 - max_symbols_in_raw / 2; i++)
		ft_putchar(' ');
	for (int block_wide_it = 0; block_wide_it < (max_symbols_in_raw - curr_symbols_in_raw)
		/ 2 + curr_symbols_in_raw; block_wide_it++)
	{
		time_to_place_doors = 2;
		if (g_size % 2 == 0)
			time_to_place_doors = 3;
		door_wide = g_size;
		if (g_size % 2 == 0)
			door_wide--;
		if (block_wide_it < (max_symbols_in_raw - curr_symbols_in_raw) / 2)
			ft_putchar(' ');
		else if (block_wide_it == (max_symbols_in_raw - curr_symbols_in_raw) / 2)
			ft_putchar('/');
		else if (block_wide_it == (max_symbols_in_raw - curr_symbols_in_raw) / 2 + curr_symbols_in_raw - 1)
			ft_putchar('\\');
		else if (block_it == g_size - 1 && block_raw_it >= time_to_place_doors + door_wide / 2
			&& block_raw_it < time_to_place_doors + door_wide / 2 + 1
			&& block_wide_it > max_symbols_in_raw / 2 - door_wide / 2 + door_wide - 3
			&& block_wide_it <= max_symbols_in_raw / 2 - door_wide / 2 + door_wide - 2)
			ft_putchar('$');
		else if (block_it == g_size - 1 && block_raw_it > time_to_place_doors - 1 && block_wide_it > max_symbols_in_raw / 2 - door_wide / 2 - 1 && block_wide_it < max_symbols_in_raw / 2  + door_wide / 2 + 1)
			ft_putchar('|');
		else
			ft_putchar('*');
	}
	ft_putchar('\n');
}
void	sastantua(int size)
{
	g_size = size;
	for(int block_it = 0; block_it < size; block_it++)
	{
		for (int block_raw_it = 0; block_raw_it < 3 + block_it; block_raw_it++)
		{
			print_sastantua(find_start_block_wide(block_it) + block_it * 2 + 7,
				find_start_block_wide(block_it) + block_raw_it * 2 + 3, block_it, block_raw_it);			
		}
	}
}
int main()
{
	sastantua(5);	
}