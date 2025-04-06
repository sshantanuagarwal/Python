
public class DoublyLinkListDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		DoublyLinkList list= new DoublyLinkList();
		list.insertAtBegining(10);
		list.insertAtBegining(20);
		list.insertAtBegining(30);
		list.insertAtBegining(40);
		list.insertAtBegining(50);
		//list.insertAtLast(70);
		list.deleteFromStart();
		list.deleteFromLast();
		
		list.printForward();
		//list.printBackword();
	}

}
