import java.util.Stack;

public class QueueUsingStack {
	
	public Stack<Integer> st;
	
	public QueueUsingStack() {
		// TODO Auto-generated constructor stub
		st = new Stack<>();
	}
	
	public void enqueue(int data){
		if(st.isEmpty()){
			st.push(data);
		}else{
			int size=st.size();
			st.push(data);
			while(size>0){
				st.push(st.pop());
				size--;
			}
		}
	}
	
	public int dequeue(){
		return st.pop();
	}

	public static void main(String args[]){
		QueueUsingStack qt = new QueueUsingStack();
		qt.enqueue(1);
		qt.enqueue(2);
		qt.enqueue(3);
		
		System.out.println(qt.dequeue());
		System.out.println(qt.dequeue());
		System.out.println(qt.dequeue());
		
	}
}
