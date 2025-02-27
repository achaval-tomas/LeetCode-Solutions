class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        ans = []
        i = 0
        while i < len(words):

            line_length, sc = 0, 0
            current_line = []

            while i < len(words) and line_length + (sc + 1)*(line_length>0) + len(words[i]) <= maxWidth:
                # there is a new word that fits within maxWidth in this line, add it
                sc += (line_length > 0)
                line_length += len(words[i])
                current_line.append(words[i])
                i += 1

            # no more words fit in the current line, format it
            text = ""
            total_words = len(current_line)
            total_spaces = maxWidth - sum(len(w) for w in current_line)

            if i != len(words):
                
                space_after = [0 for _ in range(total_words)]
                space_slots = max(1, total_words - 1)

                # distribute spaces evenly with priority on the left
                w = 0
                while (total_spaces > 0):
                    space_after[w] += 1
                    total_spaces -= 1
                    w = (w+1) % space_slots

                # apply spaces between words to create the final string for the current line
                for w in range(total_words):
                    text += current_line[w] + " "*space_after[w]

            else:
                # left-align last line
                spaces_used = 0

                # apply one space between words
                for w in range(total_words):
                    text += current_line[w]
                    if w < total_words - 1:
                        text += " "
                        total_spaces -= 1

                # apply all remaining spaces at the end
                text = text + " "*total_spaces

            ans.append(text)

        return ans           