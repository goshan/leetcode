# =====================
# there is only one less digit before lager digit
# =====================

# @param {Integer} num
# @return {String}
def int_to_roman(num)
	roman_digits = ['M', 'D', 'C', 'L', 'X', 'V', 'I']
	roman_values = [1000, 500, 100, 50, 10, 5, 1]
	res = ''
	roman_digits.each_with_index do |d, i|
		if i%2 == 0  # 1000, 100, 10, 1
			dig = num/roman_values[i]
			num = num%roman_values[i]
			if dig >= 9
				res += "#{roman_digits[i]}#{roman_digits[i-2]}"
			elsif dig >=5
				res += "#{roman_digits[i-1]}#{roman_digits[i]*(dig-5)}"
			elsif dig >= 4
				res += "#{roman_digits[i]}#{roman_digits[i-1]}"
			else
				res += "#{roman_digits[i]*dig}"
			end
		end
	end
	res
end


puts int_to_roman 1954    # MCMLIV
puts int_to_roman 1990     # MCMXC
puts int_to_roman 2014     # MMXIV
puts int_to_roman 18     # XVIII
