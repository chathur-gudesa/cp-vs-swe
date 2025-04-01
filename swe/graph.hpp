#pragma once

#include <vector>
#include <set>

namespace cg
{

  // an adjacency list representation of a graph
  struct graph
  {
    graph(unsigned num_vertices);

    // Vertices should be numbered from 1 upwards.
    // Throws if vertices are out of range.
    virtual void add_directed_edge(unsigned u, unsigned v) noexcept(false);

  protected:
    std::vector<std::vector<int>> adj_;
    unsigned num_vertices_;
  };

  struct directed_acyclic_graph : public graph
  {
    directed_acyclic_graph(unsigned num_vertices);

    // Vertices should be numbered from 1 upwards.
    // Throws if vertices are out of range.
    // Precondition: adding the edge (u, v) should not create a cycle.
    virtual void add_directed_edge(unsigned u, unsigned v) noexcept(false) override;

    // the vertices are numbered from 1 upwards
    std::vector<unsigned> topological_sort() const;

  protected:
    std::vector<unsigned> in_degree_;
  };
}