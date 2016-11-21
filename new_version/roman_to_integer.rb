# =====================
# there is only one less digit before lager digit
# =====================

# @param {String} s
# @return {Integer}
def roman_to_int(s)
	roman_map = {:I => 1, :V => 5, :X => 10, :L => 50, :C => 100, :D => 500, :M => 1000, :bound => 10000}
	res = 0
	pre = 'bound'
	s.each_char do |c|
		#puts c
		if roman_map[c.to_sym] > roman_map[pre.to_sym]
			#puts "11111"
			res = res - roman_map[pre.to_sym] + roman_map[c.to_sym] - roman_map[pre.to_sym]
			#puts res
		else
			#puts "22222"
			res += roman_map[c.to_sym]
			#puts res
		end
		pre = c
	end
	res
end


puts roman_to_int "MCMLIV"    # 1954
puts roman_to_int "MCMXC"     # 1990
puts roman_to_int "MMXIV"     # 2014
puts roman_to_int "XVIII"     # 18
