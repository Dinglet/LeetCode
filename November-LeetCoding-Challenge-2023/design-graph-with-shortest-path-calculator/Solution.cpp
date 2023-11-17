#include <vector>
#include <map>
#include <queue>
#include <limits>

using namespace std;

typedef int Node;

class Path
{
public:
    int from;
    int to;
    int cost;
    Path(int from, int to, int cost)
    {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
    bool operator<(const Path& rhs) const
    {
        return cost < rhs.cost;
    }
    bool operator>(const Path& rhs) const
    {
        return cost > rhs.cost;
    }
};

class Graph
{
public:
    Graph(int n, vector<vector<int>>& edges)
    {
        this->n = n;
        for (auto edge : edges)
        {
            addEdge(edge);
        }
    }
    
    void addEdge(vector<int> edge)
    {
        graph[edge[0]].push_back({edge[0], edge[1], edge[2]});
    }
    
    int shortestPath(int src, int dst)
    {
        vector<bool> visited(n, false);
        vector<Node> distance(n, numeric_limits<int>::max());
        priority_queue<Path, vector<Path>, greater<Path>> pq;

        distance[src] = 0;
        pq.push({src, src, 0});

        while (!pq.empty())
        {
            Path path = pq.top();
            pq.pop();

            if (visited[path.to] == true)
            {
                continue;
            }

            visited[path.to] = true;

            for (auto edge : graph[path.to])
            {
                if (!visited[edge.to] && distance[edge.to] > distance[edge.from] + edge.cost)
                {
                    distance[edge.to] = distance[edge.from] + edge.cost;
                    pq.push({edge.from, edge.to, distance[edge.to]});
                }
            }
        }

        return distance[dst] == numeric_limits<int>::max() ? -1 : distance[dst];
    }

private:
    int n;
    map<int, vector<Path>> graph;
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */