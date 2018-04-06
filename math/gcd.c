int gcd(int a, int b)
{
  int i, ans = 0;
  for(i = 1; i <= a && i <= b; ++i){
    if((a % i) == 0 && (b % i) == 0)
      ans = i;
  }
  return ans;
}
