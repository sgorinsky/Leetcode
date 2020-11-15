
class OrderedStream {
    var stream: [String]
    var idx = 1
    init(_ n: Int) {
        stream = [String](repeating: "", count: 1001)
    }
    
    func insert(_ id: Int, _ value: String) -> [String] {
        stream[id] = value
        var res = [String]()
        var i = idx
        while stream[i] != "" {
            res.append(stream[i])
            i += 1
        }
        idx = i
        return res
    }
}

/**
 * Your OrderedStream object will be instantiated and called as such:
 * let obj = OrderedStream(n)
 * let ret_1: [String] = obj.insert(id, value)
 */
