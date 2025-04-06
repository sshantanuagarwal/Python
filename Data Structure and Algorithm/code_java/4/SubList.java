public class SubList {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinkList list1 = new LinkList();
		list1.insertAtLast(1);
		list1.insertAtLast(3);
		list1.insertAtLast(4);

		LinkList list2 = new LinkList();
		list2.insertAtLast(1);
		list2.insertAtLast(2);
		list2.insertAtLast(3);
		list2.insertAtLast(4);
		list2.insertAtLast(5);
		list2.insertAtLast(6);

		System.out.println(isSubList(list2.head, list1.head));

	}

	/*
	 * public static boolean isSubList(Node head1, Node head2){ Node current1 =
	 * head1; Node current2= head2; boolean sublist = true; while(current1!=null
	 * && current2 != null){ if(current1.data == current2.data && sublist){
	 * current1=current1.next; sublist = true; }else{ sublist=false; }
	 * current2=current2.next;
	 * 
	 * } return (sublist && (current1 ==null )); }
	 */

	public static boolean isSubList(Node l1, Node l2) {
		Node current = l2;
		boolean isSubset = false;
		boolean isSubSetStarted = false;
		while (l1 != null && l1.next != null) {
			if (l1.data == current.data) {
				isSubSetStarted = true;
				isSubset = true;
				current = current.next;

			} else if (isSubSetStarted && current != null) {
				isSubset = false;
			} else if (isSubSetStarted && current == null) {
				return isSubset;
			}
			l1 = l1.next;
			if (current == null || l1.next == null) {
				return isSubset;
			}

		}
		if (current.next == null) {
			return true;
		}
		return false;
	}

}
