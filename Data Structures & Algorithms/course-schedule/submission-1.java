class Solution {

    private int n;
    private ArrayList<Integer>[] graph;
    
    private boolean topo(int[] indegrees)
    {
        // khan algorithm
        Queue<Integer> q = new LinkedList<>();
        
        for(int i=0;i<n;i++)
        {
            if(indegrees[i] == 0)
            {
                q.add(i);
            }
        }
        
        int tasks = n;
        //  case of cycles ? num of componenets??
        while(!q.isEmpty())
        {
            int node = q.peek();
            q.poll();
            tasks--;
            
            for(var child:graph[node])
            {
                indegrees[child]--;
                if(indegrees[child] == 0)
                {
                    q.add(child);
                }
            }
        }
        
        return tasks == 0;
        
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        
        this.n = numCourses;
        this.graph = new ArrayList[numCourses+1];


        for(int i=0;i<n;i++)
            graph[i] = new ArrayList<>(); 
        
        int[] indegrees = new int[numCourses+1];
        
        for(int i=0;i<prerequisites.length;i++)
        {
            graph[prerequisites[i][1]].add(prerequisites[i][0]);
            indegrees[prerequisites[i][0]]++;
        }
        
        return topo(indegrees);
    }
}
