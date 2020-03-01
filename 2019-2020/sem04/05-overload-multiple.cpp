void f(int a, int b);// {}
void f(double a, double b);// {}

int main()
{
  int vi;
  long vl;
  double vd;

  f(vi, vl);
  // f(int, int) : { 0, 1 }
  // f(double, double) : { 1, 1 }
  // { 0, 1 } < { 1, 1 }

  f(vd, vl);

  f(vd, vi);
  // f(int, int): { 1, 0 }
  // f(double, double) : { 0, 1 }
  // { 1, 0 } ? { 0, 1 }

  f(vl, vl);
  // { 1, 1 }
  // { 1, 1 }
  // { 1, 1 } == { 1, 1 }
  
  f(vl, vi);
  f(vl, vd);
}
