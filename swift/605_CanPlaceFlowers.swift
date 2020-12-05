class Solution {
    func canPlaceFlowers(_ flowerbed: [Int], _ n: Int) -> Bool {
        var changedFlowerbed = flowerbed
        var flowersLeftToPlace = n
        for (i, flower) in flowerbed.enumerated() {
            if flower == 0 && (i == 0 || changedFlowerbed[i-1] == 0) && (i == flowerbed.count - 1 || changedFlowerbed[i+1] == 0) {
                flowersLeftToPlace -= 1
                changedFlowerbed[i] = 1
            }
            if flowersLeftToPlace <= 0 {
                break
            }
        }
        return flowersLeftToPlace <= 0
    }
}
