
public class ReverseDoublyList {

	public static void main(String args[]){
		
		System.out.println(fact(5));
		
		DoublyLinkList list= new DoublyLinkList();
		list.insertAtBegining(50);
		list.insertAtBegining(40);
		list.insertAtBegining(30);
		list.insertAtBegining(20);
		list.insertAtBegining(10);
		
		reverseList(list);
		
		
		//list.printForward();
	}
	
	static void reverseList(DoublyLinkList list){
		
		
		DoublyNode current = list.head;
		DoublyNode prev = null;
		
		if(current.next == null){
			return;
		}
		
		while(current!=null){
			prev =current.prev;
			current.prev=current.next;
			current.next=prev;
			current=current.prev;
			
		}
		list.head=prev.prev;
	}
	
	public static int fact(int n){
		
		if( n == 0){
			return 1;
		}else{
			return n*fact(n-1);
		}
		
	}
}
