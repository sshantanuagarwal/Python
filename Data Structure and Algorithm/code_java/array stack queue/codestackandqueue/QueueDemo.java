
public class QueueDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//Queue theQue=new Queue(5);
		QueueLinkList theQue=new QueueLinkList();
		theQue.add("10");
		theQue.add("20");
		theQue.add("30");
		
		/*System.out.println(theQue.isEmpty());
		System.out.println(theQue.isFull());
		System.out.println(theQue.remove());
		System.out.println(theQue.remove());*/
		//System.out.println(theQue.remove());

		for(int i=0;i<3;i++){
			System.out.println(theQue.remove());
		}
		
	}

}
