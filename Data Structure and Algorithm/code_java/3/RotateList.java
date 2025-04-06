import java.util.Currency;

public class RotateList {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		LinkList list = new LinkList();
		list.insertAtStart(60);
		list.insertAtStart(50);
		list.insertAtStart(40);
		list.insertAtStart(30);
		list.insertAtStart(20);
		list.insertAtStart(10);
		System.out.println("Before rotate  ------- ");
		list.printList();
		rotate(4, list);
		System.out.println("After rotate  ------- ");
		list.printList();

	}
	
	 /**
	 * @param k
	 * @param list
	 */
	static void rotate(int k,LinkList list)
	    {
		Node current = list.head;
	       int count =1;
	       while(count <k &&current .next!=null){
	    	   current= current.next;
	    	   count++;
	       }
	       Node KthNode = current;
	       while(current.next!= null){
	    	   current= current.next;
	       }
	       current.next= list.head;
	      list.head = KthNode.next;
	      KthNode.next= null;
	    }

}
