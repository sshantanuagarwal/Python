
public class Stack {
	
	int size;
	int top;
	int[] arr;
	
	 Stack(int number){
		 this.size= number;
		 arr = new int[number];
		 top=-1;
	 }
	 
	 public void push(int n){
		 if(isFull()){
			 System.out.println(" STACK is already full");
		 }else{
		 arr[++top]= n;
		 }
	 }
	 public int pop(){
		 if(isEmpty()){
			 System.out.println("Stack is empty");
			 return -1;
		 }
		 return arr[top--];
	 }
	 
	 public boolean isEmpty(){
		 return (top == -1); 
	 }
	 public boolean isFull(){
		 return (top == (size -1));
	 }
}
