import java.util.Stack;

public class StackGetMin {

	Stack st = new Stack<>();
	Stack stMin = new Stack<>();

	public void pop() {
		int data = (int) st.pop();
		if ((int) stMin.peek() == data) {
			stMin.pop();
		}

	}

	public int getMin() {
		return (int) stMin.peek();
	}

	public static void main(String[] args) {

		// TODO Auto-generated method stub
		StackGetMin stackMin = new StackGetMin();

		int[] arr = { 3, 4, 2, 8, 1 };

		int len = arr.length;
		for (int i = 0; i < len; i++) {
			if (stackMin.st.isEmpty()) {
				stackMin.st.push(arr[i]);
				stackMin.stMin.push(arr[i]);
			} else {
				stackMin.st.push(arr[i]);
				if ((int) stackMin.st.peek() < (int) stackMin.stMin.peek()) {
					stackMin.stMin.push(arr[i]);
				}
			}
		}
		
		//stackMin.pop();
		
		System.out.println(stackMin.getMin());
		

	}

}
