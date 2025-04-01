#include "graph.hpp"

#include <stdexcept>

namespace cg
{
  graph::graph(unsigned num_vertices)
    : adj_(num_vertices)
    , num_vertices_(num_vertices)
  {
  }

  void graph::add_directed_edge(unsigned u, unsigned v)
  {
    --u, --v;

    if (u >= num_vertices_ || v >= num_vertices_)
    {
      throw std::out_of_range("vertex out of range");
    }

    adj_[u].push_back(v);
  }

  directed_acyclic_graph::directed_acyclic_graph(unsigned num_vertices)
    : graph(num_vertices)
    , in_degree_(num_vertices)
  {
  }

  void directed_acyclic_graph::add_directed_edge(unsigned u, unsigned v)
  {
    graph::add_directed_edge(u, v);
    ++in_degree_[v - 1];
  }

  std::vector<unsigned> directed_acyclic_graph::topological_sort() const
  {
    std::vector<unsigned> result;
    std::set<unsigned> visited;

    auto in_degree = in_degree_;

    // find the initial set of vertices with in-degree 0.
    for (unsigned i = 0; i < num_vertices_; ++i)
    {
      if (in_degree[i] == 0)
      {
        result.push_back(i);
        visited.insert(i);
      }
    }

    // repeatedly remove vertices with in-degree 0 and update the in-degrees of their neighbours
    for (unsigned i = 0; i < result.size(); i++) {
      for (unsigned v : adj_[result[i]]) {
        if (visited.find(v) == visited.end())
        {
          if (--in_degree[v] == 0)
          {
            result.push_back(v);
            visited.insert(v);
          }
        }
      }
    }

    for (auto& u : result) {
      u += 1;
    }

    return result;
  }
}