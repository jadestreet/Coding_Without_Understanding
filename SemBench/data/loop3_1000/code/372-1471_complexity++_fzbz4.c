int putchar( int );
int main( void )
{
	char *a = "BizFub";
	int b = 0;
	while ( b++ < 100 )
	{
		short c = 0x2213;	
		short d = 0x2240;	
		int e = 0x22452213;	
		if ( !(b%15) )
			while ( putchar(a[e&0xF]) && (e>>=4) );
		else if ( !(b%3) )
			while ( putchar(a[c&0xF]) && (c>>=4) );
		else if ( !(b%5) )
			while ( putchar(a[d&0xF]) && (d>>=4) );
		else if( b > 9 )
		{
			putchar(b/10+'0');
			putchar(b%10+'0');
		}
		else
			putchar(b+'0');
		putchar('\n');
	}
	return 0;
}