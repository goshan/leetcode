# =====================
# simplely scan two lists. Problem is the process at the end of list
# =====================

# Definition for singly-linked list.
class ListNode
	attr_accessor :val, :next
	def initialize(val)
		@val = val
		@next = nil
	end
end

# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}
def add_two_numbers(l1, l2)
	temp = l1
	is_forward = false
	while temp
		temp.val += l2 ? l2.val : 0
		temp.val += 1 if is_forward
		if temp.val >= 10
			is_forward = true
			temp.val -= 10
		else
			is_forward = false
		end

		l2 = l2.next if l2
		if !temp.next
			temp.next = l2
			l2 = nil
		end
		if !temp.next && is_forward
			temp.next = ListNode.new 1
			is_forward = false
		end
		temp = temp.next
	end
	l1
end

def arr2list(arr)
	temp = nil
	arr.reverse.each do |e|
		current = ListNode.new e
		current.next = temp
		temp = current
	end
	temp
end

l1 = [2, 4, 3]
l2 = [7, 0, 8]
puts add_two_numbers(arr2list(l1), arr2list(l2)).inspect
