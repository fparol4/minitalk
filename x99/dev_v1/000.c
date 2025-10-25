
void	w_str(char *s)
{
	while (*s)
		write(1, s++, 1);
}
