class Solution {
    public String reformatNumber(String number) {
        String s = number.replaceAll("[^0-9]", "");
        StringBuilder sb = new StringBuilder(s);
        if (s.length() == 2 || s.length() == 3) return s;
        if (s.length() == 4) return s.substring(0,2) + "-" + s.substring(2);
        int n = s.length() / 3;
        for (int i = 1; i < n; i++) sb.insert(4*i-1,'-');
        if (sb.lastIndexOf("-") == sb.length() - 5 || sb.lastIndexOf("-") == sb.length() - 6) 
            sb.insert(sb.length()-2,'-');
        return sb.toString();
    }
}
