class TrieNode {
    var children: Dictionary<Character, TrieNode> = [Character : TrieNode]()
    var word: Bool = false;
}

class StreamChecker {
    var queue: [Character]
    var trie: TrieNode
    var queueEnd: Int = -1
    
    init(_ words: [String]) {
        queue = [Character]()
        trie = TrieNode()
        
        for w in words {
            var node = trie
            for (i, c) in w.enumerated().reversed() {
                if node.children[c] == nil {
                    node.children[c] = TrieNode()
                }
                node = node.children[c]!
            }
            node.word = true
        }
    }
    
    func query(_ letter: Character) -> Bool {
        queue.append(letter)
        queueEnd += 1
        var node: TrieNode = trie
        var c: Character
        
        for i in 0...queueEnd {
            c = queue[queueEnd-i]
            if node.children[c] != nil {
                node = node.children[c]!
            } else {
                break
            }
            if node.word {
                return true
            }
        }
        return node.word
    }
}

/**
 * Your StreamChecker object will be instantiated and called as such:
 * let obj = StreamChecker(words)
 * let ret_1: Bool = obj.query(letter)
 */
