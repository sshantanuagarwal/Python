import java.util.ArrayList;

public class Stack {
	
	private ArrayList list ;
	private int top;
	
	
	public Stack() {
		// TODO Auto-generated constructor stub
		list= new ArrayList();
		top=-1;
		
	}
	
	public void push(Object data){
		top++;
		list.add(data);
		
	}
	public Object pop(){
		Object data= list.get(top);
		list.remove(top);
		top--;
		return data;
	}
	
	public boolean isEmpty(){
		return (top == -1);
		
	}
	

}
