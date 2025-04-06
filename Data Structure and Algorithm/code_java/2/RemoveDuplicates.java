
public class RemoveDuplicates {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinkList list = new LinkList();
		list.insertAtStart(1);
		list.insertAtStart(1);
		list.insertAtStart(1);
		list.insertAtStart(1);
		list.insertAtStart(1);
		list.insertAtStart(1);
		list.insertAtStart(1);
		Node head= RemoveDuplicates(list.head);
		System.err.println(head.data);
	}


static Node  RemoveDuplicates(Node head) {
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    Node current = head;
    while(current.next!=null){
        if(current.data!=current.next.data){
        	current.next=current.next;
        }else{
        	current.next=current.next.next;
        }
    }
    return head;
}
}
