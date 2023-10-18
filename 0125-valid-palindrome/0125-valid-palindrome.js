/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    let string = s.replace(/[^a-z0-9]/gi, '');
    string = string.toLowerCase();
    let len = string.length;
    for (let i = 0; i<=len/2; i++){
        if (string[i] != string[len-i-1]){
            return false;
            }
    }
    return true;
};