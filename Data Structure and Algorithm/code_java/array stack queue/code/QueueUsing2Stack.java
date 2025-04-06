import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class QueueUsing2Stack {

	static Stack<Integer> st1 = new java.util.Stack<>();
	static Stack<Integer> st2 = new java.util.Stack<>();
	static Queue<Integer> qt = new LinkedList<>();

	public static void enqueue(int data) {
		if (st1.isEmpty()) {
			st1.push(data);
		} else {
			while (st1.isEmpty()) {
				st2.push(st1.pop());
			}
			st1.push(data);
			if (!st2.isEmpty())
				while (st2.empty()) {
					st1.push(st2.pop());
				}
		}
	}

	public static int dequeue() {
		return st1.pop();
	}
	public static int peek() {
		return st1.peek();
	}
	
	
	static void insert (int data){
		qt.add(data);
	}
	static void remove (){
		qt.remove();
	}
	static int peekData(){
		return qt.peek();
	}

	public static void main(String args[]) {
		
		Scanner sc = new Scanner(System.in);
		int limit = sc.nextInt();
		for ( int i=0;i<limit;i++){
			int data = sc.nextInt();
			if(1== data){
				int temp = sc.nextInt();
				insert(temp);
			}else if(2 == data){
				remove();
			}else if (3 == data){
				System.out.println(peekData());
			}
		}
		
	}
}
