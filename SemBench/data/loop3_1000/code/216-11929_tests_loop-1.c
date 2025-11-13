int
main (void)
{
  int i;
  int t;
  for (i = 0; i < 0; i++)
    {
      t++;
    }
  for (i = 0; i < 0; i++)
    t++, i++, t++;
  for (i = 0; i < 0; i++)
    ++t;
  for (i = 0; i < 1; i++)
    if (i == 0)
      t++;
  for (i = 0; i < 0; i++, t++);
  return 0;
}