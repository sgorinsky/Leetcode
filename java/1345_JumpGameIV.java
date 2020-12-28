class Solution {
    public int minJumps(int[] arr) {
        HashMap<Integer, List<Integer>> graph = new HashMap<Integer, List<Integer>>();
        for (int i = 0; i < arr.length; ++i) {
            List<Integer> tmp;
            if (graph.get(arr[i]) == null) {
                tmp = new ArrayList<Integer>();
            } else {
                tmp = graph.get(arr[i]);
            }
            tmp.add(i);
            graph.put(arr[i], tmp);
        }
        
        int count = 0;
        List<Integer> nodes = new ArrayList<Integer>() {{ add(0); }};
        boolean[] visited = new boolean[arr.length];
        while (!nodes.isEmpty()) {
            List<Integer> nextNodes = new ArrayList<Integer>();
            for (int node : nodes) {
                if (node == arr.length - 1) return count;

                for (int nei : graph.get(arr[node])) {
                    if (!visited[nei]) {
                        visited[nei] = true;
                        nextNodes.add(nei);
                    }
                }
                
                for (int nei : new int[]{node - 1, node + 1}) {
                    if (nei >= 0 && nei < arr.length && !visited[nei]) {
                        visited[nei] = true;
                        nextNodes.add(nei);
                    }
                }
                
                graph.put(arr[node], new ArrayList<Integer>());
            }
            
            nodes = nextNodes;
            count++;
        }
        return -1;
    }
}
