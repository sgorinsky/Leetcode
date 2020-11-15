class OrderedStream {
    int idx = 1;
    String[] stream;
    public OrderedStream(int n) {
        stream = new String[1001];
    }
    
    public List<String> insert(int id, String value) {
        stream[id] = value;
        List<String> res = new ArrayList<String>();
        int i = idx;
        while (stream[i] != null) {
            res.add(stream[i++]);
        }
        idx = i;
        return res;
    }
}
