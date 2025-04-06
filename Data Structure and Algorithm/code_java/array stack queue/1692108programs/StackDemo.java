
public class StackDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Stack st = new Stack(3);
		st.push(1);
		st.push(2);
		st.push(3);
		while (!st.isEmpty()){
			System.out.println(st.pop());
		}
		st.pop();
	//	st.push(4);
	}

}
