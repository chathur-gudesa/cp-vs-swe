#include "ski_accidents.hpp"

#include <iostream>

int main()
{
  int t;
  std::cin >> t;

  while (t--) {
    unsigned n, m;
    std::cin >> n >> m;

    ski_accidents::ski_track track(n);

    for (unsigned i = 0; i < m; i++) {
      int a, b;
      std::cin >> a >> b;

      track.add_directed_edge(a, b);
    }

    auto vertices = track.get_removable_vertices();

    std::cout << vertices.size() << std::endl;

    for (auto u : vertices) {
      std::cout << u << ' ';
    }

    std::cout << std::endl;
  }
}