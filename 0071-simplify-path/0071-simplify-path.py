class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        dirs = [w for w in path.split('/') if w != '']

        valid_dirs = []
        for w in dirs:
            if w == '.':
                continue
            elif w == '..':
                if valid_dirs:
                    valid_dirs.pop(-1)
            else:
                valid_dirs.append(w)
        
        return "/" + "/".join(valid_dirs)
