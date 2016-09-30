# =====================
# every time %10 to get lowest digit, and plus to result after result * 10
# be careful for 0, minus number, 1000, and overflow 32-bit int
# =====================

# @param {Integer} x
# @return {Integer}
def reverse(x)
	max = 2147483648  # max integer for 32bit
	mark = x < 0 ? -1 : 1
	x *= mark
	y = 0
	while x != 0
		digit = x%10
		x /= 10
		return 0 if y > max/10 || (y == max/10 && digit > max%10)
		y = y*10+digit
	end
	y*mark
end

x = 1234
puts reverse(x)
