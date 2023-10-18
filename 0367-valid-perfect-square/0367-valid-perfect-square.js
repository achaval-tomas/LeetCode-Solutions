/**
 * @param {number} num
 * @return {boolean}
 */
var isPerfectSquare = function(num) {
    if (num == 1){return true;}
    for (let i = 0; i<=num/2; i++){
        if (i*i == num){
            return true;
        }
    }
    return false;
};