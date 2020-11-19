class Solution {
    public String decodeString(String s) {
        Stack<Character> stack = new Stack<Character>();
        for (char c : s.toCharArray()) {
            if (c != ']') {
                stack.push(c);
            } else {
                List<Character> currentString = new ArrayList<Character>();
                while (!stack.isEmpty() && stack.peek() != '[') {
                    currentString.add(stack.pop());
                }
                
                stack.pop(); // remove '['
                int repeats = 0, power = 0;
                while (!stack.isEmpty() && stack.peek() - '0' >= 0 && stack.peek() - '0' <= 9) {
                    repeats = (stack.pop() - '0') * ((int) Math.pow(10, power++)) + repeats;
                    
                }
                
                for (int i = 0; i < repeats; ++i) {
                    for (int j = currentString.size() - 1; j >= 0; --j) {
                        stack.push(currentString.get(j));
                    }
                }
            }
        }
        char[] result = new char[stack.size()];
        for (int i = 0; i < stack.size(); ++i) {
            result[i] = stack.get(i);
        } 
        
        return new String(result);
    }
}

class Solution {
    public String decodeString(String s) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ']') {
                List<Character> decodedString = new ArrayList<>();
                
                // get the encoded string
                while (stack.peek() != '[') {
                    decodedString.add(stack.pop());
                }
                
                // pop [ from the stack
                stack.pop();
                
                int base = 1, k = 0;
                // get the number k
                while (!stack.isEmpty() && Character.isDigit(stack.peek())) {
                    k = k + (stack.pop() - '0') * base;
                    base *= 10;
                }
                // decode k[decodedString], by pushing decodedString k times into stack
                while (k != 0) {
                    for (int j = decodedString.size() - 1; j >= 0; j--) {
                        stack.push(decodedString.get(j));
                    }
                    k--;
                }
            }
            // push the current character to stack
            else {
                stack.push(s.charAt(i));
            }
        }      
        // get the result from stack
        char[] result = new char[stack.size()];
        for (int i = result.length - 1; i >= 0; i--) {
            result[i] = stack.pop();
        }
        return new String(result);
    }
}


