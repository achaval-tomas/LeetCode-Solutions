/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function(num) {
  let romans = [
    ["M", 1000],
    ["CM", 900],
    ["D", 500],
    ["CD", 400],
    ["C", 100],
    ["XC", 90],
    ["L", 50],
    ["XL", 40],
    ["X", 10],
    ["IX", 9],
    ["V", 5],
    ["IV", 4],
    ["I", 1]
  ];
  let ans = "";
  let res = num;

  while (res != 0){
    for (let i = 0; i<romans.length; i++){
      if (res >= romans[i][1]){
        ans = ans.concat('',romans[i][0]);
        res -= romans[i][1];
        break;
      }
    }
  }
  return ans;
};