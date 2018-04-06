double power(double base, int exp)
{
  double ans = 1;
  while (exp != 0){
    ans *= base;
    --exp;
  }
  return ans;
}
