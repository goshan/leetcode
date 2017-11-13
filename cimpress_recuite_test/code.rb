# you can write to stdout for debugging purposes, e.g.
# puts "this is a debug message"

def solution(s)
  # write your code in Ruby 2.2
  return nil unless s
  return 0 if s.empty?
  if s.length == 1
    return 0 if s == "("
    return 1 if s == ")"
  end

  point = s.length/2
  left = 0
  right = 0
  (0...point).each do |i|
    left += 1 if s[i] == "("
  end
  (point...s.length).each do |i|
    right += 1 if s[i] == ")"
  end

  while true
    if left == right
      return point
    elsif left < right
      # move one right
      if s[point] == "("
        left += 1
      else s[point] == ")"
        right -= 1
      end
      point += 1
    else  # left > right
      # move one left
      if s[point] == "("
        left -= 1
      else s[point] == ")"
        right += 1
      end
      point -= 1
    end
  end
end





ss = [
  #"(())))(",
  #nil,
  #"",
  #")",
  #"(",
  #"(())",
  #"))",
  "))(((((((()",
  "))((()())))()",
  "))()(((())(()",
  "(())(()))(())))(())((()((((()))))((())()()())))((()",
  "(()))((()))((()))))((((((())))))))((()))()()()(",
  "))((()())())))(()())()()())))))))(((())))))()())()))))()()()))))(((((()))))))(()()()))))))(("
]



ss.each do |s|
  puts solution(s).inspect
end


