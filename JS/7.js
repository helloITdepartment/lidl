/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    //Keep track of whether the input is negative
    let negative = x < 0;
    //Get the decimal digits
    let s = Math.abs(x).toString();
    //Reverse them and get the resulting number
    let res = parseInt(s.split('').reverse().join(''));
    //Crude check to see if the result is within range
    if (negative) {
        return res > Math.pow(2,31) ? 0 : -res;
    } else {
        return res >= Math.pow(2,31) ? 0 : res;
    }
};
