class Pair implements Comparable<Pair> {

    int first;
    int second;
    Pair(){}
    Pair(int first,int second)
    {
        this.first = first;
        this.second = second;
    }

    @Override
    public int compareTo(Pair o) {
        if(o.first == this.first)
            return Integer.compare(this.second,o.second);
        else
            return Integer.compare(this.first,o.first);
    }
}

class Solution {

    private int n;

    private Map<Integer, Integer> solve(ArrayList<Pair>[] graph, int src)
    {
        boolean[] vis = new boolean[n+1];
        int[] dist = new int[n+1];

        for(int i=0;i<n;i++)
            dist[i] = Integer.MAX_VALUE;

        // min heap
        PriorityQueue<Pair> pq = new PriorityQueue<>();

        pq.offer(new Pair(0,src));
        dist[src] = 0;

        while(!pq.isEmpty())
        {
            int cost = pq.peek().first;
            int node = pq.peek().second;
            pq.poll();
            if(vis[node]) continue;

            vis[node] = true;

            for(var child : graph[node])
            {
                int childNode = child.first;
                int childCost = child.second;

                if(cost + childCost < dist[childNode])
                {
                    dist[childNode] = cost + childCost;
                    pq.offer(new Pair(dist[childNode],childNode));
                }
            }
        }

        Map<Integer, Integer> mp = new HashMap<>();
        for(int i=0;i<n;i++) {
            if (dist[i] == Integer.MAX_VALUE)
                dist[i] = -1;
            mp.put(i, dist[i]);
        }
        return mp;
    }



    public Map<Integer, Integer> shortestPath(int n, List<List<Integer>> edges, int src) {

        this.n = n;
        ArrayList<Pair>[] graph = new ArrayList[n+1];

        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for(var tuples: edges) {
            int u = tuples.get(0);
            int v = tuples.get(1);
            int w = tuples.get(2);
            graph[u].add(new Pair(v, w));
        }
        return solve(graph,src);
    }
}
