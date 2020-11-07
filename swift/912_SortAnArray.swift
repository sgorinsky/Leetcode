class Solution {
    func sortArray(_ nums: [Int]) -> [Int] {
        func splitArrayInHalfAndMerge(_ startingIdx: Int, _ endingIdx: Int) -> [Int] {
            if startingIdx == endingIdx { return [nums[startingIdx]] }
            
            var firstHalfOfArray = splitArrayInHalfAndMerge(startingIdx, (startingIdx + endingIdx) / 2)
            var secondHalfOfArray = splitArrayInHalfAndMerge((startingIdx + endingIdx) / 2 + 1, endingIdx)
            
            return mergeSortTwoArrays(firstHalfOfArray, secondHalfOfArray)
        }
        
        func mergeSortTwoArrays(_ firstArray: [Int], _ secondArray: [Int]) -> [Int] {
            var firstArrayIdx = 0, secondArrayIdx = 0
            var resultingMergedArray = [Int]()
            
            while firstArrayIdx < firstArray.count || secondArrayIdx < secondArray.count {
                if secondArrayIdx >= secondArray.count || (firstArrayIdx < firstArray.count && firstArray[firstArrayIdx] < secondArray[secondArrayIdx]) {
                    resultingMergedArray.append(firstArray[firstArrayIdx])
                    firstArrayIdx += 1
                } else {
                    resultingMergedArray.append(secondArray[secondArrayIdx])
                    secondArrayIdx += 1
                }
            }
            return resultingMergedArray
        }
        
        return splitArrayInHalfAndMerge(0, nums.count - 1)
    }
}
