
public class LengthEvenOdd {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		LinkList list = new LinkList();
		list.insertAtStart(50);
		list.insertAtStart(40);
		list.insertAtStart(30);
		list.insertAtStart(20);
		list.insertAtStart(10);
		
		Node current = list.head;
		
		while(current!=null && current.next!=null){
			current = current.next.next;
		}
		if(null == current){
			System.out.println("Even list");
		}else{
			System.out.println("Odd List ");
		}

	}

}
