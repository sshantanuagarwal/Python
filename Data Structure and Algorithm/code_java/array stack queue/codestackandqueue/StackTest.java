
public class StackTest {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Stack st= new Stack();
		Student student = new Student();
		student.setName("test");
		student.setAddress("xyz");
		
		st.push(1);
		st.push(2);
		st.push(3);
		st.push("Test");
		st.push(1.25);
		st.push(student);
		
		while(!st.isEmpty()){
			System.out.println(st.pop());
		}
		

	}

}
