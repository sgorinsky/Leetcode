class Solution {
    public boolean checkIfExist(int[] arr) {
        HashMap<Integer, Integer> numTable = new HashMap<Integer, Integer>();
        for (int n : arr) {
            numTable.put(n, numTable.get(n) == null ? 1 : numTable.get(n) + 1);
        }
        
        if (numTable.get(0) != null && numTable.get(0) > 1) 
            return true;
        
        for (int n : arr) {
            if (numTable.get(n*2) != null && n != 0) 
                return true;
        }
        return false;
    }
}
