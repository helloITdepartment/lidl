/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let best = 0;
    let leftIndex = 0;
    let rightIndex = height.length - 1;

    while (leftIndex != rightIndex) {
        let width = rightIndex - leftIndex;
        let h = Math.min(height[leftIndex], height[rightIndex]);
        let area = width*h;

        best = Math.max(best, area);
        // console.log(leftIndex, rightIndex, width, h, area, best);

        if (height[leftIndex] < height[rightIndex]) {
            leftIndex++;
        } else {
            rightIndex--;
        }
    }

    return best;
};
