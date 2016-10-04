# =====================
# jump n step from head and remember this node with tail
# jump head and tail together until tail reach nil(end of list)
# remove current head and return head of list will be okay
# =====================

# Definition for singly-linked list.
 class ListNode
	 attr_accessor :val, :next
	 def initialize(val)
		 @val = val
		 @next = nil
	 end
 end

# @param {ListNode} head
# @param {Integer} n
# @return {ListNode}
def remove_nth_from_end(head, n)
	tail = head
	prev = head
	while n > 0
		return nil if tail == nil
		tail = tail.next
		n -= 1
	end
	return head.next if tail == nil
	tail = tail.next
	while tail != nil
		tail = tail.next
		prev = prev.next
	end
	prev.next = prev.next.next
	head
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

l = [2]
puts remove_nth_from_end(arr2list(l), 2).inspect
