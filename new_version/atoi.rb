# =====================
# start from the first non-whitespace worod
# +/- will be okay. stop at non-number word
# invalid word return 0
# 32-bit int is [-2147483648, 2147483647], return limit when overflow
# =====================

# @param {String} str
# @return {Integer}
def my_atoi(str)
	max = 2147483647
	min = 2147483648
	sign = nil
	res = 0
	is_start = false
	str.each_char do |c|
		next if c.ord == 32 && !is_start  # space
		if c.ord == 43  # +
			return 0 if sign
			sign = 1
			is_start = true
			next
		end
		if c.ord == 45  # -
			return 0 if sign
			sign = -1
			is_start = true
			next
		end
		return res*(sign ? sign : 1) if c.ord == 46   # c == '.'
		return res*(sign ? sign : 1) if c.ord == 32   # space
		return res*(sign ? sign : 1) unless c.ord >= 48 && c.ord <= 57
		is_start = true
		digit = c.ord-'0'.ord
		if res != 0
			if sign == -1
				return min*-1 if (res >= min/10 && digit > min%10) || Math.log10(res).to_i == Math.log10(min).to_i
			else
				return max if (res >= max/10 && digit > max%10) || Math.log10(res).to_i == Math.log10(max).to_i
			end
		end
		res = res*10+c.ord-'0'.ord
	end
	res*(sign ? sign : 1)
end

puts my_atoi('    +-010')
puts my_atoi('    +010')
puts my_atoi('    -010')
puts my_atoi('     010')
puts my_atoi('0023')
puts my_atoi('0-23')
puts my_atoi('-23')
puts my_atoi('+23')
puts my_atoi('002300')
puts my_atoi('002aav3')
puts my_atoi('002.300')
puts my_atoi('2.300')
puts my_atoi('.300')
puts my_atoi('2147483648')
puts my_atoi('-2147483648')
puts my_atoi('-2147483649')
puts my_atoi('    -11919730356x')
