
public class CurcularLinkList {
	
	private Node tail;
	
	CurcularLinkList(){
		tail = null;
	}

	
	public static void main(String args[]){
		CurcularLinkList list = new CurcularLinkList();
		list.insertAtBegin(30);
		list.insertAtBegin(20);
		list.insertAtBegin(10);
		list.insertAtLast(40);
		//list.removeFromStart();
		list.printList();
	}

	private void removeFromStart() {
		// TODO Auto-generated method stub
		Node temp = tail.next;
		if(null == temp){
			tail = null;
		}
		else{
			tail.next=temp.next;
		}
	}

	private void printList() {
		// TODO Auto-generated method stub
		Node current = tail.next;
		while(current!=tail){
			System.out.println(current.data);
			current=current.next;
		}
		System.out.println(current.data);
		
	}

	private void insertAtLast(int data) {
			Node node = new Node(data);
			insertAtBegin(data);
			tail = tail.next;
		
	}

	private void insertAtBegin(int data) {
		// TODO Auto-generated method stub
		Node node = new Node(data);
		if (null == tail) {
			tail = node;
			tail.next = tail;
		} else {
			node.next = tail.next;
			tail.next = node;

		}

	}
}
