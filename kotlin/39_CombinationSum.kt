class Solution {
    var results: MutableList<MutableList<Int>> = MutableList(0){MutableList(0){0}}
    fun combinationSum(candidates: IntArray, target: Int): List<List<Int>> {
        fun combine(idx: Int, sum: Int, currAttempt: MutableList<Int>) {
            if (sum == target) {
                results.add(currAttempt.toMutableList())
                return
            } else if (sum > target) {
                return
            }
            for (i in idx until candidates.size) {
                var temp = MutableList(currAttempt.size){it->currAttempt[it]}
                temp.add(candidates[i])
                combine(i, sum + candidates[i], temp)
            }
        }
        combine(0, 0, mutableListOf())
        return results
    }
}
