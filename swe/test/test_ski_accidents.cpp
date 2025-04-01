#include "../ski_accidents.hpp"

#include <stdexcept>
#include <string>
#include <iostream>

namespace test
{

  void check(unsigned n, std::vector<std::pair<unsigned, unsigned>> connections, std::vector<unsigned> removable_vertices)
  {
    std::set<unsigned> removable_set(removable_vertices.begin(), removable_vertices.end());
    std::vector<std::pair<unsigned, unsigned>> reduced_connections;

    for (auto const [u, v] : connections) {
      if (removable_set.count(u) || removable_set.count(v)) {
        continue;
      }

      reduced_connections.emplace_back(u, v);
    }

    std::vector<unsigned> in_degree(n, 0);
    std::vector<unsigned> out_degree(n, 0);

    for (auto const [u, v] : reduced_connections) {
      in_degree[v - 1]++;
      out_degree[u - 1]++;
    }

    for (unsigned i = 0; i < n; i++) {
      if (in_degree[i] > 0 && out_degree[i] > 0) {
        throw std::runtime_error("vertex " + std::to_string(i + 1) + " has in-degree and out-degree > 0");
      }
    }
  }

  void maximum_edges()
  {
    int n = 4;

    std::vector<std::pair<unsigned, unsigned>> connections = {
      {1, 2},
      {1, 3},
      {1, 4},
      {2, 3},
      {2, 4},
      {3, 4}
    };

    ski_accidents::ski_track track(n);
    for (auto const [u, v] : connections)
    {
      track.add_directed_edge(u, v);
    }

    check(n, connections, track.get_removable_vertices());
  }

  void miscellaneous()
  {
    int n = 7;

    std::vector<std::pair<unsigned, unsigned>> connections = {
      {1, 2},
      {1, 3},
      {2, 4},
      {2, 5},
      {3, 6},
      {3, 7}
    };

    ski_accidents::ski_track track(n);
    for (auto const [u, v] : connections)
    {
      track.add_directed_edge(u, v);
    }

    check(n, connections, track.get_removable_vertices());
  }
} // test

int main()
{
  test::maximum_edges();
  test::miscellaneous();

  std::cout << "All tests passed" << std::endl;
}