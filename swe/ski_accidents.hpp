#pragma once

#include "graph.hpp"

namespace ski_accidents
{

struct ski_track : cg::directed_acyclic_graph
{
  ski_track(unsigned num_vertices);

  // Returns a list of vertices that can be removed so that no path of
  // length two or more exists in the graph. Guaranteed to remove at most
  // 4n / 7 vertices, where n is the number of vertices in the graph. The
  // vertices are 1-indexed.
  std::vector<unsigned> get_removable_vertices() const;
};

} // ski_accidents
