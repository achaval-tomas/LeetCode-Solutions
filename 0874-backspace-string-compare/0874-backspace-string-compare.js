/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var backspaceCompare = function(s, t) {
    let i = 0;
    while (i < s.length){
        if (s[i] == '#'){
            if (i > 0){
                s = s.slice(0,i-1).concat(s.slice(i+1, s.length));
                i = -1;
            } else {
                s = s.slice(1, s.length);
                i = -1;
            }        
        }
        i++;
    }
    i = 0;
    while (i < t.length){
        if (t[i] == '#'){
            if (i > 0){
                t = t.slice(0,i-1).concat(t.slice(i+1, t.length));
                i = -1;
            } else {
                t = t.slice(1, t.length);
                i = -1;
            }  
        }
        i++;
    }
    if (s.length != t.length){
        return false;
    }
    for (let i = 0; i<s.length; i++){
        if (s[i] != t[i]){
            return false;
        }
    }
    return true;
};