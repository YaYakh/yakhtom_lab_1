# include<stdio.h>
# include<stdlib.h>
# include<math.h>

int main()
{
  int n = 0;
  double l = 0.0;
  double u = 0.0;
  double sum = 0;
  int pi = 1;
  double p = 0;
  double a = 0;

  double* mas;
  mas = (double*)malloc(n * sizeof(double));
  int* mas2;
  mas2 = (int*)malloc(n * sizeof(int));

  printf(" n = ");
  scanf_s(" %d", &n);
  if (n <= 0) {
    printf("error n <= 0");
    return 0;
  }

  printf(" min = ");
  scanf_s(" %lf", &l);

  printf(" max = ");
  scanf_s(" %lf", &u);

  if (l >= u) {
    printf("error min >= max");
    return 0;
  }

  for (int i = 0; i < n; i++)
  {
    p = (((((double)rand()) / RAND_MAX) * (u - l) + l) * 1000);
    mas[i] = floor(p) / 1000;
    mas2[i] = round(modf(mas[i], &a) * 1000);
  }

  for (int i = 0; i < n; i++)
  {
    pi = 1;
    for (int k = 0; k < n; k++)
    {
      if (i == mas2[k])
        pi = 0;

    }
    if (pi)
      sum = sum + mas[i];
    else
      sum = sum - mas[i];
  }
  printf("\n\n sum = %.3lf", sum);

  free(mas);
  return 0;
}