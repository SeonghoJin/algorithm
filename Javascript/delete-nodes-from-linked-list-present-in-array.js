/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */

/**
 * @param {number[]} nums
 * @param {ListNode} head
 * @return {ListNode}
 */
var modifiedList = function (nums, head) {
  const s = new Set(nums);

  let cur = head;
  let answer = new ListNode();
  let first = answer;

  while (cur !== null) {
    if (s.has(cur.val)) {
      cur = cur.next;
    } else {
      answer.next = new ListNode(cur.val);
      answer = answer.next;
      cur = cur.next;
    }
  }

  return first.next;
};
