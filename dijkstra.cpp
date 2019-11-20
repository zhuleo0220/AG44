 list<int> dijkstraShortestPath(int src, int dst,) {
        assert(src != dst);
        // vector<int> prev = dijkstra(src);
        vector<int> prev = dijkstra_priority_queue(src);        
        list<int> path;
        int u = dst;
        if (prev[u] != -1) {
            while (prev[u] != -1) {
                path.push_front(u);
                u = prev[u];    
            }
        }

        return path;
    }

    // dijkstra经典实现，算法复杂度O(|V|^2)
    vector<int> dijkstra(int source) {
        vector<int> prev;
        vector<int> dist;
        list<int> vlist;

        for (int i = 0; i < this->numVertices; ++i) {
            dist.push_back(INT_MAX);
            prev.push_back(-1);
            vlist.push_back(i);
        }
        dist[source] = 0;
 
        while (!vlist.empty()) {
            int u =  minVertexDistance(&vlist, &dist);
            vlist.remove(u);
            vector<int> neighbors = neighbor_vertices(u);
            for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
                int alt = dist[u] + distance(u, *it);
                if (alt < dist[*it]) {
                    dist[*it] = alt;
                    prev[*it] = u;
                }
            }
        }

        // 打印距离值
        for (int i = 0; i < numVertices; ++i) {
            cout << i << " : " << dist[i] << endl;
        }

         return prev;
    }

