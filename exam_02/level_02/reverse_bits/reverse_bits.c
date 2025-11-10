unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	r;
	int		i;

	r = 0;
	i = 8;
	while (i-- > 0)
	{
		r = (r * 2) + (octet % 2);
		octet = octet / 2;
	}
	return(r);
}
