
public class FindDuplicate {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int[] arr={1,2,2,3,4,5};
		int length=arr.length;
		int sum=length*(length-1)/2;
		int count=0;
		for(int i=0;i<arr.length;i++){
			count=count+arr[i];
			
		}
		System.out.println(count-sum);
	}

}
