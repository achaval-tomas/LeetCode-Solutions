class Solution(object):
    def trap(self, height):
        n = len(height)

        l, r = 0, n-1
        l_height, r_height = height[l], height[r]

        water = 0
        while (l < r):
            l_height = max(l_height, height[l])
            r_height = max(r_height, height[r])

            fill_height = min(l_height, r_height)

            while (l < r and height[l] <= fill_height):
                water += fill_height - height[l]
                l += 1

            while (r > l and height[r] <= fill_height):
                water += fill_height - height[r]
                r -= 1


        return water