# =====================
# try to find the logic of changing of index
# -----------
# down_col
#   ↓
#	0   4   8     12    16  ← line
#	1 3 5 7 9  11 13 15
#	2   6   10    14   
#	  ↑
#	up_col
# -----------
# interate every line, and in each line interate every down_col_index
# every down_col_index is previous down_col_index + interval in the same line
# interval = 2*row_num-2
# every up_col_index is next down_col_index - 2*line, means current_down_col_index+interval-2*line
# =====================

# @param {String} s
# @param {Integer} num_rows
# @return {String}
def convert(s, num_rows)
	return s if num_rows <= 1

	res = ""
	interval = 2*num_rows-2

	# first line
	(0..s.length-1).step(interval) do |down_col_index|
		res += s[down_col_index]
	end
	# normal line
	(1..num_rows-2).each do |line|
		(line..s.length-1).step(interval) do |down_col_index|
			# down column
			res += s[down_col_index]
			# up column
			up_col_index = down_col_index+interval-2*line
			res += s[up_col_index] if up_col_index < s.length
		end
	end
	# last line
	(num_rows-1..s.length-1).step(interval) do |down_col_index|
		res += s[down_col_index]
	end
	res
end

s = "PAYPALISHIRING"
num_rows = 3
puts convert(s, num_rows)
