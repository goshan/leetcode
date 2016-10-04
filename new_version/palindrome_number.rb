# =====================
# use y to get poped digit from x
# carefull -, [0-9], and end with 0
# =====================

# @param {Integer} x
# @return {Boolean}
def is_palindrome(x)
	return false if x < 0
	return true if x < 10
	y = 0
	while x>y
		digit = x%10
		return false if digit == 0 && y == 0
		x /= 10
		return true if x == y
		y = y*10+digit
	end
	x == y
end


puts is_palindrome(-1234321)
puts is_palindrome(1234321)
puts is_palindrome(0)
puts is_palindrome(4)
puts is_palindrome(22)
puts is_palindrome(1234321)
puts is_palindrome(12344321)
puts is_palindrome(10)
puts is_palindrome(13100)
