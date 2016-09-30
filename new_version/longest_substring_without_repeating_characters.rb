# =====================
# 2 pointers for string which is currently being checked, 
# a string cache the logest substring in history. 
# a hash cache all characters whether existed in substring which is being checked 
#
# when new char in end pointer has existed in hash, 
# make start pointer to position of duplicated char. 
# and remove elements of hash between old start and new start
# =====================

# @param {String} s
# @return {Integer}
def length_of_longest_substring(s)
	return 0 if s.empty?
	start = 0
	longest = s[start]
	index = 1
	exist = {}
	exist[s[start]] = start
	while index < s.length
		if exist[s[index]] != nil
			temp = exist[s[index]]
			(start..temp).each do |i|
				exist.delete s[i]
			end
			start = temp+1
		else
			longest = s[start..index] if longest.length < index-start+1
		end
		exist[s[index]] = index
		index += 1
	end
	longest.length
end

s = "tmmzuxt"
puts length_of_longest_substring(s)
