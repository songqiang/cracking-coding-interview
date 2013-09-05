/*
 * Song Qiang <qiang.song@usc.edu> 
 *
 */

/*

Given a directed graph, design an algorithm to find out whether there
is a route be- tween two nodes.

 */

// adjacency matrix
bool
is_connected(const vector<vector<bool> > &g,
             const size_t v1, const size_t v2)
{
    if (v1 == v2) return true;
    
    vector<bool> visited(g.size(), false);
    vector<size_t> vertices;

    visited[v1] = true;
    vertices.push_back(v1);
    
    while (!vertices.empty())
    {
        const size_t v = vertices.back();
        vertices.erase(vertices.end() - 1);

        for (size_t i = 0; i < g.size(); ++i)
            if (!visited[i] && g[v][i])
            {
                if (i == v2) return true;
                visited[i] = true;
                vertices.push_back(i);
            }
    }
    return false;
}


