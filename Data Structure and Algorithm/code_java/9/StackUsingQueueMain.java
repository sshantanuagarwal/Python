import java.util.Scanner;

public class StackUsingQueueMain {
	
			public static void main(String[] args) {
			
				StackUsingOneQueue st=new StackUsingOneQueue();
				st.push(1);
				st.push(2);
				st.push(3);
				System.out.println(st.pop());
				System.out.println(st.pop());
				System.out.println(st.pop());
				

			}
}
