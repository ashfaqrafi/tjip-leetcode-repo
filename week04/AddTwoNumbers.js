var addTwoNumbers = function (l1, l2) {
  let values = [];
  let overflow = 0;
  while (l1.next || l2.next) {
    const value = (l1.val + l2.val + overflow) % 10;
    overflow = l1.val + l2.val + overflow >= 10 ? 1 : 0;
    values.push(value);

    l1 = l1.next || new ListNode(0);
    l2 = l2.next || new ListNode(0);
  }
  const value = (l1.val + l2.val + overflow) % 10;
  overflow = l1.val + l2.val + overflow >= 10 ? 1 : 0;
  values.push(value);
  if (overflow === 1) {
    values.push(1);
  }
  let node = undefined;
  values.reverse().forEach((item) => {
    if (node === undefined) {
      node = new ListNode(item);
    } else {
      const newNode = new ListNode(item);
      newNode.next = node;
      node = newNode;
    }
  });
  return node;
};
