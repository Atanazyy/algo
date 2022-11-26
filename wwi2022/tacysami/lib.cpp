// Przykłdaowa biblioteka do zadania Tacy sami

#include "zaw.h"

#include <iostream>
#include <utility>
#include <vector>

int
main ()
{
  int t;
  std::cin >> t;
  for (int i = 0; i < t; ++i)
    {
      int n;
      std::cin >> n;

      std::vector<std::pair<double, double>> a (n);
      std::vector<std::pair<double, double>> b (n);

      for (int i = 0; i < n; ++i)
        std::cin >> a[i].first >> a[i].second;
      for (int i = 0; i < n; ++i)
        std::cin >> b[i].first >> b[i].second;

      if (tacySami (a, b))
        std::cout << "TAK\n";
      else
        std::cout << "NIE\n";
    }
}
