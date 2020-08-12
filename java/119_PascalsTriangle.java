class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> row = new ArrayList<Integer>(rowIndex+1){
            {
                add(1);
            }
        };
        
        
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = 1; j < i; ++j) {
                row.set(j, j <= i/2 ? row.get(j) + row.get(i-j) : row.get(i-j));
            }
            row.add(1);
        }
        return row;
    }
}

class Solution {
    public List<Integer> getRow(int n) {
        List<Integer> row = new ArrayList<>(){
            {
                add(1);
            }
        };
        
        for (int k = 1; k <= n; ++k) {
            row.add((int) ((row.get(row.size()-1) * (long) (n-k+1)) / k));
        }
        return row;
        
    }
}
