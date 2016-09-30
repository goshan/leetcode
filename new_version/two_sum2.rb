# =====================
# because of sorted array 
# scan from start and end at the same time, and plus start and end
# larger than target, move end to front to minus result
# less than target, move start to ent to plus result
# ====================

# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
	s = 0
	e = nums.count-1
	while s < e
		temp = nums[s] + nums[e]
		if temp < target
			s += 1
		elsif temp > target
			e -= 1
		else
			return [s+1, e+1]
		end
	end
	[]
end

nums = [-5, -3, 2, 3, 4, 7]
target = 6
puts two_sum(nums, target).inspect
