#include "ski_accidents.hpp"

namespace ski_accidents
{

ski_track::ski_track(unsigned num_vertices)
  : cg::directed_acyclic_graph(num_vertices)
{
}

std::vector<unsigned> ski_track::get_removable_vertices() const
{
  auto toposort = topological_sort();

  std::vector<bool> deleted(num_vertices_, false);
  auto in_degree = in_degree_;

  // Greedily remove vertices who have an in-edge form a vertex that has
  // in-degree > 0. This is guaranteed to leave the DAG without having any
  // paths of length 2 or more.
  for (unsigned i = 0; i < num_vertices_; i++)
  {
    auto u = toposort[i] - 1;

    if (deleted[u] || in_degree[u] == 0)
      continue;

    for (auto v : adj_[u])
    {
      if (deleted[v])
        continue;

      deleted[v] = true;

      for (auto w : adj_[v])
      {
        in_degree[w]--;
      }
    }
  }

  // TODO(cgudesa): Prove that we remove at most 4n / 7 vertices.
  std::vector<unsigned> result;
  for (unsigned i = 0; i < num_vertices_; i++)
  {
    if (deleted[i])
      result.push_back(i + 1);
  }

  return result;
}

} // ski_accidents