import java.util.ArrayList;

public class StackUsingArrayList {
	
	private ArrayList list;
	private int top ;
	private int max;
	
	public StackUsingArrayList(int maxSize) {
		// TODO Auto-generated constructor stub
		list = new ArrayList();
		top = -1;
		max =maxSize;
	}
	
	public void push(Object data){
		list.add(data);
		top++;
	}
	
	public Object pop(){
		Object data = list.get(top);
		list.remove(top);
		top--;
		return data;
	}
	
	public boolean isEmpty(){
		return (top == -1);
	}
	
	public boolean isFull(){
		return ( top == (max-1));
	}

}
