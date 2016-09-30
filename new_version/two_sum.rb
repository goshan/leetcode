# =====================
# use Hash to save {:sub => index}
# ====================

# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
	need = {}
	nums.each_with_index do |n, i|
		return [need[n], i] if need[n] != nil
		need[target-n] = i
	end
	[]
end

nums = [3, 2, 4]
target = 6
puts two_sum(nums, target).inspect
